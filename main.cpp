#include <iostream>
#include "Publisher.h"

int main() {
    Publisher myPublisher1;
    std::cout << "default constructor:\n" << myPublisher1.toString() << "\n";

    Publisher myPublisher2(1, "Ababagalamaga", "Sechenova 6");
    std::cout << "explicit constructor without state:\n" << myPublisher2.toString() << "\n";

    Publisher myPublisher3(2, "Stariy Lev", "Luhova 43", false);
    std::cout << "explicit constructor with state:\n" << myPublisher3.toString() << "\n";

    return 0;
}
