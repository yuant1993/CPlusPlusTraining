#include "parkingInfo.h"

using namespace std;

void ParkingInfo::setSpotsMap(int floorId, int spotId, bool isAdd) {
  if (isAdd) {
    _spotsMap[floorId].insert(spotId);
  } else {
    if (_spotsMap.count(floorId) != 0) {
      if (_spotsMap[floorId].find(spotId) != _spotsMap[floorId].end()) {
        _spotsMap[floorId].erase(spotId);
        if (_spotsMap[floorId].empty()) {
          _spotsMap.erase(floorId);
        }
      } else {
        cerr << "No such spot found." << endl;
        return;
      }
    } else {
      cerr << "No such floor found." << endl;
      return;
    }
  }
}
