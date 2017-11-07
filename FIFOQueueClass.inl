#include "FIFOQueueClass.h"

//Default Constructor. Will properly initialize a queue to
//be an empty queue, to which values can be added.
template< class T >
FIFOQueueClass<T>::FIFOQueueClass()
{
  //std::cout << "default FIFO ctor was called!" << std::endl;
  head = NULL;
  tail = NULL;
}

//Inserts the value provided (newItem) into the queue.
template< class T >
void FIFOQueueClass<T>::enqueue(const T &newItem)
{
  LinkedNodeClass<T> *temp = tail;

  if (temp == 0)
  {
    LinkedNodeClass<T> *newNode = new LinkedNodeClass<T> (NULL, newItem, NULL);
    head = newNode;
    tail = newNode;
  }
  else
  {
    LinkedNodeClass<T> *newNode = new LinkedNodeClass<T> (temp, newItem, NULL);
    newNode->setBeforeAndAfterPointers();
    tail = newNode;
  }
}

//Attempts to take the next item out of the queue. If the
//queue is empty, the function returns false and the state
//of the reference parameter (outItem) is undefined. If the
//queue is not empty, the function returns true and outItem
//becomes a copy of the next item in the queue, which is
//removed from the data structure.
template< class T >
bool FIFOQueueClass<T>::dequeue(T &outItem)
{
  LinkedNodeClass<T> *temp = head;
  if (temp == 0)
  {
    // list is empty!
    //std::cout << "*warning: attempted to dequeue from empty queue\n";
    return false;
  }
  else
  {
    //std::cout << temp->getValue() << "\n";
    outItem = temp->getValue();

    if (temp->getNext() != 0)
    {
      head = temp->getNext();
      head->setPreviousPointerToNull();
      temp->setNextPointerToNull();
    }
    else
    {
      head = NULL;
      tail = NULL;
      //std::cout << "*warning: deleting last queue item\n";
    }

    delete(temp);
    return true;
  }
}

//Prints out the contents of the queue. All printing is done
//on one line, using a single space to separate values, and a
//single newline character is printed at the end.
template< class T >
void FIFOQueueClass<T>::print() const
{
  LinkedNodeClass<T> *temp = head;

  while (temp != 0)
  {
    std::cout << temp->getValue() << " ";
    temp = temp->getNext();
  }
  std::cout << "\n";
}