#ifndef VEHICLE_H
#define VEHICLE_H

#include "singleLevelParkingLot.h"
#include "multiLevelParkingLot.h"
#include "parkingSpot.h"
#include "parkingTime.h"
#include <iostream>
#include <string>

class Vehicle {
public:
  Vehicle() = default;
  Vehicle(std::string p, double l, double w, ParkingTime *pt): plate(p), length(l), width(w), parkingSpot(nullptr), parkingTime(pt) {}
  std::string getPlate() const {return plate;}
  double getLength() const {return length;}
  double getWidth() const {return width;}
  ParkingSpot *getParkingSpot() const {return parkingSpot;}
  void setParkingSpot(ParkingSpot *ps) {parkingSpot = ps;}
  ParkingTime *getParkingTime() const {return parkingTime;}
  double getTotalFare() const {return totalFare;}
  void setTotalFareToZero() {totalFare = 0;}
  void calculateTotalFare();
  void park(SingleLevelParkingLot *pl);
  void park(MultiLevelParkingLot *pl);
  void unpark();
private:
  std::string plate;
  double length;
  double width;
  ParkingSpot *parkingSpot;
  ParkingTime *parkingTime;
  double totalFare;
};

#endif
