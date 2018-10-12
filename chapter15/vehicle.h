#ifndef VEHICLE_H
#define VEHICLE_H

#include "parkingSpot.h"
#include <iostream>
#include <string>

class Vehicle {
public:
  Vehicle() = default;
  Vehicle(string p, double l, double w): plate(p), length(l), width(w) {}
  ParkingLot *getParkingSpot() const {return parkingSpot;}
  void park(SingleLevelParkingLot *pl);
  void park(MultiLevelParkingLot *pl);
private:
  std::string plate;
  double length;
  double width;
  ParkingSpot *parkingSpot;
};

#endif
