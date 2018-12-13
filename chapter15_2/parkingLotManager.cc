#include "parkingLotManager.h"
#include "fareController.h"

using namespace std;

int ParkingLotManager::addVehicle(Vehicle* v) {
  _vehicles.push_back(v);
  // _vehicleMap[v -> getLisenceId()] = _vehicles.size() - 1;
  setVehicleMap(v -> getLisenceId(), _vehicles.size() - 1, true);
  return _vehicles.size() - 1;
}

void ParkingLotManager::setVehicleMap(std::string lisenceId, int vehicleId, bool isAdd) {
  if (isAdd) {
    _vehicleMap[lisenceId] = vehicleId;
  } else {
    if (_vehicleMap.count(lisenceId) != 0) {
      _vehicleMap.erase(lisenceId);
    } else {
      cerr << "Lisence not found" << endl;
      return;
    }
  }
}

void ParkingLotManager::setAvailableMap(Type type, ParkingInfo parkingInfo, bool isAdd) {
  if (parkingInfo.getType() == type) {
    if (isAdd) {
      _availableMap[type] = parkingInfo;
    } else {
      if (_availableMap.count(type) != 0) {
        if (parkingInfo.getSpotsMap().empty()) {
          _availableMap.erase(type);
        } else {
          _availableMap[type] = parkingInfo;
        }
      } else {
        cerr << "No such type found." << endl;
        return;
      }
    }
  } else {
    cerr << "Type not match." << endl;
    return;
  }
}

void ParkingLotManager::parkHelper(Vehicle *v, Type type) {
  auto parkingInfo = _availableMap[type];
  auto spotsMap = parkingInfo.getSpotsMap();
  auto itr = spotsMap.begin();
  int spotId = *(itr -> second.begin());
  parkingInfo.setSpotsMap(itr -> first, spotId, false);
  ParkingDetail parkingDetail(spotId);
  v -> setParkingDetail(parkingDetail);
  int vehicleId = addVehicle(v);
  _parkingSpots[spotId] -> setVehicleId(vehicleId);
  _parkingSpots[spotId] -> setOccupied(true);
}

void ParkingLotManager::park(Vehicle *v) {
  auto availableMap = getAvailableMap();
  Type vehicleType = v -> getType();
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

double ParkingLotManager::unpark(string lisenceId) {
  if (_vehicleMap.count(lisenceId) != 0) {
    int vehicleId = _vehicleMap[lisenceId];
    auto parkingDetail = _vehicles[vehicleId] -> getParkingDetail();
    FareController fareController(&parkingDetail);
    int spotId = parkingDetail.getSpotId();
    int floorId = _parkingSpots[spotId] -> getFloorId();
    _vehicles[vehicleId] -> setParkingDetail(ParkingDetail());
    Type type = _vehicles[vehicleId] -> getType();
    auto parkingInfo = _availableMap[type];
    parkingInfo.setSpotsMap(floorId, spotId, false);
    setAvailableMap(type, parkingInfo, false);
    setVehicleMap(lisenceId, vehicleId, false);
    _vehicles.erase(_vehicles.begin() + vehicleId);

    return fareController.calculateTotalFare(_vehicles[vehicleId] -> getType());
  } else {
    cerr << "Lisence not found." << endl;
    return -1;
  }
}
