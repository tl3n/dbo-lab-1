//
// Created by vasyl on 2/18/2024.
//
#include "Utilities.h"

void writeBook(FILE* file, const Book& book) {
    // file should be opened previously
    // this is why there is no check if file exists
    // it should be done on the other side

    int id = book.getId();
    int publisherId = book.getPublisherId();
    long long isbn = book.getIsbn();
    char* title = book.getTitle();
    char* author = book.getAuthor();
    char* genre = book.getGenre();
    long prevBookAddress = book.getPrevBookAddress();
    long nextBookAddress = book.getNextBookAddress();
    bool state = book.getState();

    fwrite(&id, INT_SIZE, 1, file);
    fwrite(&publisherId, INT_SIZE, 1, file);
    fwrite(&isbn, LL_SIZE, 1, file);
    fwrite(title, CHAR_SIZE, STRING_SIZE, file);
    fwrite(author, CHAR_SIZE, STRING_SIZE, file);
    fwrite(genre, CHAR_SIZE, STRING_SIZE, file);
    fwrite(&prevBookAddress, LONG_SIZE, 1, file);
    fwrite(&nextBookAddress, LONG_SIZE, 1, file);
    fwrite(&state, BOOL_SIZE, 1, file);
}

void writeBook(FILE* file, const Book& book, long address) {
    fseek(file, address, SEEK_SET);
    writeBook(file, book);
}

Book readBook(FILE* file) {
    int id;
    int publisherId;
    long long isbn;
    char* title = new char[STRING_SIZE];
    char* author = new char[STRING_SIZE];
    char* genre = new char[STRING_SIZE];
    long prevBookAddress;
    long nextBookAddress;
    bool state;


    fread(&id, INT_SIZE, 1, file);
    fread(&publisherId, INT_SIZE, 1, file);
    fread(&isbn, LL_SIZE, 1, file);
    fread(title, CHAR_SIZE, STRING_SIZE, file);
    fread(author, CHAR_SIZE, STRING_SIZE, file);
    fread(genre, CHAR_SIZE, STRING_SIZE, file);
    fread(&prevBookAddress, LONG_SIZE, 1, file);
    fread(&nextBookAddress, LONG_SIZE, 1, file);
    fread(&state, BOOL_SIZE, 1, file);

    return {id, publisherId, isbn, title, author, genre, prevBookAddress, nextBookAddress};
}

Book readBook(FILE* file, long address) {
    fseek(file, address, SEEK_SET);
    return readBook(file);
}

void writePublisher(FILE* file, const Publisher& publisher) {
    int id = publisher.getId();
    char* name = publisher.getName();
    char* location = publisher.getLocation();
    long firstBookAddress = publisher.getFirstBookAddress();
    bool state = publisher.getState();

    fwrite(&id, INT_SIZE, 1, file);
    fwrite(name, CHAR_SIZE, STRING_SIZE, file);
    fwrite(location, CHAR_SIZE, STRING_SIZE, file);
    fwrite(&firstBookAddress, LONG_SIZE, 1, file);
    fwrite(&state, BOOL_SIZE, 1, file);

}

void writePublisher(FILE* file, Publisher publisher, long address) {
    fseek(file, address, SEEK_SET);
    writePublisher(file, publisher);
}

Publisher readPublisher(FILE* file) {
    int id;
    char* name = new char[STRING_SIZE];
    char* location = new char[STRING_SIZE];
    long firstBookAddress;
    bool state;

    fread(&id, INT_SIZE, 1, file);
    fread(name, CHAR_SIZE, STRING_SIZE, file);
    fread(location, CHAR_SIZE, STRING_SIZE, file);
    fread(&firstBookAddress, LONG_SIZE, 1, file);
    fread(&state, BOOL_SIZE, 1, file);

    return {id, name, location, firstBookAddress};
}

Publisher readPublisher(FILE* file, long address) {
    fseek(file, address, SEEK_SET);
    return readPublisher(file);
}

bool isFileEmpty(FILE* file) {
    fseek(file, 0, SEEK_END);
    long address = ftell(file);
    fseek(file, 0, SEEK_SET);
    return address == 0;
}