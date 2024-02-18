#include <iostream>
#include "Publisher.h"
#include "Book.h"
#include "Utilities.h"

int main() {
    // publisher class tests
    Publisher myPublisher1;
    //std::cout << "default constructor:\n" << myPublisher1.toString() << "\n";

    Publisher myPublisher2(1, "Ababagalamaga", "Sechenova 6");
    //std::cout << "explicit constructor without state:\n" << myPublisher2.toString() << "\n";

    Publisher myPublisher3(2, "Stariy Lev", "Luhova 43", false);
    //std::cout << "explicit constructor with state:\n" << myPublisher3.toString() << "\n";

    // books class tests
    Book myBook1;
    //std::cout << "default constructor:\n" << myBook1.toString() << '\n';

    Book myBook2(1, 1, 1111111111111, "1", "2", "3");
    //std::cout << "explicit constructor:\n" << myBook2.toString() << '\n';

    // utilities tests
    FILE* file = fopen("books", "w+b");
    writeBook(file, myBook2);

    fseek(file, 0, SEEK_SET); // setting file position indicator to the beginning

    Book myBook3 = readBook(file);
    std::cout << myBook3.toString();
    return 0;
}
