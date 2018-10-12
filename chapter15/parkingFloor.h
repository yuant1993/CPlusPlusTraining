#ifndef PAKRINGFLOOR_H
#define PARKINGFLOOR_H

#include "parkingSpot.h"
#include <iostream>

class ParkingFloor {
  friend Vehicle;
public:
  ParkingFloor() = delete;
  ParkingFloor(int fId, double spotl, double spotw, double spacel, double spacew):
    floorId(fId), spotLength(spotl), spotWidth(spotw), spaceLength(spacel), spaceWidth(spacew), numTaken(0), full(false) {}
  ParkingFloor(const ParkingFloor&);
  ParkingFloor &operator=(const ParkingFloor&);
  double getSpotLength() const {return spotLength;}
  double getSpotWidth() const {return spotWidth;}
  double getSpaceLength() const {return spaceLength;}
  double getSpaceWidth() const {return spaceWidth;}
  std::vector<PakringSpot*> getParkingSpots() const {return parkingSpots;}
  void setParkingSpots(ParkingSpot *ps) {
    parkingSpots.push_back(ps);
    untakenSpots.push(ps);
  }
  std::queue getUntakenSpots() const {return untakenSpots;}
  int getNumTaken() const {return numTaken;}
  void setNumTaken();
  bool isFull() const {return full;}
  void setFull() {full = true;}
  int capacity() const;
private:
  int floorId;
  double spotLength;
  double spotWidth;
  double spaceLength;
  double spaceWidth;
  std::vector<ParkingSpot*> parkingSpots;
  std::queue<ParkingSpot*> untakenSpots;
  ParkingLot *parkingLot;
  int numTaken;
  bool full;
};

#endif
