#include "Vehicle.h"

    Vehicle::Vehicle(int id, char type, float weight, int age, int passengers){
			Vehicle_ID = id;
			Vehicle_type = type;
			Vehicle_weight = weight;
			Vehicle_age = age;
			Passenger_occupancy = passengers;
		}

    double Vehicle::mobilityTax(){
       return 30000+0.4*Vehicle_age+0.7*Vehicle_weight ;
    }
    double Vehicle::maintenance(){
         return 20000 + 0.2* Vehicle_age;
    }

	// double Vehicle::rental();
  // double Vehicle::showin();

   int Vehicle::getVehicle_ID(){
       return Vehicle_ID;
   }

    int Vehicle::getVehicle_weight(){
         return Vehicle_weight;
     }

     int Vehicle::getVehicle_age(){
         return Vehicle_age;
     }

     int Vehicle::getPassengers(){
         return Passenger_occupancy;
    }
    char Vehicle::getVehicle_type(){
        return Vehicle_type;
    }
