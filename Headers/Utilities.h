//
// Created by vasyl on 2/17/2024.
//

#ifndef DBO_LAB1_UTILITIES_H
#define DBO_LAB1_UTILITIES_H

#include <cstdlib>
#include "Book.h"
#include "Publisher.h"

void writeBook(FILE* file, const Book& book, long address = 0);

Book readBook(FILE* file, long address = 0);

void writePublisher(FILE* file, const Publisher& publisher, long address = 0);

Publisher readPublisher(FILE* file, long address = 0);

#endif //DBO_LAB1_UTILITIES_H
