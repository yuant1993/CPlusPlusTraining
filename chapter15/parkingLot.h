#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "parkingFloor.h"
#include <iostream>

class ParkingLot {
public:
  ParkingLot() = delete;
  ParkingLot(double l, double w): length(l), width(w), fullFloors(false), fullVehicles(false) {}
  ParkingLot(const ParkingLot &);
  ParkingLot &operator=(const ParkingLot &);
  virtual ~ParkingLot() = default;
  double getLength() const {return length;}
  double getWidth() const {return width;}
  bool isFullFloors() const {return fullFloors;}
  bool isFullVehicles() const {return fullVehicles;}
  void setFullVehicles() {fullVehicles = true;}
  void unsetFullVehicles() {fullVehicles = false;}
  virtual void addParkingFloor(ParkingFloor *pf) = 0;
private:
  double length;
  double width;
  bool fullVehicles;
protected:
  bool fullFloors;
};

#endif
