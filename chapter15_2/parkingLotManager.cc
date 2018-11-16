#include "parkingLotManager.h"

using namespace std;

void ParkingLotManager::parkHelper(Vehicle &v, Type &type) {
  auto parkingInfo = _availableMap[type];
  auto spotsMap = parkingInfo -> getSpotsMap();
  auto itr = spotsMap.begin();
  int spotId = itr -> second.back();
  ParkingDetail parkingDetail(spotId);
  v.setParkingDetail(parkingDetail);
  addVehicle(&v);
  _parkingSpots[spotId] -> setVehicleId(v.getLisenceId());
  _parkingSpots[spotId] -> setOccupied(true);
  parkingInfo -> setSpotsMap(itr -> first, spotId, false);
}

void ParkingLotManager::park(Vehicle v) {
  auto availableMap = getAvailableMap();
  Type vehicleType = v.getType();
  if (vehicleType == Type::SMALL) {
    if (!availableMap.empty()) {
      if (availableMap.count(vehicleType) != 0) {
        parkHelper(v, vehicleType);
      } else if (availableMap.count(Type::MEDIUM)) {
        parkHelper(v, Type::MEDIUM);
      } else {
        parkHelper(v, Type::LARGE);
      }
    } else {
      cerr << "No available space." << endl;
      return;
    }
  } else if (vehicleType == Type::MEDIUM) {
    if (availableMap.count(vehicleType) != 0 || availableMap.count(Type::LARGE) != 0) {
      if (availableMap.count(vehicleType) != 0) {
        parkHelper(v, vehicleType);
      } else {
        parkHelper(v, Type::LARGE);
      }
    } else {
      cerr << "No available space." << endl;
      return;
    }
  } else {
    if (availableMap.count(vehicleType) != 0) {
      parkHelper(v, vehicleType);
    } else {
      cerr << "No available space." << endl;
      return;
    }
  }
}

void ParkingLotManager::unpark(Vehicle v) {}
