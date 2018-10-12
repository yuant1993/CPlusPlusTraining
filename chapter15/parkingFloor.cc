#include "parkingFloor.h"
#include <iostream>

using namespace std;

void ParkingFloor::setNumTaken() {
  numTaken++;
  if (numTaken == capacity()) {
    full = true;
  }
}

int ParkingFloor::capacity() {
  int numLength = (int)(lotLength() / spotWidth;
  int numWidth = (int)(lotWidth() / (spotLength + spotWidth);
  if (lotWidth() - numWidth * (spotLength + spotWidth > spotLength {
    numWidth++;
  }
  return  numLength * numWidth;
}
