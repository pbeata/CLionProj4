/*
	EECS 402 Project 4
	By Paul A. Beata
	Main Program

	December 2016
	January 2017
  March 2017
  November 2017  (completed this month)

  12-12-16: created GitHub repo to host project 4
  01-14-17: moving project into Code::Blocks IDE
  01-22-17: finished Phases 1-2 in CLion IDE
    --> transitioning into event-driven simulation for the main loop

  03-22-17: restarting the project on my free time at night!
  10-31-17: restarted project as a post-doc now at NCSU
*/


#include <iostream>
#include <fstream>
#include <stdio.h>


#include "LinkedNodeClass.h"
#include "SortedListClass.h"
#include "FIFOQueueClass.h"
#include "ParkRideClass.h"
#include "random.h"


int main(int argc, char *argv[])
{
  /*
   * todo: 01-22-17 Consider using the "switch" command to coordinate the main program development
  bool testingDataStructuresOnly = false;

  switch (testingDataStructuresOnly)
  {
    case false:
      std::cout << "starting simulation ...\n";
      break;
    case true:
      std::cout << "starting tests of custom data structures ...\n";
      break;
    default:
      std::cout << "must specify what the main program should do\n";
  }
  */

  // conditions for running the main program
  bool testDataStructs = false;

  // set the seed value for testing
  int mySeedVal = 100;
  setSeed(mySeedVal);

  // input variables
  int closing;
  double riderArrivMean, riderArrivStd;
  int carArrivMin, carArrivMax;
  int percSFP, percFP;
  int idealSFP, idealFP;

  // other variables in the system
  int clock = 0;
  int riderArrival;
  int carArrival;
  int minRange = 0, maxRange = 100, randVal;

  // file management
  ifstream inFile;
  std::string inFileName;

  // get input file name from command line argument
  if (argc != 2)
  {
    printf("***Error: only supply one command line argument\n");
    printf("   Expected Usage:  $ ./parkSimulation simParams.txt \n");
    exit(1);
  }
  else
  {
    inFileName = argv[1];
    std::cout << "Got input file name: " << inFileName << "\n";
  }

  // read input parameters from the file
  inFile.open(inFileName.c_str());
  inFile >> closing;
  inFile >> riderArrivMean;
  inFile >> riderArrivStd;
  inFile >> carArrivMin;
  inFile >> carArrivMax;
  inFile >> percSFP;
  inFile >> percFP;
  inFile >> idealSFP;
  inFile >> idealFP;
  inFile.close();

  // FIFO queues for riders
  //    for this project, assume 3 queues for rider priority:
  //    SFP = Queue #0, FP = #1, and STD = #2
  const int NUM_RIDER_QUEUES = 3;
  FIFOQueueClass<int> riderQueues[NUM_RIDER_QUEUES];

  // initialize ride event queue
  SortedListClass<int> eventQueue;
  riderArrival = getNormal(riderArrivMean, riderArrivStd);
  eventQueue.insertValue(riderArrival);
  carArrival = getUniform(carArrivMin, carArrivMax);
  eventQueue.insertValue(carArrival);

  // initialize first ride of the park
  ParkRideClass myRide("Space_Mountain", 10);



    
  // main event loop (todo: change to while event queue not empty)
  closing = 200;
  while (clock < closing)
  {

    eventQueue.removeFront(clock);
    printf("\nCURRENT TIME = %d \n", clock);

    // check the event type
    if (clock == carArrival)
    {
      // handle car arrival event
      printf(" ===>> new car arrives at %d \n", clock);
      carArrival = clock + getUniform(carArrivMin, carArrivMax);
      eventQueue.insertValue(carArrival);

      // load up the car by priority level
      myRide.unloadRiders();
      

    }
    else
    {
      // handle rider arrival event
      randVal = getUniform(minRange, maxRange);
      if (randVal < percSFP)
      {
        // SFP Queue
        riderQueues[0].enqueue(clock);
      }
      else if (percSFP <= randVal && randVal < (percSFP + percFP))
      {
        // FP Queue
        riderQueues[1].enqueue(clock);
      }
      else
      {
        // STD Queue
        riderQueues[2].enqueue(clock);
      }
      //printf("(added rider to proper queue)\n");
      riderArrival = clock + getNormal(riderArrivMean, riderArrivStd);
      eventQueue.insertValue(riderArrival);
    }
  }






  /*  TESTING CUSTOM DATA STRUCTURES ONLY
   *    -- these are from Phases 1-2
   *    -- completed the testing script 01-22-17
   */
  if (testDataStructs)
  {
    std::cout << "\nstarting tests of custom data structures ...\n\n";
    LinkedNodeClass<int> *A = new LinkedNodeClass<int>(NULL, 1000, NULL);
    LinkedNodeClass<int> *C = new LinkedNodeClass<int>(A, 3000, NULL);
    LinkedNodeClass<int> *B = new LinkedNodeClass<int>(A, 2000, C);

    std::cout << "A = " << A->getValue() << std::endl;
    std::cout << "B = " << B->getValue() << std::endl;
    std::cout << "C = " << C->getValue() << std::endl;

    std::cout << "B prev = " << (B->getPrev())->getValue() << std::endl;
    std::cout << "B next = " << (B->getNext())->getValue() << std::endl;

    B->setBeforeAndAfterPointers();
    B->setPreviousPointerToNull();
    B->setNextPointerToNull();

    //std::cout << B->getPrev() << std::endl;
    //std::cout << B->getNext() << std::endl;

    if (A->getValue() < B->getValue()) {
      std::cout << "A < B" << std::endl;
    } else {
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
    std::cout << "\n\n" << std::endl;
    newList.printForward();
    std::cout << "\n\n" << std::endl;

    myList.insertValue(1);
    myList.insertValue(3000);
    myList.insertValue(400);
    myList.insertValue(3000);
    myList.insertValue(400);

    //std::cout << "  newList" << std::endl;
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

    delete (A);
    delete (B);
    delete (C);

    // testing of FIFOQueueClass
    std::cout << "\n\n";
    FIFOQueueClass<int> myQ;
    myQ.enqueue(10);
    myQ.enqueue(20);
    myQ.enqueue(30);
    myQ.print();

    int deq;
    myQ.dequeue(deq);
    std::cout << "\nremoved value: " << deq << "\n";
    myQ.print();

    myQ.dequeue(deq);
    std::cout << "removed value: " << deq << "\n";
    myQ.print();

    myQ.dequeue(deq);
    std::cout << "removed value: " << deq << "\n";
    myQ.print();

    myQ.dequeue(deq);
    std::cout << "removed value: " << deq << "\n";
    myQ.print();
  }

  return 0;
}
