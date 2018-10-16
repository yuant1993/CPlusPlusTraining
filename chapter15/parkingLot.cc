#include "singleLevelParkingLot.h"
#include "multiLevelParkingLot.h"
#include <iostream>

using namespace std;

void SingleLevelParkingLot::addParkingFloor(ParkingFloor *pf) {
  if (isFullFloors()) {
    cerr << "The single level parking lot already has a parking floor." << endl;
    exit(1);
  }
  if (pf -> getParkingLot()) {
    cerr << "The parking floor is attached to another parking lot." << endl;
    exit(1);
  }
  parkingFloor = pf;
  parkingFloor -> setParkingLot(this);
  fullFloors = true;
}

void MultiLevelParkingLot::addParkingFloor(ParkingFloor *pf) {
  if (isFullFloors()) {
    cerr << "The multi-level parking lot already has enough floors." << endl;
    exit(1);
  }
  if (pf -> getParkingLot()) {
    cerr << "The parking floor is attached to another parking lot." << endl;
    exit(1);
  }
  parkingFloors.push_back(pf);
  pf -> setParkingLot(this);
  if(parkingFloors.size() >= numFloor) {
    fullFloors = true;
  }
}
