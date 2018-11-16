#ifndef PARKINGFLOOR_H
#define PARKINGFLOOR_H

// #include "parkingLotManager.h"
#include <iostream>
#include <vector>

class ParkingLotManager;

class ParkingFloor {
public:
  ParkingFloor() = default;
  ParkingFloor(ParkingLotManager* plm);
  ParkingLotManager* getParkingLot() const {return _parkingLotManager;}
  int getFloorId() const {return _floorId;}
  std::vector<int> getParkingSpotsIds() const {return _parkingSpotsIds;}
  int numParkingSpots() const {return _parkingSpotsIds.size();}
  std::vector<int> getUntakenSpotsIds() const {return _untakenSpotsIds;}
  int numUntakenSpots() const {return _untakenSpotsIds.size();}
  void addParkingSpotsIds(int spotId) {_parkingSpotsIds.push_back(spotId);}
  void addUntakenSpotsIds(int spotId) {_untakenSpotsIds.push_back(spotId);}
private:
  ParkingLotManager* _parkingLotManager;
  int _floorId;
  std::vector<int> _parkingSpotsIds;
  std::vector<int> _untakenSpotsIds;
};

#endif
