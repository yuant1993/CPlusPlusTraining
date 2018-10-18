#include "vehicle.h"
#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <chrono>

using namespace std;

void Vehicle::park(SingleLevelParkingLot *pl) {
  if (pl -> isFullVehicles()) {
    cerr << "The parking lot is full." << endl;
  }
  ParkingFloor *pf = pl -> getParkingFloor();
  if (pf -> getSpotLength() - pf -> space >= length && pf -> getSpotWidth() - pf -> space >= width) {
    parkingSpot = pf -> getUntakenSpots().front();
    parkingSpot -> setVehicle(this);
    setParkingSpot(parkingSpot);
    parkingTime -> setStart();
    pf -> popUntakenSpots();
    if (pf -> getUntakenSpots().empty()) {
      pf -> setFullVehicles();
      pl -> setFullVehicles();
    }
  } else {
    cerr << "No parking spot available." << endl;
  }
}

void Vehicle::park(MultiLevelParkingLot *pl) {
  if (pl -> isFullVehicles()) {
    cerr << "The parking lot is full." << endl;
  }
  vector<ParkingFloor*> pfs = pl -> getParkingFloors();
  sort(pfs.begin(), pfs.end(), [](const ParkingFloor *pf1, const ParkingFloor *pf2) -> bool {
    return pf1 -> getSpotLength() == pf2 -> getSpotLength() ? pf1 -> getSpotWidth() < pf2 -> getSpotWidth() : pf1 -> getSpotLength() < pf2 -> getSpotLength();
  });
  for (auto itr = pfs.begin(); itr != pfs.end(); ++itr) {
    if ((*itr) -> isFullVehicles()) {
      continue;
    }
    if ((*itr) -> getSpotLength() - (*itr) -> space >= length && (*itr) -> getSpotWidth() - (*itr) -> space >= width) {
      parkingSpot = (*itr) -> getUntakenSpots().front();
      parkingSpot -> setVehicle(this);
      setParkingSpot(parkingSpot);
      parkingTime -> setStart();
      (*itr) -> popUntakenSpots();
      if ((*itr) -> getUntakenSpots().empty()) {
        (*itr) -> setFullVehicles();
        pl -> decreaseNumAvailableFloors();
        if (pl -> getNumAvailableFloors() == 0) {
          pl -> setFullVehicles();
        }
      }
      break;
    }
  }
}

void Vehicle::unpark() {
  parkingSpot -> setVehicle(nullptr);
  ParkingFloor *pf = parkingSpot -> getParkingFloor();
  pf -> pushUntakenSpots(parkingSpot);
  parkingTime -> setEnd();
  calculateTotalFare();
  parkingSpot = nullptr;
  if (pf -> isFullVehicles()) {
    pf -> unsetFullVehicles();
    ParkingLot *pl = pf -> getParkingLot();
    if (typeid(*pl).name() == "MultiLevelParkingLot") {
        MultiLevelParkingLot *mlpl = dynamic_cast<MultiLevelParkingLot*>(pl);
        mlpl -> increseNumAvailableFloors();
    }
    if (pl -> isFullVehicles()) {
      pl -> unsetFullVehicles();
    }
  }
};

void Vehicle::calculateTotalFare() {
  totalFare = (parkingSpot -> getParkingFloor() -> getFare()) * (parkingTime -> getTime());
}
