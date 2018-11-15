#ifndef PARKINGINFO_H
#define PARKINGINFO_H

#include "type.h"
#include <iostream>
#include <unordered_map>
#include <vector>

class ParkingInfo {
public:
  ParkingInfo(Type type) : _type(type) {}
  Type getType() const {return _type;}
  auto getSpotsMap() const {return _spotsMap;}
  void setSpotsMap(int floorId, int spotId) {
    _spotsMap[floorId].push_back(spotId);
  };
private:
  Type _type;
  std::unordered_map<int, std::vector<int>> _spotsMap;
};

#endif
