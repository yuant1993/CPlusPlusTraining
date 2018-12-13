#ifndef PARKINGDETAIL_H
#define PARKINGDETAIL_H

#include <iostream>
#include <chrono>

class ParkingDetail {
public:
  ParkingDetail() : _spotId(-1) {}
  ParkingDetail(int spotId) : _spotId(spotId), _startTime(std::chrono::system_clock::now()) {}
  auto getStartTime() {return _startTime;}
  auto getEndTime() {
    _endTime = std::chrono::system_clock::now();
    return _endTime;
  }
  int getSpotId() const {return _spotId;}
private:
  std::chrono::system_clock::time_point _startTime;
  std::chrono::system_clock::time_point _endTime;
  int _spotId;
};

#endif
