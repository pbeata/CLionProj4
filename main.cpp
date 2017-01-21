/*
	EECS 402 Project 4
	By Paul A. Beata
	Main Program

	December 2016
	January 2017

  12-12-16: created GitHub repo to host project 4
  01-14-17: moving project into Code::Blocks IDE
*/

#include <iostream>
#include "LinkedNodeClass.h"
#include "SortedListClass.h"

int main()
{

  LinkedNodeClass<int>* A = new LinkedNodeClass<int> (NULL, 1000, NULL);
  LinkedNodeClass<int>* C = new LinkedNodeClass<int> (A, 3000, NULL);
  LinkedNodeClass<int>* B = new LinkedNodeClass<int> (A, 2000, C);

  std::cout << A->getValue() << std::endl;
  std::cout << B->getValue() << std::endl;
  std::cout << C->getValue() << std::endl;

  std::cout << "prev : " << (B->getPrev())->getValue() << std::endl;
  std::cout << "next : " << (B->getNext())->getValue() << std::endl;

  B->setBeforeAndAfterPointers();

  B->setPreviousPointerToNull();
  B->setNextPointerToNull();

  std::cout << B->getPrev() << std::endl;
  std::cout << B->getNext() << std::endl;

  // initialize a new sorted list class object
  SortedListClass<int> myList;

  if (A->getValue() < B->getValue())
  {
    std::cout << "A < B" << std::endl;
  }
  else
  {
    std::cout << "A > B" << std::endl;
  }

  myList.insertValue(100);
  SortedListClass<int> newList(myList);

  //newList.clear();
  //myList.clear();

  delete(A);
  delete(B);
  delete(C);
  //delete(myList);
  //delete(newList);

  return 0;
}
