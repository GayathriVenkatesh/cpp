class WVehicle :public Vehicle
{
public:
  WVehicle(int a, char b, float c, int d, int e): Vehicle(a, b, c, d, e){

  }
    double rental()
    {
        if(getPassengers()<10)
        {
        return 50000.00;
        }
        else
        {
             return 100000.00;
        }

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
