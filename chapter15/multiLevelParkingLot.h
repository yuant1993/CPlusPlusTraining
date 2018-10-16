#ifndef MULTILEVELPARKINGLOT_H
#define MULTILEVELPARKINGLOT_H

#include "parkingLot.h"
#include <iostream>
#include <vector>

class MultiLevelParkingLot: public ParkingLot {
public:
  MultiLevelParkingLot() = delete;
  MultiLevelParkingLot(double l, double w, int f): ParkingLot(l, w), numFloor(f), numAvailableFloors(f) {}
  MultiLevelParkingLot(const MultiLevelParkingLot&);
  MultiLevelParkingLot &operator=(const MultiLevelParkingLot&);
  ~MultiLevelParkingLot() = default;
  int getNumFloor() const {return numFloor;}
  int getNumAvailableFloors() const {return numAvailableFloors;}
  void increseNumAvailableFloors() {numAvailableFloors++;}
  void decreaseNumAvailableFloors() {numAvailableFloors--;}
  std::vector<ParkingFloor*> getParkingFloors() {return parkingFloors;}
  void addParkingFloor(ParkingFloor *pf);
private:
  int numFloor;
  int numAvailableFloors;
  std::vector<ParkingFloor*> parkingFloors;
};

#endif
