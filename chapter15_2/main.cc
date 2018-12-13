#include "parkingLotManager.h"
#include "parkingFloor.h"
#include "parkingSpot.h"
#include "type.h"
#include "vehicle.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ParkingLotManager plm("The First ParkingLot");
  ParkingFloor pf0(&plm);
  cout << "number of plm's parking floors: " << plm.numParkingFloors() << endl;
  ParkingSpot ps0(pf0.getFloorId(), &plm, Type::MEDIUM);
  ParkingSpot ps1(pf0.getFloorId(), &plm, Type::SMALL);
  cout << "number of plm's parking spots: " << plm.numParkingSpots() << endl;
  cout << "number of pf1's parking spots: " << pf0.numParkingSpots() << endl;
  // cout << "number of pf1's untaken parking spots: " << pf0.numUntakenSpots() << endl;
  auto availableMap = plm.getAvailableMap();
  cout << "availableMap size: " << availableMap.size() << endl;
  for (auto itr = availableMap.begin(); itr != availableMap.end(); ++itr) {
    if (itr -> first == Type::LARGE) {
      cout << "type: Large ";
    } else if (itr -> first == Type::MEDIUM) {
      cout << "type: MEDIUM ";
    } else {
      cout << "type: SMALL ";
    }
    auto parkingInfo = itr -> second;
    auto spotsMap = parkingInfo.getSpotsMap();
    for (auto itr1 = spotsMap.begin(); itr1 != spotsMap.end(); ++itr1) {
      cout << "floor: " << itr1 -> first;

      auto spots = itr1 -> second;
      cout << " spots: ";
      for (auto itr2 = spots.begin(); itr2 != spots.end(); ++itr2) {
        cout << *itr2 << " ";
      }

      cout << endl;
    }
  }
  Vehicle v1("aaaaa", Type::SMALL);
  plm.park(&v1);
  cout << "After Parking:" << endl;
  cout << "v1's spot: " << v1.getParkingDetail().getSpotId() << endl;
  cout << "vehicles's size: " << plm.numVehicles() << endl;
  plm.unpark("aaaaa");
  cout << endl;
  cout << "After Unparking:" << endl;
  cout << "v1's spot: " << v1.getParkingDetail().getSpotId() << endl;
  cout << "vehicles's size: " << plm.numVehicles() << endl;
}
