#include <iostream>
#include "Menu.h"
#include "Functions.h"

int main() {
    prepareFiles("Publishers.bin",
                 "Books.bin",
                 "PublishersIndex.bin",
                 "BooksIndex.bin",
                 "PublishersGarbage.bin",
                 "booksGarbage.bin");
    start();
    close("PublishersIndex.bin",
          "BooksIndex.bin",
          "PublishersGarbage.bin",
          "booksGarbage.bin");
    return 0;
}
