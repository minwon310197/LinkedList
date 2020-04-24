#include "LinkedList.h"

int main() {

   LinkedList<int> numList;
   numList.insertNode(1);
   numList.insertNode(2);
   numList.insertNode(3);
   numList.insertNode(4);
   numList.insertNode(5);
   numList.printList();

   numList.deleteNode(4);
   numList.printList();

   LinkedList<char> charList;
   charList.insertNode('a');
   charList.insertNode('b');
   charList.insertNode('c');
   charList.insertNode('d');
   charList.insertNode('e');
   charList.printList();

   charList.deleteNode('b');
   charList.printList();

   return 0;
}
