#ifndef PARKINGFLOOR_H
#define PARKINGFLOOR_H

#include "parkingLotManager.h"
#include <iostream>
#include <vector>

class ParkingFloor {
public:
  ParkingFloor() = default;
  ParkingFloor(ParkingLotManager* plm) : _parkingLotManager(plm), _floorId(plm -> numParkingFloors()) {
    plm -> addParkingFloor(this);
  }
  void setParkingSpotsIds(spotId) {_parkingSpotsIds.push_back(spotId);}
private:
  ParkingLotManager* _parkingLotManager;
  int _floorId;
  std::vector<int> _parkingSpotsIds;
  std::vector<int> _untakenSpotsIds;
};

#endif
