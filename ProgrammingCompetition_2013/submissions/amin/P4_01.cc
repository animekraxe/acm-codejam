#include <iostream>
#include <map>
#include <vector>
#include <math.h>
using namespace std;

int main() {
  int input;
    while(cin >> input) {
    if(input == 0) {
      return 0;
    }
    double input2,i(0);
    map<double,double> myMap;
    vector<double> myList;
    while(cin >> input2 && i != input-1){
      myMap[input2] = input2;
      i++;
    }
    myMap[input2] = input2;
    for(map<double,double>::iterator it = myMap.begin(); 
      it != myMap.end(); it++){
      myList.push_back(it->first);
    }
    cout << endl;

    for(int i(0); i != myList.size(); i++) {
      double a = myList[i];
      for(int j(i + 1); j != myList.size(); j++) {
        double b = myList[j];
        double c = sqrt(a*a + b*b);
        if(myMap[c] == c){
          cout << a << " " << b << " " << c << endl;
        }
      }
    }
      
    }
   return 0;
}
