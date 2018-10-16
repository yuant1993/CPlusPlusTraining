#include "parkingFloor.h"
#include "parkingLot.h"
#include <iostream>

using namespace std;

void ParkingFloor::addParkingSpot(ParkingSpot *ps) {
  if (isFullSpots()) {
    cerr << "The parking floor is full." << endl;
    exit(1);
  }
  if (ps -> getParkingFloor()) {
    cerr << "The parking spot is attached to the another parking floor." << endl;
    exit(1);
  }
  parkingSpots.push_back(ps);
  untakenSpots.push(ps);
  ps -> setParkingFloor(this);
  if (parkingSpots.size() >= capacity()) {
    fullSpots = true;
  }
}

int ParkingFloor::capacity() const {
  if (!parkingLot) {
    cerr << "The parking floor doesn't belong to any parking lot." << endl;
    exit(1);
  }
  int numLength = (int)(parkingLot -> getLength() / spotWidth);
  int numWidth = (int)(parkingLot -> getWidth() / (spotLength + spotWidth));
  if (parkingLot -> getWidth() - numWidth * (spotLength + spotWidth) > spotLength) {
    numWidth++;
  }
  return numLength * numWidth;
}
