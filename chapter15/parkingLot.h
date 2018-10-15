#ifndef ParkingLot_H
#define ParkingLot_H

#include "parkingFloor.h"
#include <iostream>
#include <vector>

class ParkingLot {
  friend void Vehicle::park(SingleLevelParkingLot *pl);
public:
  ParkingLot() = delete;
  ParkingLot(double l, double w): length(l), width(w), full(false) {}
  ParkingLot(const ParkingLot &);
  ParkingLot &operator=(const ParkingLot &);
  virtual ~ParkingLot();
  double getLength() const {return length;}
  double getWidth() const {return width;}
  bool isFullFloors() const {return fullFloors;}
  bool isFullVehicles() const {return fullVehicles;}
  virtual void addParkingFloor(ParkingFloor *pf) = 0;
private:
  double length;
  double width;
  bool fullFloors;
  bool fullVehicles;
};

class SingleLevelParkingLot: public ParkingLot {
public:
  SingleLevelParkingLot() = delete;
  SingleLevelParkingLot(double l, double w): ParkingLot(l, w) {}
  SingleLevelParkingLot(const SingleLevelParkingLot&);
  SingleLevelParkingLot &operator=(const SingleLevelParkingLot&);
  ParkingFloor *getParkingFloor() {return parkingFloor;}
  void addParkingFloor(ParkingFloor *pf);
private:
  ParkingFloor *parkingFloor;
};

class MultiLevelParkingLot: public ParkingLot {
public:
  MultiLevelParkingLot() = delete;
  MultiLevelParkingLot(double l, double w, int f): ParkingLot(l, w), numFloor(f), numAvailableFloors(f) {}
  MultiLevelParkingLot(const MultiLevelParkingLot&);
  MultiLevelParkingLot &operator=(const MultiLevelParkingLot&);
  int getnumFloor() {return numFloor;}
  std::vector<ParkingFloor*> getParkingFloors() {return parkingFloors;}
  void addParkingFloor(ParkingFloor *pf);
private:
  int numFloor;
  int numAvailableFloors;
  std::vector<ParkingFloor*> parkingFloors;
};

#endif
