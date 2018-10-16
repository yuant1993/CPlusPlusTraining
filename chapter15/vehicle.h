#ifndef VEHICLE_H
#define VEHICLE_H

#include "singleLevelParkingLot.h"
#include "multiLevelParkingLot.h"
#include "parkingSpot.h"
#include <iostream>
#include <string>

using namespace std;

class Vehicle {
public:
  Vehicle() = default;
  Vehicle(string p, double l, double w): plate(p), length(l), width(w) {}
  ParkingSpot *getParkingSpot() const {return parkingSpot;}
  void park(SingleLevelParkingLot *pl);
  void park(MultiLevelParkingLot *pl);
  void unPark();
private:
  std::string plate;
  double length;
  double width;
  ParkingSpot *parkingSpot;
};

#endif
