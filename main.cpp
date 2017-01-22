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

  if (A->getValue() < B->getValue())
  {
    std::cout << "A < B" << std::endl;
  }
  else
  {
    std::cout << "A > B" << std::endl;
  }

  // initialize a new sorted list class object
  SortedListClass<int> myList;

  myList.insertValue(200);
  myList.insertValue(100);
  myList.insertValue(300);
  myList.insertValue(200);
  std::cout << "number of items in list = " << myList.getNumElems() << "\n";

  SortedListClass<int> newList(myList);

  myList.insertValue(1);
  myList.insertValue(3000);
  myList.insertValue(400);
  myList.insertValue(3000);
  myList.insertValue(400);

  std::cout << "  newList" << std::endl;
  newList.insertValue(200);
  newList.insertValue(2000);

  // test the printers
  std::cout << "\n\n" << std::endl;
  myList.printForward();
  std::cout << "\n\n" << std::endl;
  newList.printForward();
  std::cout << "\n\n" << std::endl;
  myList.printBackward();
  std::cout << "\n\n" << std::endl;
  newList.printBackward();
  std::cout << "\n\n" << std::endl;
  std::cout << "number of items in list = " << myList.getNumElems() << "\n";

  // test removeFront
  int rmFront;
  myList.removeFront(rmFront);
  std::cout << "removed from front: " << rmFront << "\n\n";
  std::cout << "number of items in list = " << myList.getNumElems() << "\n";

  // test removeLast
  int rmLast;
  myList.removeLast(rmLast);
  std::cout << "removed from back: " << rmLast << "\n\n";
  std::cout << "number of items in list = " << myList.getNumElems() << "\n";

  // test getElemAtIndex function
  int getVals;
  std::cout << myList.getElemAtIndex(0, getVals) << "\n";
  std::cout << getVals << "\n";
  std::cout << myList.getElemAtIndex(-1, getVals) << "\n";
  std::cout << getVals << "\n";
  std::cout << myList.getElemAtIndex(22, getVals) << "\n";
  std::cout << getVals << "\n";
  std::cout << myList.getElemAtIndex(4, getVals) << "\n";
  std::cout << getVals << "\n";
  std::cout << myList.getElemAtIndex(7, getVals) << "\n";
  std::cout << getVals << "\n";
  std::cout << myList.getElemAtIndex(8, getVals) << "\n";
  std::cout << getVals << "\n";
  std::cout << myList.getElemAtIndex(6, getVals) << "\n";
  std::cout << getVals << "\n";

  // todo: fix the clear function
  // done: fixed clear() on 01-21-17
  newList.clear();
  myList.clear();

  delete(A);
  delete(B);
  delete(C);

  return 0;
}
