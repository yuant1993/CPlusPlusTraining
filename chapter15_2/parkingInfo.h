#ifndef PARKINGINFO_H
#define PARKINGINFO_H

#include "type.h"
#include <iostream>
#include <map>
#include <vector>

class ParkingInfo {
public:
  ParkingInfo() = default;
  ParkingInfo(Type type) : _type(type) {}
  Type getType() const {return _type;}
  auto getSpotsMap() const {return _spotsMap;}
  void setSpotsMap(int floorId, int spotId, bool isAdd) {
    if (isAdd) {
      _spotsMap[floorId].push_back(spotId);
    } else {
      _spotsMap[floorId].pop_back();
    }
  };
private:
  Type _type;
  std::map<int, std::vector<int>> _spotsMap;
};

#endif
