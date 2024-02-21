//
// Created by vasyl on 2/19/2024.
//

#include "Functions.h"

FILE* publishersF = fopen("publishers.bin", "wb+");
FILE* booksF = fopen("books.bin", "wb+");

ListNode* publishersIndex = new ListNode;
Queue* publishersGarbage = new Queue;

ListNode* booksIndex = new ListNode;
Queue* booksGarbage = new Queue;

long getPublisherAddress(int id) {
    return getAddress(id, publishersIndex);
}

Publisher getPublisher(int id) {
    long address = getPublisherAddress(id);
    if (address == -1) {
        std::cerr << "No publisher with such ID\n";
        return Publisher();
    }
    return readPublisher(publishersF, address);
}

long getBookAddress(int id) {
    return getAddress(id, booksIndex);
}

Book getBook(int id) {
    long address = getBookAddress(id);
    if (address == -1) {
        std::cerr << "No book with such ID.\n";
        return Book();
    }
    return readBook(booksF, address);
}

void deletePublisher(int id) {
    Publisher publisher = getPublisher(id);
    if (publisher.getId() == -1) {
        return;
    }
    publisher.setState(STATE_REMOVED);

    long address = getPublisherAddress(id);
    writePublisher(publishersF, publisher, address);

    publishersGarbage->push(address);
    deleteListNode(id, &publishersIndex);

    // deleting all sub records
    long bookAddress = publisher.getFirstBookAddress();

    while (bookAddress != -1) {
        Book book = readBook(booksF, bookAddress);
        book.setState(STATE_REMOVED);
        // I guess I don't need to update book rn? better to do it when closing the file;
        booksGarbage->push(bookAddress);
        deleteListNode(book.getId(), &booksIndex);
        bookAddress = book.getNextBookAddress();
    }
}

void deleteBook(int id) {
    Book book = getBook(id);
    if (book.getId() == -1) {
        return;
    }
    book.setState(STATE_REMOVED);

    long prevBookAddress = book.getPrevBookAddress();
    long nextBookAddress = book.getNextBookAddress();

    if (prevBookAddress != -1) {
        // changing relations between books
        Book prevBook = readBook(booksF, prevBookAddress);
        prevBook.setNextBookAddress(nextBookAddress);
        writeBook(booksF, prevBook, prevBookAddress);

        if (nextBookAddress != -1) {
            Book nextBook = readBook(booksF, nextBookAddress);
            nextBook.setPrevBookAddress(prevBookAddress);
            writeBook(booksF, nextBook, nextBookAddress);
        }
    }
    else {
        // setting publisher first book to the next one
        int publisherId = book.getPublisherId();
        Publisher publisher = getPublisher(publisherId);
        publisher.setFirstBookAddress(nextBookAddress);
        updatePublisher(publisherId, publisher);
    }

    long address = getBookAddress(id);
    if (address != -1) {
        writeBook(booksF, book, address);
        booksGarbage->push(address);
        deleteListNode(id, &booksIndex);
    }

}

void insertPublisher(const Publisher& newPublisher) {
    long address = publishersGarbage->pop();
    if (address == -1) {
        fseek(publishersF, 0, SEEK_END);
        address = ftell(publishersF);
    }
    int id = newPublisher.getId();
    addListNode(id, address, &publishersIndex);

    writePublisher(publishersF, newPublisher, address);
}

void insertBook(Book& newBook) {
    int publisherId = newBook.getPublisherId();
    // TODO: transfer this check to the creation of book?
    if (isIdFree(publisherId, publishersIndex)) {
        std::cerr << "No publisher with such ID.\n";
        return;
    }

    long address = booksGarbage->pop();
    if (address == -1) {
        fseek(booksF, 0, SEEK_END);
        address = ftell(booksF);
    }

    Publisher publisher = getPublisher(publisherId);
    long bookAddress = publisher.getFirstBookAddress();

    if (bookAddress == -1) {
        publisher.setFirstBookAddress(address);

        long publisherAddress = getPublisherAddress(publisherId);
        writePublisher(publishersF, publisher, publisherAddress);
    }
    else {
        Book book = readBook(booksF, bookAddress);
        while (book.getNextBookAddress() != -1) {
            bookAddress = book.getNextBookAddress();
            book = readBook(booksF, bookAddress);
        }
        book.setNextBookAddress(address);
        newBook.setPrevBookAddress(bookAddress);

        writeBook(booksF, book, bookAddress);
    }
    writeBook(booksF, newBook, address);
}

void updatePublisher(int id, const Publisher& newPublisher) {
    long address = getPublisherAddress(id);
    if (address == -1) {
        std::cerr << "No publisher with such ID\n";
        return;
    }
    writePublisher(publishersF, newPublisher);

}

void updateBook(int id, const Book& newBook) {
    long address = getBookAddress(id);
    if (address == 1) {
        std::cerr << "No book with such ID\n";
        return;
    }
    writeBook(booksF, newBook);
}