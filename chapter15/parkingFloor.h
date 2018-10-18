#ifndef PARKINGFLOOR_H
#define PARKINGFLOOR_H

#include "parkingSpot.h"
#include <iostream>
#include <vector>
#include <queue>

class ParkingLot;

class ParkingFloor {
public:
  ParkingFloor() = delete;
  ParkingFloor(int fId, double spotl, double spotw, double f):
    floorId(fId), spotLength(spotl), spotWidth(spotw), fare(f), parkingLot(nullptr), fullSpots(false), fullVehicles(false) {}
  ParkingFloor(const ParkingFloor&);
  ParkingFloor &operator=(const ParkingFloor&);
  static double space;
  double getFloorId() const {return floorId;}
  double getSpotLength() const {return spotLength;}
  double getSpotWidth() const {return spotWidth;}
  double getFare() const {return fare;}
  std::vector<ParkingSpot*> getParkingSpots() const {return parkingSpots;}
  std::queue<ParkingSpot*> getUntakenSpots() const {return untakenSpots;}
  void pushUntakenSpots(ParkingSpot *ps) {untakenSpots.push(ps);}
  void popUntakenSpots() {untakenSpots.pop();}
  void addParkingSpot(ParkingSpot *ps);
  ParkingLot *getParkingLot() const {return parkingLot;}
  void setParkingLot(ParkingLot *pl) {parkingLot = pl;}
  int getNumTaken() const {return parkingSpots.size() - untakenSpots.size();}
  bool isFullSpots() const {return fullSpots;}
  bool isFullVehicles() const {return fullVehicles;}
  void setFullVehicles() {fullVehicles = true;}
  void unsetFullVehicles() {fullVehicles = false;}
  int capacity() const;
private:
  int floorId;
  double spotLength;
  double spotWidth;
  double fare;
  std::vector<ParkingSpot*> parkingSpots;
  std::queue<ParkingSpot*> untakenSpots;
  ParkingLot *parkingLot;
  bool fullSpots;
  bool fullVehicles;
};

#endif
