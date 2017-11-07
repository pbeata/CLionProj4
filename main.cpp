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
  11-07-17: finished the project!!!
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
  // set the seed value for testing
  int mySeedVal = 100;
  setSeed(mySeedVal);

  // input variables
  int closing;
  double riderArrivMean, riderArrivStd;
  int carArrivMin, carArrivMax;

  // other variables in the system
  int i, j;
  int temp, randVal, clock = 0;
  int riderArrival, carArrival;
  bool checkQueue, checkRide;

  // ride-specific input
  int rideSeats = 10;
  std::string rideName = "Space_Mountain";

  // FIFO queues for riders
  //    for this project, assume 3 queues for rider priority:
  //    SFP = Queue #0, FP = #1, and STD = #2
  const int NUM_RIDER_QUEUES = 3;
  FIFOQueueClass<int> riderQueues[NUM_RIDER_QUEUES];
  int percentPriority[NUM_RIDER_QUEUES];
  int idealRiders[NUM_RIDER_QUEUES];
  int minPercent = 0, totalPercent = 100;

  // rider statistics
  int totalRiders[NUM_RIDER_QUEUES];
  int totalWaitTime[NUM_RIDER_QUEUES];
  int lineLength[NUM_RIDER_QUEUES];
  int maxLength[NUM_RIDER_QUEUES];
  for (i = 0; i < NUM_RIDER_QUEUES; i++)
  {
    totalRiders[i] = 0;
    totalWaitTime[i] = 0;
    lineLength[i] = 0;
    maxLength[i] = 0;
  }

  // ====================================================================
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
  inFile >> percentPriority[0];
  inFile >> percentPriority[1];
  inFile >> idealRiders[0];
  inFile >> idealRiders[1];
  inFile.close();

  // derived parameters from input
  percentPriority[NUM_RIDER_QUEUES-1] = totalPercent;
  idealRiders[NUM_RIDER_QUEUES-1] = rideSeats;
  for (i = 0; i < NUM_RIDER_QUEUES-1; i++)
  {
    percentPriority[NUM_RIDER_QUEUES-1] -= percentPriority[i];
    idealRiders[NUM_RIDER_QUEUES-1] -= idealRiders[i];
  }
  // set this for testing
  idealRiders[NUM_RIDER_QUEUES-1] = 1;
  // ====================================================================  

  // initialize ride event queue
  SortedListClass<int> eventQueue;
  riderArrival = getNormal(riderArrivMean, riderArrivStd);
  eventQueue.insertValue(riderArrival);
  carArrival = getUniform(carArrivMin, carArrivMax);
  eventQueue.insertValue(carArrival);

  // initialize first ride of the park
  ParkRideClass myRide(rideName, rideSeats);


    
  // main event loop (todo: change to while event queue not empty)
  while (eventQueue.getNumElems() > 0)
  {
    eventQueue.removeFront(clock);

    // CAR ARRIVAL EVENT
    if (clock == carArrival)
    {
      // handle car arrival event
      printf("\n\n\n===>> new car arrives at %d \n", clock);
      myRide.unloadRiders();
      printf("Rider queues: \n");
      printf("Super Fast Pass :: ");
      riderQueues[0].print();
      printf("      Fast Pass :: ");
      riderQueues[1].print();
      printf("  Standard Pass :: ");
      riderQueues[2].print();
      printf("\n");

      // fill car with ideal number of riders first
      printf("Riders selected to board the car: \n");
      for (j = 0; j < NUM_RIDER_QUEUES; j++)
      {
        for (i = 0; i < idealRiders[j]; i++)
        {
          checkRide = myRide.carIsFull();
          if (!checkRide)
          {
            checkQueue = riderQueues[j].dequeue(temp);
            if (checkQueue)
            {
              lineLength[j] -= 1;
              totalWaitTime[j] += (clock - temp);
              myRide.addRider(temp);
              printf("%d ", temp);
            }
          }
        }
        printf("\n");
      }

      // try to fill remaining available seats in the car
      j = 0;
      while (!checkRide && j < NUM_RIDER_QUEUES)
      {
        checkRide = myRide.carIsFull();
        if (!checkRide)
        {
          checkQueue = riderQueues[j].dequeue(temp);
          if (checkQueue)
          {
            lineLength[j] -= 1;
            totalWaitTime[j] += (clock - temp);
            myRide.addRider(temp);
            printf("%d ", temp);
          }
          else
          {
            j++;
            printf("\n");
          }
        }
      }

      // generate next car arrival event
      carArrival = clock + getUniform(carArrivMin, carArrivMax);
      if (checkQueue || clock < closing)
      {
        eventQueue.insertValue(carArrival);
      }
    }

    // RIDER ARRIVAL EVENT
    else
    {
      // handle rider arrival event
      randVal = getUniform(minPercent, totalPercent);
      temp = minPercent;
      for (i = 0; i < NUM_RIDER_QUEUES; i++)
      {
        if ( temp <= randVal && randVal < temp+percentPriority[i] )
        {
          riderQueues[i].enqueue(clock);
          lineLength[i] += 1;
          totalRiders[i] += 1;
          if (lineLength[i] > maxLength[i])
          {
            maxLength[i] = lineLength[i];
          }
        }
        temp += percentPriority[i];
      }

      // generate new rider arrival
      riderArrival = clock + getNormal(riderArrivMean, riderArrivStd);
      if (riderArrival < closing)
      {
        eventQueue.insertValue(riderArrival);
      }
    }
  }

  // print summary stats:

    printf("\ntotal riders served per queue: \n");
    printf("Super Fast Pass :: ");
    printf("%d \n", totalRiders[0]);
    printf("      Fast Pass :: ");
    printf("%d \n", totalRiders[1]);
    printf("  Standard Pass :: ");
    printf("%d \n", totalRiders[2]);

    printf("\nmax length of each queue: \n");
    printf("Super Fast Pass :: ");
    printf("%d \n", maxLength[0]);
    printf("      Fast Pass :: ");
    printf("%d \n", maxLength[1]);
    printf("  Standard Pass :: ");
    printf("%d \n", maxLength[2]);

    printf("\naverage wait time of each queue: \n");
    printf("Super Fast Pass :: ");
    printf("%f \n", (double)(totalWaitTime[0]/totalRiders[0]) );
    printf("      Fast Pass :: ");
    printf("%f \n", (double)(totalWaitTime[1]/totalRiders[1]) );
    printf("  Standard Pass :: ");
    printf("%f \n", (double)(totalWaitTime[2]/totalRiders[2]) );

  // simulation is completed
  printf("\nThis is the end of the simulation! \n\n");
  return 0;
}
