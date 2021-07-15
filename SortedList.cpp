#include "SortedList.h"
#include <iostream>
#include <utility>

//possible exceptions
class OutOfBound
{};
class DuplicateItem
{};
class DeletingMissingItem
{};

//Constructor------------------------
template <class ItemType>
SortedList<ItemType>::SortedList() {
  head = nullptr;
  length = 0;
} //constructor

//Destructor------------------------
template <class ItemType>
SortedList<ItemType>::~SortedList() {
  makeEmpty();
} //destructor

//Const Methods--------------------
template <class ItemType>
bool SortedList<ItemType>::isEmpty() const {
  if (length == 0) {
    return true;
  } else {
    return false;
  }
} //isEmpty

template <class ItemType>
int SortedList<ItemType>::getLength() const {
  return length;
} //getLength

//Helper Method--------------------
template <class ItemType>
std::pair<bool, Node<ItemType>*> SortedList<ItemType>::findItem(ItemType item) {
  bool found = NULL;
  Node<ItemType>* prevNode = nullptr;
  curr = head;

  while (curr != nullptr) {
    if (curr->info == item) {
      found = true;
      return make_pair(found, prevNode);
    } else if (curr->info > item) {
      found = false;
      return make_pair(found, prevNode);
    }
    prevNode = curr;
    curr = curr->next;
  }
  return make_pair(found, prevNode);
} //findItem

//Regular Methods------------------
template <class ItemType>
void SortedList<ItemType>::makeEmpty() {
  Node<ItemType>* temp;
  while (head != nullptr) {
    temp = head;
    head = head->next;
    delete temp;
  }
  length = 0;
  head = nullptr;
} //makeEmpty

template <class ItemType>
ItemType SortedList<ItemType>::getAt(int index) {
  if (index < 1 || index > length) {
    throw OutOfBound();
  }
  int count = 1;
  curr = head;
  while (count < index) {
    curr = curr->next;
    count++;
  }
  return curr->info;
} //getAt
   
template <class ItemType>
void SortedList<ItemType>::putItem(ItemType newItem) {
  if (findItem(newItem).first == true) {
    throw DuplicateItem();
  }
  Node<ItemType>* addNode;
  Node<ItemType>* prevNode;
  curr = head;
  prevNode = nullptr;
  addNode = new Node<ItemType>;
  addNode->info = newItem;
  while ((curr != nullptr) && (newItem > curr->info)) {
    prevNode = curr;
    curr = curr->next;
  }
  if (prevNode == nullptr) {
    addNode->next = curr;
    head = addNode;
  } else {
    addNode->next = curr;
    prevNode->next = addNode;
  }
  length++;
} //putItem

template <class ItemType>
void SortedList<ItemType>::deleteItem(ItemType item) {
  if (findItem(item).first == false) {
    throw DeletingMissingItem();
  }
  Node<ItemType>* prevNode = nullptr;
  Node<ItemType>* temp = head;
  if (item == head->info) {
    //if the node to be deleted is the first node in the list
    head = head->next;
  } else {
    while (item != (temp->info)) {
      prevNode = temp;
      temp = temp->next;
    }
    prevNode->next = temp->next;
  }
  delete temp;
  length--;
} //deleteItem
    
template <class ItemType>
void SortedList<ItemType>::printList(ofstream& outFile) {
  curr = head;
  outFile << "List Items: ";
  if (curr == nullptr) {
    outFile << "NULL";
  }
  while (curr != nullptr) {
    outFile << curr->info << "->";
    curr = curr->next;
    if (curr == nullptr) {
      outFile << "NULL";
    }
  }
} //printList

template <class ItemType>
void SortedList<ItemType>::merge(SortedList& otherList) {
  Node<ItemType>* curr1 = head;
  Node<ItemType>* curr2 = otherList.head;
  Node<ItemType>* newList = nullptr;
  Node<ItemType>* newListCurr = newList;
  if(curr2 != nullptr || curr1!= nullptr) {
        if(curr2 == nullptr) {
            newListCurr = curr1;
            curr1 = curr1->next;
        } else if(curr1 == nullptr) {
            newListCurr = curr2;
            curr2 = curr2->next;
        } else if(curr1->info < curr2->info) {
            newListCurr = curr1;
            curr1 = curr1->next;
        } else if (curr2->info < curr1->info) {
            newListCurr = curr2;
            curr2 = curr2->next;
        } else if (curr1->info == curr2->info) {
            newListCurr = curr1;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        newList = newListCurr;
    }
    while(curr2 != nullptr || curr1 != nullptr) {
        if(curr2 == nullptr) {
            newListCurr->next = curr1;
            curr1 = curr1->next;
            newListCurr = newListCurr->next;
        }
        else if(curr1 == nullptr) {
            newListCurr->next = curr2;
            curr2 = curr2->next;
            newListCurr = newListCurr->next;
        }
        else if(curr1->info < curr2->info) {

            newListCurr->next = curr1;
            curr1 = curr1->next;
            newListCurr = newListCurr->next;
        } else if (curr2->info < curr1->info) {
            newListCurr->next = curr2;
            curr2 = curr2->next;
            newListCurr = newListCurr->next;
        }
        else if (curr1->info == curr2->info) {
            newListCurr->next = curr1;
            curr1 = curr1->next;
            curr2 = curr2->next;
            newListCurr = newListCurr->next;
        }
    }
    otherList.head = nullptr;
    head = newList;
} //merge

    



  
    







  
