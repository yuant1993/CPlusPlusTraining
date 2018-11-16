#ifndef PARKINGLOTMANAGER_H
#define PARKINGLOTMANAGER_H

#include "type.h"
#include "parkingFloor.h"
#include "parkingSpot.h"
#include "vehicle.h"
#include <iostream>
#include <vector>
#include <unordered_map>

class ParkingLotManager {
public:
  ParkingLotManager() = default;
  ParkingLotManager(std::string name) : _name(name) {}
  std::vector<ParkingFloor*> getParkingFloors() const {return _parkingFloors;}
  std::vector<ParkingSpot*> getParkingSpots() const {return _parkingSpots;}
  int numParkingFloors() const {return _parkingFloors.size();}
  int numParkingSpots() const {return _parkingSpots.size();}
  void addParkingFloor(ParkingFloor* pf) {_parkingFloors.push_back(pf);}
  void addParkingSpot(ParkingSpot* ps) {_parkingSpots.push_back(ps);}
  void addVehicle(Vehicle* v) {
    _vehicles.push_back(v);
    _vehicleMap[v -> getLisenceId()] = _vehicles.size() - 1;
  }
  std::unordered_map<Type, ParkingInfo> getAvailableMap() const {return _availableMap;}
  void setAvailableMap(Type type, ParkingInfo parkingInfo) {_availableMap[type] = parkingInfo;}
private:
  std::string _name;
  std::vector<ParkingFloor*> _parkingFloors;
  std::vector<ParkingSpot*> _parkingSpots;
  std::vector<Vehicle*> _vehicles;
  std::unordered_map<std::string, int> _vehicleMap;
  std::unordered_map<Type, ParkingInfo> _availableMap;
};

#endif
