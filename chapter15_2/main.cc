#include "parkingLotManager.h"
#include "parkingFloor.h"
#include "parkingSpot.h"
#include <iostream>

using namespace std;

int main() {
  ParkingLotManager plm("The First ParkingLot");
  ParkingFloor pf1(&plm);
  cout << "number of plm's parking floors: " << plm.numParkingFloors() << endl;
}
