#include "singleLevelParkingLot.h"
#include "multiLevelParkingLot.h"
#include "parkingFloor.h"
#include "parkingSpot.h"
#include "vehicle.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

double ParkingFloor::space = 0.12;

int main() {
  // SingleLevelParkingLot spl(123.45, 67.89);
  // cout << spl.getLength() << ' ' << spl.getWidth() << endl;
  // ParkingFloor pf1(1, 3.45, 2.34, 5);
  // cout << pf1.getSpotLength() << ' ' << pf1.getSpotWidth() << ' ' << pf1.space << endl;
  // cout << pf1.getParkingLot() << ' ' << pf1.getFare() << endl;
  // ParkingSpot ps1(1);
  // ParkingSpot ps2(2);
  // cout << &ps1 << ' ' << &ps2 << endl;
  // spl.addParkingFloor(&pf1);
  // cout << pf1.getParkingLot() << endl;
  // cout << spl.getParkingFloor() -> getSpotWidth() << endl;
  // pf1.addParkingSpot(&ps1);
  // pf1.addParkingSpot(&ps2);
  // cout << pf1.getParkingSpots().size() << ' ' << pf1.getUntakenSpots().size() << endl;
  // cout << pf1.getUntakenSpots().front() -> getParkingFloor() -> getSpotWidth() << endl;

  MultiLevelParkingLot mpl(234.56, 78.90, 3);
  cout << mpl.getLength() << ' ' << mpl.getWidth() << ' ' << mpl.getNumFloor() << ' ' << mpl.getNumAvailableFloors() << endl;
  cout << mpl.getParkingFloors().size() << ' ' << mpl.isFullFloors() << endl;
  ParkingFloor pf2(2, 3.78, 2.78, 4.5);
  ParkingFloor pf3(3, 3.67, 2.67, 3.5);
  ParkingFloor pf4(4, 3.56, 2.56, 2.5);
  mpl.addParkingFloor(&pf2);
  mpl.addParkingFloor(&pf3);
  mpl.addParkingFloor(&pf4);
  cout << mpl.getParkingFloors().size() << ' ' << mpl.isFullFloors() << endl;
  ParkingSpot ps3(3);
  ParkingSpot ps4(4);
  ParkingSpot ps5(5);
  pf2.addParkingSpot(&ps3);
  pf3.addParkingSpot(&ps4);
  pf4.addParkingSpot(&ps5);

  ParkingTime pt1;
  Vehicle v1("A1111", 3.53, 2.63, &pt1);
  cout << v1.getPlate() << ' ' << v1.getLength() << ' ' << v1.getWidth() << v1.getParkingSpot() << endl;
  cout << pf2.getUntakenSpots().size() << ' ' << pf2.isFullVehicles() << endl;
  v1.park(&mpl);
  cout << v1.getParkingSpot() -> getParkingSpotId() << endl;
  cout << v1.getParkingSpot() -> getVehicle() -> getPlate() << endl;
  cout << pf2.getUntakenSpots().size() << ' ' << pf2.isFullVehicles() << endl;
  this_thread::sleep_for(chrono::seconds(3));
  v1.unpark();
  cout << pt1.getTime() << endl;
  cout << v1.getTotalFare() << endl;
  cout << v1.getParkingSpot() << endl;
  cout << pf2.getUntakenSpots().size() << ' ' << pf2.isFullVehicles() << endl;

}
