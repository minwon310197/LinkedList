#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
using namespace std;

template <typename T> class LinkedList
{
private:
   struct Node
   {
      T data;
      Node* pNext;
      Node(T value) : data(value), pNext(nullptr) {};
   };

   Node* m_pHead;

public:
   LinkedList() : m_pHead(nullptr) {};
   ~LinkedList()
   {
      deleteList();
   }

   LinkedList(const LinkedList<T>&) = delete;
   LinkedList& operator=(const LinkedList<T>&) = delete;

   void insertNode(T data)
   {
      Node* pNewData = new Node(data);
      if (m_pHead == nullptr)
      {
         m_pHead = pNewData;
      }
      else
      {
         Node* temp = m_pHead;

         // find the last element
         while (temp->pNext != nullptr)
         {
            temp = temp->pNext;
         }

         // insert to the end of list
         temp->pNext = pNewData;
      }
   }

   Node* searchNode(T data)
   {
      Node* pNode = m_pHead;

      while (pNode != nullptr)
      {
         if (pNode->data == data)
         {
            return pNode;
         }
         pNode = pNode->pNext;
      }

      return nullptr;
   }

   void deleteNode(T data)
   {
      Node* pNode = m_pHead;

      // if head node itself hold the key to be deleted
      if ((pNode != nullptr) && (pNode->data == data))
      {
         m_pHead = pNode->pNext;
         delete pNode;
         return;
      }

      Node* pPrev = nullptr;
      while ((pNode != nullptr) && (pNode->data != data))
      {
         pPrev = pNode;
         pNode = pNode->pNext;
      }

      // if key is not present in linked list
      if (pNode == nullptr)
         return;

      // key is present, unlink the node from linked list
      pPrev->pNext = pNode->pNext;
      delete pNode;
   }

   void deleteList()
   {
      Node* current = m_pHead;
      Node* next = nullptr;

      while (current != nullptr)
      {
         next = current->pNext;
         delete current;
         current = next;
      }

      m_pHead = nullptr;
   }

   void printList()
   {
      Node* pNode = m_pHead;
      while (pNode != nullptr)
      {
         cout << pNode->data << " ";
         pNode = pNode->pNext;
      }
      cout << endl;
   }
};

#endif /* LINKEDLIST_H_ */
