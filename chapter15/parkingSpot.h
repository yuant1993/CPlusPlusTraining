#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include "vehicle.h"
#include <iostream>

class ParkingSpot {
  friend void ParkingFloor::addParkingSpot(ParkingSpot *ps);
public:
  PakringSpot() = delete;
  PakringSpot(int id): pakringSpotId(id), taken(false) {}
  int getParkingSpotId() const {return parkingSpotId;}
  PakringFloor *getParkingFloor() const {return parkingFloor;}
  Vehicle *getVehicle() const {return vehicle;}
  void setVehicle(Vehicle *v) {vehicle = v;}
private:
  int parkingSpotId;
  PakringFloor *parkingFloor;
  Vehicle *vehicle;
};

#endif
