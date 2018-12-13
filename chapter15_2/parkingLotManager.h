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
  std::vector<Vehicle*> getVehicles() const {return _vehicles;}
  int numParkingFloors() const {return _parkingFloors.size();}
  int numParkingSpots() const {return _parkingSpots.size();}
  int numVehicles() const {return _vehicles.size();}
  void addParkingFloor(ParkingFloor* pf) {_parkingFloors.push_back(pf);}
  void addParkingSpot(ParkingSpot* ps) {_parkingSpots.push_back(ps);}
  int addVehicle(Vehicle* v);
  std::unordered_map<std::string, int> getVehicleMap() const {return _vehicleMap;}
  void setVehicleMap(std::string lisenceId, int vehicleId, bool isAdd);
  std::unordered_map<Type, ParkingInfo> getAvailableMap() const {return _availableMap;}
  void setAvailableMap(Type type, ParkingInfo parkingInfo, bool isAdd);
  void park(Vehicle *v);
  double unpark(std::string lisenceId);
private:
  std::string _name;
  std::vector<ParkingFloor*> _parkingFloors;
  std::vector<ParkingSpot*> _parkingSpots;
  std::vector<Vehicle*> _vehicles;
  std::unordered_map<std::string, int> _vehicleMap;
  std::unordered_map<Type, ParkingInfo> _availableMap;
  void parkHelper(Vehicle *v, Type type);
};

#endif
