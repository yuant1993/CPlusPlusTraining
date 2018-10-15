#ifndef PAKRINGFLOOR_H
#define PARKINGFLOOR_H

#include "parkingSpot.h"
#include "parkingLot.h"
#include "vehicle.h"
#include <iostream>

class ParkingFloor {
  friend void ParkingLot::addParkingFloor(ParkingFloor *pf);
  friend void Vehicle::park(SingleLevelParkingLot *pl);
  friend void Vehicle::unPark();
public:
  ParkingFloor() = delete;
  ParkingFloor(int fId, double spotl, double spotw, double spacel, double spacew):
    floorId(fId), spotLength(spotl), spotWidth(spotw), spaceLength(spacel), spaceWidth(spacew), numTaken(0), full(false) {}
  ParkingFloor(const ParkingFloor&);
  ParkingFloor &operator=(const ParkingFloor&);
  static double space;
  double getSpotLength() const {return spotLength;}
  double getSpotWidth() const {return spotWidth;}
  std::vector<PakringSpot*> getParkingSpots() const {return parkingSpots;}
  std::queue<ParkingSpot*> getUntakenSpots() const {return untakenSpots;}
  void addParkingSpot(ParkingSpot *ps);
  ParkingLot *getParkingLot() const {return parkingLot;}
  int getNumTaken() const {return parkingSpots.size() - untakenSpots();}
  bool isFullSpots() const {return fullSpots;}
  bool isFullVehicles() const {return fullVehicles;}
  int capacity() const;
private:
  int floorId;
  double spotLength;
  double spotWidth;
  std::vector<ParkingSpot*> parkingSpots;
  std::queue<ParkingSpot*> untakenSpots;
  ParkingLot *parkingLot;
  bool fullSpots;
  bool fullVehicles;
};

#endif
