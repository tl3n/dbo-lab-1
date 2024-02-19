//
// Created by vasyl on 2/18/2024.
//
#include "Utilities.h"

void writeBook(FILE* file, const Book& book, long address) {
    // file should be opened previously
    // this is why there is no check if file exists
    // it should be done on the other side
    fseek(file, address, SEEK_SET);

    int id = book.getId();
    int publisherId = book.getPublisherId();
    long long isbn = book.getIsbn();
    char* title = book.getTitle();
    char* author = book.getAuthor();
    char* genre = book.getGenre();
    long prevBookAddress = book.getPrevBookAddress();
    long nextBookAddress = book.getNextBookAddress();

    fwrite(&id, INT_SIZE, 1, file);
    fwrite(&publisherId, INT_SIZE, 1, file);
    fwrite(&isbn, LL_SIZE, 1, file);
    fwrite(title, CHAR_SIZE, STRING_SIZE, file);
    fwrite(author, CHAR_SIZE, STRING_SIZE, file);
    fwrite(genre, CHAR_SIZE, STRING_SIZE, file);
    fwrite(&prevBookAddress, LONG_SIZE, 1, file);
    fwrite(&nextBookAddress, LONG_SIZE, 1, file);
}

Book readBook(FILE* file, long address) {
    fseek(file, address, SEEK_SET);

    int id;
    int publisherId;
    long long isbn;
    char* title = new char[STRING_SIZE];
    char* author = new char[STRING_SIZE];
    char* genre = new char[STRING_SIZE];
    long prevBookAddress;
    long nextBookAddress;

    fread(&id, INT_SIZE, 1, file);
    fread(&publisherId, INT_SIZE, 1, file);
    fread(&isbn, LL_SIZE, 1, file);
    fread(title, CHAR_SIZE, STRING_SIZE, file);
    fread(author, CHAR_SIZE, STRING_SIZE, file);
    fread(genre, CHAR_SIZE, STRING_SIZE, file);
    fread(&prevBookAddress, LONG_SIZE, 1, file);
    fread(&nextBookAddress, LONG_SIZE, 1, file);

    return {id, publisherId, isbn, title, author, genre, prevBookAddress, nextBookAddress};
}

void writePublisher(FILE* file, const Publisher& publisher, long address) {
    fseek(file, address, SEEK_SET);

    int id = publisher.getId();
    char* name = publisher.getName();
    char* location = publisher.getLocation();
    long firstBookAddress = publisher.getFirstBookAddress();

    fwrite(&id, INT_SIZE, 1, file);
    fwrite(name, CHAR_SIZE, STRING_SIZE, file);
    fwrite(location, CHAR_SIZE, STRING_SIZE, file);
    fwrite(&firstBookAddress, LONG_SIZE, 1, file);
}

Publisher readPublisher(FILE* file, long address) {
    fseek(file, address, SEEK_SET);

    int id;
    char* name = new char[STRING_SIZE];
    char* location = new char[STRING_SIZE];
    long firstBookAddress;

    fread(&id, INT_SIZE, 1, file);
    fread(name, CHAR_SIZE, STRING_SIZE, file);
    fread(location, CHAR_SIZE, STRING_SIZE, file);
    fread(&firstBookAddress, LONG_SIZE, 1, file);

    return {id, name, location, firstBookAddress};
}

