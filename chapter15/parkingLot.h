#ifndef ParkingLot_H
#define ParkingLot_H

#include "parkingFloor.h"
#include <iostream>
#include <vector>

class ParkingLot {
public:
  ParkingLot() = delete;
  ParkingLot(double l, double w): length(l), width(w), full(false) {}
  ParkingLot(const ParkingLot &);
  ParkingLot &operator=(const ParkingLot &);
  virtual ~ParkingLot();
  double getLength() const {return length;}
  double getWidth() const {return width;}
  bool isFull() const {return full;}
  void setFull() {return full = true;}
  virtual void setParkingFloor() = 0;
private:
  double length;
  double width;
  bool full;
};

class SingleLevelParkingLot: public ParkingLot {
public:
  SingleLevelParkingLot() = delete;
  SingleLevelParkingLot(double l, double w): ParkingLot(l, w) {}
  SingleLevelParkingLot(double l, double w, ParkingFloor *pf): ParkingLot(l, w), parkingFloor(pf) {}
  SingleLevelParkingLot(const SingleLevelParkingLot&);
  SingleLevelParkingLot &operator=(const SingleLevelParkingLot&);
  ParkingFloor *getParkingFloor() {return parkingFloor;}
  void setParkingFloor(ParkingFloor *pf) {parkingFloor = pf};
private:
  ParkingFloor *parkingFloor;
};

class MultiLevelParkingLot: public ParkingLot {
public:
  MultiLevelParkingLot() = delete;
  MultiLevelParkingLot(double l, double w, int f): ParkingLot(l, w), numFloor(f), ParkingLoLots(f) {}
  MultiLevelParkingLot(double l, double w, int f, vector<ParkingLotLot*> vec) : ParkingLot(l, w), numFloor(f), ParkingLotLots(vec) {}
  MultiLevelParkingLot(const MultiLevelParkingLot&);
  MultiLevelParkingLot &operator=(const MultiLevelParkingLot&);
  int getnumFloor() {return numFloor;}
  std::vector<ParkingFloor*> getParkingFloors() {return parkingFloors;}
  void setParkingFloor(ParkingFloor *pf) {parkingFloors.push_back(pf)};
private:
  int numFloor;
  std::vector<ParkingFloor*> parkingFloors;
};

#endif
