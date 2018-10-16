#ifndef SINGLELEVELPARKINGLOT_H
#define SINGLELEVELPARKINGLOT_H

#include "parkingLot.h"
#include <iostream>

class SingleLevelParkingLot: public ParkingLot {
public:
  SingleLevelParkingLot() = delete;
  SingleLevelParkingLot(double l, double w): ParkingLot(l, w), parkingFloor(nullptr) {}
  SingleLevelParkingLot(const SingleLevelParkingLot&);
  SingleLevelParkingLot &operator=(const SingleLevelParkingLot&);
  ~SingleLevelParkingLot() = default;
  ParkingFloor *getParkingFloor() {return parkingFloor;}
  void addParkingFloor(ParkingFloor *pf);
private:
  ParkingFloor *parkingFloor;
};

#endif
