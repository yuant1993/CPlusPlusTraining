#include "parkingLotManager.h"
#include <iostream>

using namespace std;

ParkingSpot::ParkingSpot(int parkingFloorId, ParkingLotManager* plm, Type type) :
  _parkingLotManager(plm), _spotId(plm -> numParkingSpots()),
  _parkingFloorId(parkingFloorId), _type(type), _isOccupied(false), _vehicleId(-1) {
    plm -> addParkingSpot(this);

    std::unordered_map<Type, ParkingInfo> availableMap = plm -> getAvailableMap();
    if (availableMap.count(type) == 0) {
      ParkingInfo parkingInfo(type);
      parkingInfo.setSpotsMap(parkingFloorId, _spotId, true);
      plm -> setAvailableMap(type, parkingInfo, true);
    } else {
      ParkingInfo parkingInfo = availableMap[type];
      parkingInfo.setSpotsMap(parkingFloorId, _spotId, true);
      plm -> setAvailableMap(type, parkingInfo, true);
    }

    std::vector<ParkingFloor*> parkingFloors = plm -> getParkingFloors();
    parkingFloors[parkingFloorId] -> addParkingSpotsIds(_spotId);
    // parkingFloors[parkingFloorId] -> addUntakenSpotsIds(_spotId);
  }
