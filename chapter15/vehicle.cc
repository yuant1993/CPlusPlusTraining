#include "vehicle.h"
#include <iostream>

using namespace std;

void Vehicle::park(SingleLevelParkingLot *pl) {
  if (pl -> isFull()) {
    cerr << "No parking spot available. Please go to another parking lot".
  }
  ParkingFloor *pf = pl -> getParkingFloor();
  if (pf -> getSpotLength() - pf -> getSpaceLength() >= length && pf -> getSpotWidt() - pf -> getSpaceWidth() >= width) {
    pl
  }
}



/*ParkingLot  = ps -> parkingLot;
if (pl -> getSpotLength() - pl -> getSpaceLength() >= l && pl -> getSpotWidth() - pl -> getSpaceWidth() >= w) {
  parkingSpot -> setTaken();
  parkingSpot -> parkVehicle(this);
  parkingSpot -> getParkingLot() -> setNumTaken();
} else {
  cerr << "The parking spot is too small for this vehicle."
}*/
