//
// Created by vasyl on 2/17/2024.
//

#ifndef DBO_LAB1_UTILITIES_H
#define DBO_LAB1_UTILITIES_H

#include <cstdlib>
#include "Book.h"
#include "Publisher.h"

void writeBook(FILE* file, const Book& book);

void writeBook(FILE* file, const Book& book, long address);

Book readBook(FILE* file);

Book readBook(FILE* file, long address);

void writePublisher(FILE* file, const Publisher& publisher);

void writePublisher(FILE* file, const Publisher& publisher, long address);

Publisher readPublisher(FILE* file);

Publisher readPublisher(FILE* file, long address);

#endif //DBO_LAB1_UTILITIES_H
