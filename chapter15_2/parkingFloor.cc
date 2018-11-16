#include "parkingLotManager.h"
#include <iostream>

using namespace std;

ParkingFloor::ParkingFloor(ParkingLotManager* plm)
  : _parkingLotManager(plm), _floorId(plm -> numParkingFloors()) {
    plm -> addParkingFloor(this);
}
