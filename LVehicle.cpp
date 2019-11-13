class LVehicle :public Vehicle{

  public:
    LVehicle(int a, char b, float c, int d, int e): Vehicle(a, b, c, d, e){
      
    }

    double rental()
    {
        return 34000+20*getPassengers();
    }
    double showin()
    {
        if(getVehicle_age()<2)
        {
        return 20000.00;
        }
        else
        {
             return 40000+0.4*getVehicle_age();
        }

    }
};
