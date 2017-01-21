#include "SortedListClass.h"

//Default Constructor. Will properly initialize a list to
//be an empty list, to which values can be added.
template< class T >
SortedListClass<T>::SortedListClass()
{
  std::cout << "default list ctor was called!" << std::endl;
  head = NULL;
  tail = NULL;
}

//Copy constructor. Will make a complete copy of the list, such
//that one can be changed without affecting the other.
template< class T >
SortedListClass<T>::SortedListClass(const SortedListClass< T > &rhs)
{
  std::cout << "copy ctor was called!" << std::endl;
  head = rhs.head;
  tail = rhs.tail;
}

//Clears the list to an empty state without resulting in any
//memory leaks.
template< class T >
void SortedListClass<T>::clear()
{
  bool emptyList = false;

  if (head == NULL || tail == NULL)
  {
    //std::cout << "list is already empty!" << std::cout;
    emptyList = true;
  }
  else
  {
    while (!emptyList)
    {
      LinkedNodeClass<T> *temp = head;
      head = temp->getNext();
      head->setPreviousPointerToNull();
      delete temp;
      if (head == tail)
      {
        emptyList = true;
        delete head;
      }
    }
  }
}

//Allows the user to insert a value into the list.
template< class T >
void SortedListClass<T>::insertValue(const T &valToInsert)
{
  if (head == NULL || tail == NULL)
  {
    // then this is the first node in the list!
    LinkedNodeClass<T>* temp = new LinkedNodeClass<T> (NULL, valToInsert, NULL);
    head = temp;
    tail = temp;
  }
  else
  {

    // NOTE 01-17-17 at 21:27
    // this is where I left off: where to insert a new node?

    bool found = false;
    LinkedNodeClass<T> *temp = head;

    // single-node case
    if (head == tail)
    {
      if (valToInsert < head->getValue())
      {

      }
      else
      {

      }
    }

    // compare with head

    // compare with tail

    // else... interior node

  }
}