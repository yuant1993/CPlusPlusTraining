#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include "type.h"
#include "parkingInfo.h"
#include "vehicle.h"
// #include "parkingLotManager.h"
#include <iostream>
#include <unordered_map>

class ParkingLotManager;

class ParkingSpot {
public:
  ParkingSpot() = default;
  ParkingSpot(int parkingFloorId, ParkingLotManager* plm, Type type);
  int getSpotId() const {return _spotId;}
private:
  ParkingLotManager* _parkingLotManager;
  int _spotId;
  int _parkingFloorId;
  Type _type;
  bool _isOccupied;
  int _vehicleId;
};

#endif
