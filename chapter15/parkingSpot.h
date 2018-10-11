#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include "vehicle.h"
#include <iostream>

class ParkingSpot {
public:
  PakringSpot() = default;
  PakringSpot(PakringLot *pl, Vehicle *v): parkingLot(pl), vehicle(v), taken(false) {}
  bool isTaken() const {return taken;}
  Vehicle *getVehicle() const {return vehicle;}
  void parkVehicle(Vehicle *v) {vehicle = v;}
private:
  PakringLot *parkingLot;
  Vehicle *vehicle;
  bool taken;
};

#endif
