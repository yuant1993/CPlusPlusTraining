#include "parkingLot.h"
#include <iostream>

using namespace std;

void SingleLevelParkingLot::addParkingFloor(ParkingFloor *pf) {
  if (isFullFloors()) {
    cerr << "The single level parking lot already has a parking floor."
  }
  parkingFloor = pf;
  parkingFloor -> parkingLot = this;
  fullFloors = true;
}

void MultiLevelParkingLot::addParkingFloor(ParkingFloor *pf) {
  if (isFullFloors()) {
    cerr << "The multi-level parking lot already has enough floors."
  }
  parkingFloors.push_back(pf);
  pf -> parkingLot = this;
  if(parkingFloors.size() >= numFloor) {
    fullFloors = true;
  }
}
