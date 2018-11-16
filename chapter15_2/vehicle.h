#ifndef VEHICLE_H
#define VEHICLE_H

#include "parkingDetail.h"
#include "type.h"
#include <iostream>

class Vehicle {
public:
  Vehicle() = default;
  Vehicle(std::string lisence, Type type) : _lisenceId(lisence), _type(type) {}
  std::string getLisenceId() const {return _lisenceId;}
  Type getType() const {return _type;}
  ParkingDetail getParkingDetail() const {return _parkingDetail;}
  void setParkingDetail(ParkingDetail pd) {_parkingDetail = pd;}
private:
  std::string _lisenceId;
  Type _type;
  ParkingDetail _parkingDetail;
};

#endif
