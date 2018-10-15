#include "parkingFloor.h"
#include <iostream>

using namespace std;

void ParkingFloor::addParkingSpot(ParkingSpot *ps) {
  if (isFullSpots()) {
    cerr << "The parking floor is full."
  }
  parkingSpots.push_back(ps);
  untakenSpots.push(ps);
  ps -> parkingFloor = this;
  if (parkingSpots.size() >= capacity()) {
    fullSpots = true;
  }
}

int ParkingFloor::capacity() {
  if (!parkingLot) {
    cerr << "The parking floor doesn't belong to any parking lot."
  }
  int numLength = (int)(parkingLot -> getLength() / spotWidth);
  int numWidth = (int)(parkingLot -> getWidth() / (spotLength + spotWidth));
  if (parkingLot -> getWidth() - numWidth * (spotLength + spotWidth) > spotLength {
    numWidth++;
  }
  return  numLength * numWidth;
}
