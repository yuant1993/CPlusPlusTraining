#include "vehicle.h"
#include <iostream>

using namespace std;

void Vehicle::park(SingleLevelParkingLot *pl) {
  if (pl -> isFullVehicles()) {
    cerr << "The parking lot is full." << endl;
  }
  ParkingFloor *pf = pl -> getParkingFloor();
  if (pf -> getSpotLength() - pf -> space >= length && pf -> getSpotWidth() - pf -> space >= width) {
    queue<ParkingSpot*> uts = pf -> untakenSpots();
    parkingSpot = uts.front();
    parkingSpot.parkVehicle(this);
    uts.pop();
    if (uts.empty()) {
      pf -> fullVehicles = true;
      pl -> fullVehicles = true;
    }
  } else {
    cerr << "No parking spot available." << endl;
  }
}

void Vehicle::park(MultiLevelParkingLot *pl) {
  if (pl -> isFullVehicles()) {
    cerr << "The parking lot is full." << endl;
  }
  Vector<ParkingFloor*> pfs = pl -> getParkingFloors();
  sort(pfs.begin(), pfs.end(), [](const ParkingFloor *pf1, const ParkingFloor *pf2) -> bool {
    return pf1.getSpotLength() == pf2.getSpotLength() ? pf1.getSpotWidth() < pf2.getSpotWidth() : pf1.getSpotLength() < pf2.getSpotLength();
  });
  for (auto itr = pfs.begin(); itr != pfs.end(); ++itr) {
    if (*itr -> isFullVehicles()) {
      continue;
    }
    if (*itr -> getSpotLength() - *itr -> space >= length && *itr -> getSpotWidth() - *itr -> space >= width) {
      queue<ParkingSpot*> uts = *itr -> untakenSpots();
      parkingSpot = uts.front();
      parkingSpot.parkVehicle(this);
      uts.pop();
      if (uts.empty()) {
        pf -> fullVehicles = true;
        pf -> numAvailableFloors--;
        if (pf -> numAvailableFloors == 0) {
          pl -> fullVehicles = true;
        }
      }
    }
  }
}
