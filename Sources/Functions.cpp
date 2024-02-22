//
// Created by vasyl on 2/19/2024.
//

#include "Functions.h"

FILE* publishersF;
FILE* booksF;

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
        //std::cerr << "No publisher with such ID\n";
        return Publisher();
    }
    return readPublisher(publishersF, address);
}

void getAllPublishers() {
    if (publishersIndex->id == -1) {
        std::cout << "No publishers.\n";
        return;
    }

    ListNode* temp = publishersIndex;
    while (temp) {
        int id = temp->id;
        Publisher publisher = getPublisher(id);
        std::cout << publisher.toString() << '\n';
        temp = temp->next;
    }
}

void countPublishers() {
    std::cout << "Total publishers: " << getSize(publishersIndex) << '\n';
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

void getAllBooks() {
    if (booksIndex->id == -1) {
        std::cout << "No books.\n";
        return;
    }

    ListNode* temp = booksIndex;
    while (temp) {
        int id = temp->id;
        Book book = getBook(id);
        std::cout << book.toString() << '\n';
        temp = temp->next;
    }
}

void countBooks() {
    std::cout << "Total books: " << getSize(booksIndex) << '\n';
}

int countBooksOfPublisher(int id) {
    Publisher publisher = getPublisher(id);
    long address = publisher.getFirstBookAddress();

    int count = 0;
    while (address != -1) {
        Book book = readBook(booksF, address);
        ++count;
        address = book.getNextBookAddress();
    }
    return count;
}

bool removePublisher(int id) {
    Publisher publisher = getPublisher(id);
    if (publisher.getId() == -1) {
        return false;
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
        writeBook(booksF, book, bookAddress);
        booksGarbage->push(bookAddress);
        deleteListNode(book.getId(), &booksIndex);
        bookAddress = book.getNextBookAddress();
    }
    return true;
}

bool removeBook(int id) {
    Book book = getBook(id);
    if (book.getId() == -1) {
        return false;
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
    if (address == -1) {
        return false;
    }

    writeBook(booksF, book, address);
    booksGarbage->push(address);
    deleteListNode(id, &booksIndex);
    return true;
}

bool insertPublisher(const Publisher& newPublisher) {
    long address = publishersGarbage->pop();
    if (address == -1) {
        fseek(publishersF, 0, SEEK_END);
        address = ftell(publishersF);
    }
    int id = newPublisher.getId();
    addListNode(id, address, &publishersIndex);
    sortList(&publishersIndex);

    writePublisher(publishersF, newPublisher, address);
    return true;
}

bool insertBook(Book& newBook) {
    int publisherId = newBook.getPublisherId();

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

    addListNode(newBook.getId(), address, &booksIndex);
    sortList(&booksIndex);

    writeBook(booksF, newBook, address);
    return true;
}

bool updatePublisher(int id, const Publisher& newPublisher) {
    long address = getPublisherAddress(id);
    if (address == -1) {
        //std::cerr << "No publisher with such ID\n";
        return false;
    }
    writePublisher(publishersF, newPublisher, address);
    return true;
}

bool updateBook(int id, const Book& newBook) {
    long address = getBookAddress(id);
    if (address == 1) {
        std::cerr << "No book with such ID\n";
        return false;
    }
    writeBook(booksF, newBook, address);
    return true;
}

bool checkPublisherId(int id) {
    return isIdFree(id, publishersIndex);
}

bool checkBookId(int id) {
    return isIdFree(id, booksIndex);
}

void loadIndex(char* filePath, ListNode** head) {
    FILE* file = fopen(filePath, "rb+");
    if (!file) {
        file = fopen(filePath, "wb+");
    }

    if (!isFileEmpty(file)) {
        int id;
        long address;

        do {
            fread(&id, INT_SIZE, 1, file);
            fread(&address, LONG_SIZE, 1, file);
            addListNode(id, address, head);
        } while (!feof(file));
    }
    sortList(head);
    fclose(file);
}

void writeIndex(char* filePath, ListNode* head) {
    FILE* file = fopen(filePath, "wb+");

    ListNode* temp = head;
    if (temp->id == -1) {
        return;
    }

    while(temp) {
        fwrite(&temp->id, INT_SIZE, 1, file);
        fwrite(&temp->address, LONG_SIZE, 1, file);
        temp = temp->next;
    }
    fclose(file);
}

void loadGarbage(char* filePath, Queue** garbage) {
    FILE* file = fopen(filePath, "rb+");
    if (!file) {
        file = fopen(filePath, "wb+");
    }

    if (!isFileEmpty(file)) {
        long address;
        do {
            fread(&address, LONG_SIZE, 1, file);
            (*garbage)->push(address);
        } while (!feof(file));
    }
    fclose(file);
}

void writeGarbage(char* filePath, Queue* garbage) {
    FILE* file = fopen(filePath, "wb+");

    while(!garbage->isEmpty()) {
        long address = garbage->pop();
        fwrite(&address, LONG_SIZE, 1, file);
    }
    fclose(file);
}

void prepareFiles(char* publishersPath, char* booksPath, char* publishersIndexPath, char* booksIndexPath, char* publishersGarbagePath, char* booksGarbagePath) {
    publishersF = fopen(publishersPath, "rb+");
    if (!publishersF) {
        publishersF = fopen(publishersPath, "wb+");
    }

    booksF = fopen(booksPath, "rb+");
    if (!booksF) {
        booksF = fopen(booksPath, "wb+");
    }

    // loading indexes
    loadIndex(publishersIndexPath, &publishersIndex);
    loadIndex(booksIndexPath, &booksIndex);

    // loading garbage
    loadGarbage(publishersGarbagePath, &publishersGarbage);
    loadGarbage(booksGarbagePath, &booksGarbage);
}

void close(char* publishersIndexPath, char* booksIndexPath, char* publishersGarbagePath, char* booksGarbagePath) {
    fclose(publishersF);
    writeIndex(publishersIndexPath, publishersIndex);
    writeGarbage(publishersGarbagePath, publishersGarbage);

    fclose(booksF);
    writeIndex(booksIndexPath, booksIndex);
    writeGarbage(booksGarbagePath, booksGarbage);
}