#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include "type.h"
#include "parkingInfo.h"
#include "vehicle.h"
#include "parkingLotManager.h"
#include <iostream>
#include <unordered_map>

class ParkingSpot {
public:
  ParkingSpot() = default;
  ParkingSpot(int parkingFloorId, ParkingLotManager* plm, Type type) :
    _parkingLotManager(plm), _spotId(plm -> numParkingSpots()),
    _parkingFloorId(parkingFloorId), _type(type), _isOccupied(false), _vehicleId(-1) {
      plm.addParkingSpot(this);

      std::unordered_map<Type, ParkingInfo> availableMap = plm -> getAvailableMap();
      if (avalibleMap.count(type) == 0) {
        ParkingInfo parkingInfo(type);
        parkingInfo.setSpotsMap(parkingFloorId, plm -> numParkingSpots() - 1);
        avalibleMap[type] = parkingInfo;
      } else {
        ParkingInfo &parkingInfo = availableMap[type];
        parkingInfo.setSpotsmap(parkingFloorId, plm -> numParkingSpots() - 1);
      }

      std::vector<ParkingFloor*> parkingFloors = plm -> getParkingFloors();
      parkingFloors[parkingFloorId] -> setParkingSpotsIds(spotId);
    }
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
