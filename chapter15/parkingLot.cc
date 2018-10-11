#include "parkingLot.h"
#include <iostream>

using namespace std;

int ParkingLot::capacity() {
  int numLength = (int)(lotLength() / spotWidth;
  int numWidth = (int)(lotWidth() / (spotLength + spotWidth);
  if (lotWidth() - numWidth * (spotLength + spotWidth > spotLength {
    numWidth++;
  }
  return  numLength * numWidth;
}
