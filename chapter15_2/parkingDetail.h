#ifndef PARKINGDETAIL_H
#define PARKINGDETAIL_H

#include <iostream>
#include <chrono>

class ParkingDetail {
public:
private:
  std::chrono::system_clock::time_point _startTime;
  std::chrono::system_clock::time_point _endTime;
  int _spotId;
};

#endif
