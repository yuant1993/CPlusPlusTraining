#ifndef FARECONTROLLER_H
#define FARECONTROLLER_H

#include "type.h"
#include "parkingDetail.h"
#include <iostream>
#include <unordered_map>

class FareController {
public:
  FareController() = default;
  FareController(ParkingDetail* pd) : _parkingDetail(pd) {}
  void setParkingDetail(ParkingDetail* pd) {_parkingDetail = pd;}
  double calculateTotalFare(Type type);
private:
  static std::unordered_map<Type, double> _fareMap;
  ParkingDetail* _parkingDetail;
};

#endif
