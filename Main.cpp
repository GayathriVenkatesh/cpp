//  TO DO : Write .h files
//  Put this code in FinOp class

#include<iostream>
#include<vector>
#include<boost/algorithm/string.hpp>
#include"Vehicle.cpp"
#include"LVehicle.cpp"
#include"WVehicle.cpp"
using namespace std;

// 2 3 10-L-200-10-4 22-W-400-2-20 MN-10 MT-22 RR-L-2
int main(){

  int v, q;
  int income=0;
  int expense=0;
  string test;
  vector<LVehicle> lvehicles;
  vector<WVehicle> wvehicles;
  cin >> v >> q;
  int veh=v;
  while(v){
    v--;
    cin >> test;
    vector<string> input;
    boost::split(input, test, boost::is_any_of("-"));
    char x = input[1][0];
    if(x=='L') {
      LVehicle l(stoi(input[0]), x, stof(input[2]), stoi(input[3]), stoi(input[4]));
      lvehicles.push_back(l); }
    else {
      WVehicle l(stoi(input[0]), x, stof(input[2]), stoi(input[3]), stoi(input[4]));
      wvehicles.push_back(l); }
  }

  while(q){
    q--;
    cin >> test;
    vector<string> input;
    boost::split(input, test, boost::is_any_of("-"));
    if(input[0]=="MN"){
      int id = stoi(input[1]);
      for(int i=0; i<lvehicles.size(); i++){
        if(lvehicles[i].getVehicle_ID() == id){
          // cout << "YAY!";
          double k = lvehicles[i].maintenance();
          cout << k << "\n";
          expense+=k;
        }
      }

      for(int i=0; i<wvehicles.size(); i++){
        if(wvehicles[i].getVehicle_ID() == id){
          // cout << "YAY2!";
          double k = wvehicles[i].maintenance();
          cout << k << "\n";
          expense+=k;
        }
      }
    }


    else if(input[0]=="MT"){
      int id = stoi(input[1]);
      for(int i=0; i<lvehicles.size(); i++){
        if(lvehicles[i].getVehicle_ID() == id){
          // cout << "YAY!";
          double k = lvehicles[i].mobilityTax();
          cout << k << "\n";
          expense+=k;
        }
      }

      for(int i=0; i<wvehicles.size(); i++){
        if(wvehicles[i].getVehicle_ID() == id){
          // cout << "YAY2!";
          double k = lvehicles[i].mobilityTax();
          cout << k << "\n";
          expense+=k;
        }
      }
    }

    else if(input[0]=="SR"){
      char x = input[1][0];
      int no = stoi(input[2]);
      int min_diff = INT_MAX;
      int index=-1;
      double k;
      if(x=='L'){
        for(int i=0; i<lvehicles.size(); i++){
          if(lvehicles[i].getVehicle_age() >= no){
            // cout << "YAY!";
            if(lvehicles[i].getVehicle_age()-no < min_diff) {
              min_diff = lvehicles[i].getVehicle_age()-no;
              index = i; } }
        }

          if(index!=-1) {k = lvehicles[index].showin(); income+=k;}
          else k=0;
          cout << k << "\n";
          if(index!=-1) cout << lvehicles[index].getVehicle_age() << "\n";
      }
        // } }

        else if(x=='W'){
          for(int i=0; i<wvehicles.size(); i++){
            if(wvehicles[i].getVehicle_age() >= no){
              // cout << "YAY!";
              if(wvehicles[i].getVehicle_age()-no < min_diff) {
                min_diff = wvehicles[i].getVehicle_age()-no;
                index = i; } }
            }
              if(index!=-1) {k = wvehicles[index].showin(); income+=k;}
              else k=0;
              cout << k << "\n";
              if(index!=-1) cout << wvehicles[index].getVehicle_age() << "\n";
          }
    }




  else if(input[0]=="RR"){
    char x = input[1][0];
    int no = stoi(input[2]);
    int min_diff = INT_MAX;
    int index=-1;
    double k;
    if(x=='L'){
      for(int i=0; i<lvehicles.size(); i++){
        if(lvehicles[i].getPassengers() >= no){
          // cout << "YAY!";
          if(lvehicles[i].getPassengers()-no < min_diff) {
            min_diff = lvehicles[i].getPassengers()-no;
            index = i; } }
      }

        if(index!=-1) {k = lvehicles[index].rental(); income+=k;}
        else k=0;
        cout << k << "\n";
        if(index!=-1) cout << lvehicles[index].getVehicle_ID() << "\n";
    }
      // } }

      else if(x=='W'){
        for(int i=0; i<wvehicles.size(); i++){
          if(wvehicles[i].getPassengers() >= no){
            // cout << "YAY!";
            if(wvehicles[i].getPassengers()-no < min_diff) {
              min_diff = wvehicles[i].getPassengers()-no;
              index = i; } }
          }
            if(index!=-1) {k = wvehicles[index].rental(); income+=k;}
            else k=0;
            cout << k << "\n";
            if(index!=-1) cout << wvehicles[index].getVehicle_ID() << "\n";
        }
  }
}


  expense+=veh*6000;

  cout << income-expense << "\n";
  return 0;
}
