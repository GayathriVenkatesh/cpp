class Vehicle{

		int Vehicle_ID, Vehicle_age, Passenger_occupancy;
		float Vehicle_weight;
		char Vehicle_type;

public:

    Vehicle(int id, char type, float weight, int age, int passengers);

    double mobilityTax();
    double maintenance();

	  virtual double rental()=0;
	  virtual double showin()=0;

	  int getVehicle_ID();
	  int getVehicle_weight();
    int getVehicle_age();
    int getPassengers();
    char getVehicle_type();

};
