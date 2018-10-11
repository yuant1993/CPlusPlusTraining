#ifndef PARKING_H
#define PARKING_H

#include "parkingLot.h"
#include <iostream>
#include <vector>

class Parking {
public:
  Parking() = default;
  Parking(double l, double w): length(l), width(w), full(false) {}
  double getLength() const {return length;}
  double getWidth() const {return width;}
  bool isFull() const {return full;}
private:
  double length;
  double width;
  bool full;
};

class SingleParking: public Parking {
public:
  SingleParking() = default;
  SingleParking(double l, double w): Parking(l, w) {}
  SingleParking(double l, double w, ParkingLot *pl): Pakring(l, w), parkingLot(pl) {}
  ParkingLot *getParkingLot() {return parkingLot;}
private:
  PakringLot* parkingLot;
};

class MultiLevelParking: public Parking {
public:
  MultiLevelParking() = default;
  MultiLevelParking(double l, double w, int f): Parking(l, w), floorNum(f), parkingLots(f) {}
  MultiLevelParking(double l, double w, int f, vector<ParkingLot*> vec) : Parking(l, w), floorNum(f), parkingLots(vec) {}
  int getFloorNum() {return floorNum;}
  std::vector<ParkingLot*> getParkingLots() {return parkingLots;}
private:
  int floorNum;
  std::vector<ParkingLot*> parkingLots;
};

#endif
