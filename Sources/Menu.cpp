//
// Created by vasyl on 2/21/2024.
//
#include "Menu.h"

const char* MAIN_MENU_OPTIONS_TEXT = "0 – Exit\n"
                                     "1 - Insert publisher\n"
                                     "2 - Get publisher\n"
                                     "3 - Delete publisher\n"
                                     "4 - Edit publisher\n"
                                     "5 - Insert book\n"
                                     "6 - Get book\n"
                                     "7 - Delete book\n"
                                     "8 - Edit book\n"
                                     "9 - Count publishers\n"
                                     "10 - Count books\n"
                                     "11 - Count books for publisher\n"
                                     "12 - Get all publishers\n"
                                     "13 - Get all books\n";

const char* MAIN_MENU_WRONG_INPUT = "Enter value between 0 and 4\n";

const char* PUBLISHER_ID_REQUEST_TEXT = "Enter publisherID (only positive integers).\n";
const char* PUBLISHER_NAME_REQUEST_TEXT = "Enter publisher name.\n";
const char* PUBLISHER_LOCATION_REQUEST_TEXT = "Enter publisher location.\n";

const char* PUBLISHER_INSERTED_TEXT = "Publisher has been successfully inserted.\n";
const char* PUBLISHER_REMOVED_TEXT = "Publisher has been successfully removed.\n";

const char* PUBLISHER_SELECT_FIELD_TO_UPDATE = "0 - Stop updating\n1 - Name\n2 - Location\n";
const char* PUBLISHER_UPDATED_TEXT = "Publisher has been successfully updated.\n";

const char* PUBLISHER_INVALID_ID_TEXT = "No publisher with such ID.\n";
const char* PUBLISHER_ID_IS_TAKEN_TEXT = "This ID is already taken.\n";
const char* PUBLISHER_NOT_REMOVED_TEXT = "Error while removing the publisher.\n";
const char* PUBLISHER_NOT_UPDATED_TEXT = "Error while updating the publisher.\n";

const char* BOOK_ID_REQUEST_TEXT = "Enter book ID.\n";
const char* BOOK_PUBLISHER_ID_REQUEST_TEXT = "Enter book's publisher ID.\n";
const char* BOOK_ISBN_REQUEST_TEXT = "Enter book ISBN (must be 13 characters long).\n";
const char* BOOK_TITLE_REQUEST_TEXT = "Enter book title.\n";
const char* BOOK_AUTHOR_REQUEST_TEXT = "Enter book author.\n";
const char* BOOK_GENRE_REQUEST_TEXT = "Enter book genre.\n";

const char* BOOK_INVALID_ID_TEXT = "No book with such ID\n";
const char* BOOK_INVALID_ISBN_TEXT = "Invalid ISBN.\n";
const char* BOOK_ID_IS_TAKEN_TEXT = "This ID is already taken.\n";
const char* BOOK_NOT_REMOVED_TEXT = "Error while removing the book.\n";
const char* BOOK_NOT_UPDATED_TEXT = "Error while updating the book\n";

const char* BOOK_INSERTED_TEXT = "Book has been successfully inserted.\n";
const char* BOOK_REMOVED_TEXT = "Book has been successfully removed.\n";

const char* BOOK_SELECT_FIELDS_TO_UPDATE_TEXT = "0 - Stop updating\n1 - Title\n2 - Author\n3 - Genre\n";
const char* BOOK_UPDATED_TEXT = "Book has been successfully updated.\n";

const char* PUBLISHER_COUNT_RESULT_TEXT = "Publishers count: ";
const char* BOOK_COUNT_RESULT_TEXT = "Books count: ";
const char* PUBLISHERS_BOOKS_COUNT_RESULT_TEXT = "Publisher's books count: ";

int readInt(const char* text)
{
    int value;
    std::cout << text;
    std::cin >> value;
    return value;
}

char* readString(const char* text)
{
    char* string = new char[STRING_SIZE];
    std::cout << text;
    std::cin >> string;
    return string;
}

void addPublisherMenu()
{
    int id;
    while (true)
    {
        id = readInt(PUBLISHER_ID_REQUEST_TEXT);

        if (!checkPublisherId(id))
        {
            std::cout << PUBLISHER_ID_IS_TAKEN_TEXT;
            continue;
        }

        break;
    }

    char* name = readString(PUBLISHER_NAME_REQUEST_TEXT);
    char* location = readString(PUBLISHER_LOCATION_REQUEST_TEXT);

    Publisher publisher(id, name, location, -1);
    insertPublisher(publisher);

    std::cout << PUBLISHER_INSERTED_TEXT;
}

void getPublisherMenu()
{
    int id = readInt(PUBLISHER_ID_REQUEST_TEXT);

    Publisher publisher = getPublisher(id);
    if (publisher.getId() == -1) {
        std::cout << PUBLISHER_INVALID_ID_TEXT;
        return;
    }

    std::cout << publisher.toString();
}

void removePublisherMenu()
{
    int id = readInt(PUBLISHER_ID_REQUEST_TEXT);
    bool success = removePublisher(id);
    if (!success)
    {
        std::cout << PUBLISHER_NOT_REMOVED_TEXT;
        return;
    }
    std::cout << PUBLISHER_REMOVED_TEXT;
}

void updatePublisherName(Publisher& publisher)
{
    char* name = readString(PUBLISHER_NAME_REQUEST_TEXT);
    publisher.setName(name);
}

void updatePublisherLocation(Publisher& publisher)
{
    char* location = readString(PUBLISHER_LOCATION_REQUEST_TEXT);
    publisher.setLocation(location);
}

void updatePublisherFields(Publisher& publisher)
{
    int option;
    do
    {
        option = readInt(PUBLISHER_SELECT_FIELD_TO_UPDATE);
        switch (option)
        {
            case 0:
                break;
            case 1:
                updatePublisherName(publisher);
                break;
            case 2:
                updatePublisherLocation(publisher);
                break;
            default:
                break;
        }
    } while (option != 0);
}

void updatePublisherMenu()
{
    int id = readInt(PUBLISHER_ID_REQUEST_TEXT);
    Publisher publisher = getPublisher(id);

    if (publisher.getId() == -1) {
        std::cout << PUBLISHER_INVALID_ID_TEXT;
        return;
    }

    updatePublisherFields(publisher);

    bool success = updatePublisher(id, publisher);
    if (!success)
    {
        std::cout << PUBLISHER_NOT_UPDATED_TEXT;
        return;
    }

    std::cout << PUBLISHER_UPDATED_TEXT;
}

void addBookMenu()
{
    int id;
    while (true)
    {
        id = readInt(BOOK_ID_REQUEST_TEXT);
        if (!checkBookId(id))
        {
            std::cout << BOOK_ID_IS_TAKEN_TEXT;
            continue;
        }
        break;
    }

    int publisherId = readInt(BOOK_PUBLISHER_ID_REQUEST_TEXT);
    Publisher publisher = getPublisher(publisherId);
    if (publisher.getId() == -1) {
        std::cout << PUBLISHER_INVALID_ID_TEXT;
        return;
    }

    long long isbn;
    while (true) {
        std::cout << BOOK_ISBN_REQUEST_TEXT;
        std::cin >> isbn;

        if (std::to_string(isbn).length() != 13) {
            std::cout << BOOK_INVALID_ISBN_TEXT;
            continue;
        }
        break;
    }

    char* title = readString(BOOK_TITLE_REQUEST_TEXT);
    char* author = readString(BOOK_AUTHOR_REQUEST_TEXT);
    char* genre = readString(BOOK_GENRE_REQUEST_TEXT);

    Book book(id, publisherId, isbn, title, author, genre, -1, -1);
    insertBook(book);

    std::cout << BOOK_INSERTED_TEXT;
}

void getBookMenu()
{
    int id = readInt(BOOK_ID_REQUEST_TEXT);

    Book book = getBook(id);
    if (book.getId() == -1)
    {
        std::cout << BOOK_INVALID_ID_TEXT;
        return;
    }

    std::cout << book.toString();
}

void removeBookMenu()
{
    int id = readInt(BOOK_ID_REQUEST_TEXT);
    bool success = removeBook(id);
    if (!success)
    {
        std::cout << BOOK_NOT_REMOVED_TEXT;
        return;
    }
    std::cout  << BOOK_REMOVED_TEXT;
}

void updateBookTitle(Book& book)
{
    char* title = readString(BOOK_TITLE_REQUEST_TEXT);
    book.setTitle(title);
}

void updateBookAuthor(Book& book)
{
    char* author = readString(BOOK_AUTHOR_REQUEST_TEXT);
    book.setAuthor(author);
}

void updateBookGenre(Book& book) {
    char* genre = readString(BOOK_GENRE_REQUEST_TEXT);
    book.setGenre(genre);
}

void updateBookFields(Book& book)
{
    int options;
    do
    {
        options = readInt(BOOK_SELECT_FIELDS_TO_UPDATE_TEXT);
        switch (options)
        {
            case 1:
                updateBookTitle(book);
                break;
            case 2:
                updateBookAuthor(book);
                break;
            case 3:
                updateBookGenre(book);
                break;
            default:
                break;
        }
    } while (options != 0);
}

void updateBookMenu()
{
    int id = readInt(BOOK_ID_REQUEST_TEXT);

    Book book = getBook(id);
    if (book.getId() == -1)
    {
        std::cout << BOOK_INVALID_ID_TEXT;
        return;
    }

    updateBookFields(book);
    updateBook(id, book);
}

void countBooksOfPublisherMenu() {
    int id = readInt(PUBLISHER_ID_REQUEST_TEXT);

    Publisher publisher = getPublisher(id);
    if (publisher.getId() == -1) {
        std::cout << PUBLISHER_INVALID_ID_TEXT;
        return;
    }

    std::cout << "Total books of this publisher: " << countBooksOfPublisher(id);
}

/*void countAllMoviesForDirectorMenu()
{
    int directorId = readInt(DIRECTOR_ID_REQUEST_TEXT), error = 0;
    long count = countMoviesForDirector(directorId, error);
    if (error)
    {
        printError(error);
        return;
    }
    cout << DIRECTORS_MOVIES_COUNT_RESULT_TEXT << count << endl;
}*/

void start()
{
    int option;
    do
    {
        std::cout << "\n\n";
        option = readInt(MAIN_MENU_OPTIONS_TEXT);
        switch (option)
        {
            case 0:
                break;
            case 1:
                addPublisherMenu();
                break;
            case 2:
                getPublisherMenu();
                break;
            case 3:
                removePublisherMenu();
                break;
            case 4:
                updatePublisherMenu();
                break;
            case 5:
                addBookMenu();
                break;
            case 6:
                getBookMenu();
                break;
            case 7:
                removeBookMenu();
                break;
            case 8:
                updateBookMenu();
                break;
            case 9:
                countPublishers();
                break;
            case 10:
                countBooks();
                break;
            case 11:
                countBooksOfPublisherMenu();
                break;
            case 12:
                getAllPublishers();
                break;
            case 13:
                getAllBooks();
                break;
            default:
                std::cout << MAIN_MENU_WRONG_INPUT;
                break;
        }
    } while (option != 0);
}