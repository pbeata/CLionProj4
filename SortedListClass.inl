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
  SortedListClass();

  bool copyDone = false;
  LinkedNodeClass<T> *temp = rhs.head;

  if (temp == 0)
  {
    std::cout << "copying an empty list!" << std::endl;
    copyDone = true;
  }
  else
  {
    // create first node and set head to pt to it
    std::cout << "copying: " << temp->getValue() << std::endl;
    LinkedNodeClass<T> *newNode = new LinkedNodeClass<T>(NULL, temp->getValue(), NULL);
    head = newNode;

    // add remaining nodes to the list
    LinkedNodeClass<T> *prev = newNode;
    while (!copyDone)
    {
      if (temp->getNext() != 0)
      {
        temp = temp->getNext();
        std::cout << "copying: " << temp->getValue() << std::endl;
        LinkedNodeClass<T> *newNode = new LinkedNodeClass<T>(prev, temp->getValue(), NULL);
        newNode->setBeforeAndAfterPointers();
        prev = newNode;
      }
      else
      {
        std::cout << "reached the tail during copying" << std::endl;
        tail = prev;
        copyDone = true;
      }
    }

    std::cout << "\n COPIED HEAD: " << head->getValue() << std::endl;
    std::cout << " COPIED TAIL: " << tail->getValue() << "\n" << std::endl;

  }
}

//Clears the list to an empty state without resulting in any
//memory leaks.
template< class T >
void SortedListClass<T>::clear()
{
  bool emptyList = false;
  LinkedNodeClass<T> *temp = head;

  if (head == NULL || tail == NULL)
  {
    std::cout << "list is already empty!" << std::cout;
    emptyList = true;
  }

  while (!emptyList)
  {
    if (head != tail)
    {
      head = temp->getNext();
      temp->setPreviousPointerToNull();
      temp->setNextPointerToNull();
      head->setPreviousPointerToNull();
      std::cout << "deleting this value from list: " << temp->getValue() << std::endl;
      delete (temp);
      temp = head;
    }
    else
    {
      std::cout << "deleting LAST value from list: " << temp->getValue() << std::endl;
      delete (temp);
      emptyList = true;
    }
  }

  head = NULL;
  tail = NULL;
  std::cout << "*list has been cleared!*" << std::endl;
}

//Allows the user to insert a value into the list.
template< class T >
void SortedListClass<T>::insertValue(const T &valToInsert)
{
  bool found = false;
  int check = 0;


  //while (!found)
  //{
    // empty list case
    if (head == NULL || tail == NULL)
    {
      // then this is the first node in the list!
      LinkedNodeClass<T> *newNode = new LinkedNodeClass<T> (NULL, valToInsert, NULL);
      head = newNode;
      tail = newNode;
      found = true;
      std::cout << "inserted FIRST value into list = " << head->getValue() << " also " << tail->getValue() << std::endl;
    }
    else
    {
        LinkedNodeClass<T> *temp = head;

      // single-node case
      /*
      if (head == tail) {
        std::cout << temp->getValue() << " and " << valToInsert << std::endl;
        if (valToInsert < temp->getValue()) {
          std::cout << "new value is smaller than the ONE existing node's value" << std::endl;
          LinkedNodeClass<T> *newNode = new LinkedNodeClass<T>(NULL, valToInsert, temp);
          head = newNode;
          newNode->setBeforeAndAfterPointers();
        } else {
          std::cout << "new value is >= than the ONE existing node's value" << std::endl;
          LinkedNodeClass<T> *newNode = new LinkedNodeClass<T>(temp, valToInsert, NULL);
          tail = newNode;
          newNode->setBeforeAndAfterPointers();
        }
        found = true;
      }
      else  // multi-node case
      {
      */
        // check head
        //if (valToInsert < temp->getValue() && temp == head)
        if (valToInsert < head->getValue())
        {
          temp = head;
          LinkedNodeClass<T> *newNode = new LinkedNodeClass<T>(NULL, valToInsert, temp);
          head = newNode;
          newNode->setBeforeAndAfterPointers();
          found = true;
          std::cout << "inserted " << valToInsert << " at the HEAD" << std::endl;
        }
        // check tail
        //else if (valToInsert >= temp->getValue() && temp == tail)
        else if (valToInsert >= tail->getValue())
        {
          temp = tail;
          LinkedNodeClass<T> *newNode = new LinkedNodeClass<T>(temp, valToInsert, NULL);
          tail = newNode;
          newNode->setBeforeAndAfterPointers();
          found = true;
          std::cout << "inserted " << valToInsert << " at the TAIL" << std::endl;
        }
      //}

      // otherwise, step through list
        temp = head;
        while (!found)
        {

          std::cout << "current temp value   = " << temp->getValue() << std::endl;
          std::cout << "value to be inserted = " << valToInsert << std::endl;
          std::cout << "next value  in list  = " << (temp->getNext())->getValue() << std::endl;

          if (temp == tail)
          {
            /*
            // reached end of list so value must be before or after the tail
            if (temp->getValue() <= valToInsert)
            {
              // new value goes before tail

            }
            else
            {
              // new value is the tail
            }
            */
            std::cout << "we are at the tail" << std::endl;
          }
          else if (temp->getValue() <= valToInsert && valToInsert < (temp->getNext())->getValue() )
          {
            std::cout << "inserted " << valToInsert << " between " << temp->getValue() << " and " << (temp->getNext())->getValue() << std::endl;
            LinkedNodeClass<T> *newNode = new LinkedNodeClass<T>(temp, valToInsert, temp->getNext());
            newNode->setBeforeAndAfterPointers();
            found = true;
          }
          else
          {
            temp = temp->getNext();
            std::cout << "*moving temp to getNext()*" << std::endl;
          }


          /*
          check++;
          if (check > 5)
          {
            std::cout << "**stopped while loop for testing**" << std::endl;
            found = true;
          }
          */

        }

    }
  //}
  //delete(temp);
}

//Prints the contents of the list from head to tail to the screen.
template< class T >
void SortedListClass<T>::printForward() const
{
  std::cout << "*WARNING: printForward() is incomplete!" << std::endl;
}

// std::cout << " " << std::endl;