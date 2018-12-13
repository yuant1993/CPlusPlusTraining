#include "FareController.h"

using namespace std;

unordered_map<Type, double> FareController::_fareMap = {
  {Type::SMALL, 3.5},
  {Type::MEDIUM, 4.5},
  {Type::LARGE, 5.5}
};

double FareController::calculateTotalFare(Type type) {
  std::chrono::duration<double> diff = _parkingDetail -> getEndTime() - _parkingDetail -> getStartTime();
  return _fareMap[type] * diff.count();
}
