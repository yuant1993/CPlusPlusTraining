#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include "vehicle.h"
#include <iostream>

class ParkingSpot {
public:
  PakringSpot() = delete;
  PakringSpot(int id, PakringLot *pl): pakringSpotId(id), parkingLot(pl), taken(false) {}
  PakringSpot(int id, PakringLot *pl, Vehicle *v): pakringSpotId(id), parkingLot(pl), vehicle(v), taken(false) {}
  int getParkingSpotId() const {return parkingSpotId;}
  PakringLot *getParkingLot() const {return parkingLot;}
  Vehicle *getVehicle() const {return vehicle;}
  void parkVehicle(Vehicle *v) {vehicle = v;}
  bool isTaken() const {return taken;}
  void setTaken() {taken = true;}
private:
  int parkingSpotId;
  PakringLot *parkingLot;
  Vehicle *vehicle;
  bool taken;
};

#endif
