#ifndef PAKRINGLOT_H
#define PARKINGLOT_H

#include "parkingSpot.h"
#include <iostream>

class ParkingLot {
public:
  ParkingLot() = default;
  ParkingLot(int fId, double spotl, double spotw, double spacel, double spacew):
    floorId(fId), spotLength(spotl), spotWidth(spotw), spaceLength(spacel), spaceWidth(spacew), full(false) {}
  ParkingLot(int fId,  double spotl, double spotw, double spacel, double spacew, vector<PakringSpot*> ps, Parking *p):
    floorId(fId), spotLength(spotl), spotWidth(spotw), spaceLength(spacel), spaceWidth(spacew), pakringSpots(ps), parkingLot(p), full(false) {}
  double getSpotLength() const {return spotLength;}
  double getSpotWidth() const {return spotWidth;}
  double getSpaceLength() const {return spaceLength;}
  double getSpaceWidth() const {return spaceWidth;}
  bool isFull() const {return full;}
  int capacity() const;
private:
  int floorId;
  double spotLength;
  double spotWidth;
  double spaceLength;
  double spaceWidth;
  vector<ParkingSpot*> parkingSpots;
  Parking *parking;
  bool full;
};



#endif
