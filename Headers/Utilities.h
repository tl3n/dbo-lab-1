//
// Created by vasyl on 2/17/2024.
//

#ifndef DBO_LAB1_UTILITIES_H
#define DBO_LAB1_UTILITIES_H

#include <cstdlib>
#include "Book.h"
#include "Publisher.h"

void writeBook(FILE* file, const Book& book);

Book readBook(FILE* file);

void writePublisher(FILE* file, const Publisher& publisher);

Publisher readPublisher(FILE* file);

#endif //DBO_LAB1_UTILITIES_H
