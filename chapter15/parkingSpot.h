#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

// #include "vehicle.h"
// #include "parkingFloor.h"
#include <iostream>

class ParkingFloor;

class ParkingSpot {
public:
  ParkingSpot() = delete;
  ParkingSpot(int id): parkingSpotId(id), parkingFloor(nullptr) {}
  int getParkingSpotId() const {return parkingSpotId;}
  ParkingFloor *getParkingFloor() const {return parkingFloor;}
  void setParkingFloor(ParkingFloor *pf) {parkingFloor = pf;}
  // Vehicle *getVehicle() const {return vehicle;}
  // void setVehicle(Vehicle *v) {vehicle = v;}
private:
  int parkingSpotId;
  ParkingFloor *parkingFloor;
  // Vehicle *vehicle;
};

#endif
