#ifndef PARKINGFARE_H
#define PARKINGFARE_H

#include <iostream>
#include <chrono>

class ParkingTime {
public:
  ParkingTime() = default;
  auto getStart() const {return start;}
  void setStart() {start = std::chrono::system_clock::now();}
  auto getEnd() const {return end;}
  void setEnd() {end = std::chrono::system_clock::now();}
  double getTime() const {
    std::chrono::duration<double> diff = end - start;
    return diff.count();
  }
private:
  std::chrono::system_clock::time_point start;
  std::chrono::system_clock::time_point end;
};

#endif
