#include <iostream>
#include "Publisher.h"
#include "Book.h"
#include "Utilities.h"
#include "ListNode.h"

int main() {
    // publisher class tests
    /*Publisher myPublisher1;
    //std::cout << "default constructor:\n" << myPublisher1.toString() << "\n";

    Publisher myPublisher2(1, "Ababagalamaga", "Sechenova 6", -1);
    //std::cout << "explicit constructor without state:\n" << myPublisher2.toString() << "\n";

    Publisher myPublisher3(2, "Stariy Lev", "Luhova 43", -1);
    //std::cout << "explicit constructor with state:\n" << myPublisher3.toString() << "\n";

    // books class tests
    Book myBook1(1, 1, 1111111111111, "1", "2", "3", -1, -1);
    //std::cout << "default constructor:\n" << myBook1.toString() << '\n';

    Book myBook2(2, 2, 2222222222222, "4", "5", "6", -2, -2);
    //std::cout << "explicit constructor:\n" << myBook2.toString() << '\n';

    // utilities tests
    FILE* file = fopen("books", "w+b");
    writeBook(file, myBook1);
    writeBook(file, myBook2);

    fseek(file, 0, SEEK_SET); // setting file position indicator to the beginning

    Book myBook3 = readBook(file);
    std::cout << myBook3.toString();
    Book myBook4 = readBook(file);
    std::cout << myBook4.toString();

    FILE* file = fopen("publishersF", "w+b");
    writePublisher(file, myPublisher2);
    writePublisher(file, myPublisher3);

    std::cout << readPublisher(file, 0).toString();
    std::cout << readPublisher(file).toString();
    return 0;*/

    // list tests
    ListNode* head = new ListNode;
    head->id = 1;
    head->address = 0;

    addListNode(5, 0, &head);
    addListNode(20, 0, &head);
    addListNode(3, 0, &head);
    addListNode(8, 0, &head);

    printList(head);

    sortList(&head);
    printList(head);

    removeListNode(8, &head);
    printList(head);

    removeListNode(1, &head);
    printList(head);
}
