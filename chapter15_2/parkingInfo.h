#ifndef PARKINGINFO_H
#define PARKINGINFO_H

#include "type.h"
#include <iostream>
#include <map>
#include <unordered_set>

class ParkingInfo {
public:
  ParkingInfo() = default;
  ParkingInfo(Type type) : _type(type) {}
  Type getType() const {return _type;}
  auto getSpotsMap() const {return _spotsMap;}
  void setSpotsMap(int floorId, int spotId, bool isAdd);
private:
  Type _type;
  std::map<int, std::unordered_set<int>> _spotsMap;
};

#endif
