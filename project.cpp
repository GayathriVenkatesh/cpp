#include<iostream>
#include<string>
#include<vector>
#include<boost/algorithm/string.hpp>
using namespace std;

class ExponentialEqn{
  float a,b,c,d,e,f;
public:
  ExponentialEqn(string p, string q, string r, string s, string t, string u){
    a = stof(p);
    // string temp = q.replace(q.size()-1, 1, NULL);
    if(q.size()==1) q.replace(0, 1, "1");
    else q.erase(q.size()-1, 1);
    cout << "q " << q << "\n";
    b = stof(q);

    c = stof(r);
    d = stof(s);
    string t1 = t.replace(t.size()-1, 1, "");
    e = stof(t1);
    // e=4;
    f = stof(u);

    cout << a << b<<c<<d<<e<<f;
  }

  float solve(){
    return LinearEqn l(log(a), b, c, log(d), e, f);
  }
};

int main(){
  string input;
  cin >> input;

  vector<string> res;
  vector<string>r1;
  vector<string>r2, r3;
  size_t found = input.find("-");
  if(found != string::npos)
    input.replace(found, 1, "+-");

  while(found != string::npos){
    found = input.find("-", found+2);
    if (found != string::npos)  {
      // cout << found << "\t";
      input.replace(found, 1, "+-");
      // cout << input << "\n";
    }
    else break;
  }

  cout << input << "\n";
  std::string delm("+()^");
  boost::split(r1, input, boost::is_any_of("="));
  cout << r1[0] << " " << r1[1] << "\n";

  found = r1[0].find("+");
  if(found == string::npos) r1[0].append("+0");

  cout << "REPLACED: " << r1[0] << "\n";

  boost::split(r2, r1[0], boost::is_any_of(delm));
  boost::split(r3, r1[1], boost::is_any_of(delm));

  vector<string> result;

  for(int i=0; i<r2.size(); i++) {if(r2[i]!="") result.push_back(r2[i]); }
  for(int i=0; i<r3.size(); i++) {if(r3[i]!="") result.push_back(r3[i]); }

  cout << "SPLIT: " << result[0] << " " << result[1] << " " << result[2] << " " << result[3] << " " << result[4] << " " << result[5] << "\n";

  ExponentialEqn l(result[0], result[1], result[2], result[3], result[4], result[5]);
  return 0;
}
