#include <iostream>
#include <map>
#include <vector>

using namespace std;

string mid(string, string);

int main() {
  int input;
  vector<string> final;
  while(cin >> input) {
    if(input == 0){
      for(int i(0); i != final.size(); i++) {
        cout << final[i] << endl;
      }
      return 0;
    }
    string input2;
    int i(0);
    map<string,bool> myMap;
    while(cin >> input2 && i != input - 1){
      myMap[input2] = true;
      i++;
    }
    myMap[input2] = true;

    int j(0);
    string left, right;
    if(input > 1) {
      for(map<string, bool >::iterator it = myMap.begin(); 
          it != myMap.end(); it++, j++){
        if(j == input/2 - 1){
          left = it->first;
        }
        if(j == input/2){
          right = it->first;
        }
      }
      final.push_back(mid(left,right));
    } else {
      final.push_back(input2);
    }
    
  }
 return 0;
}

string mid(string left, string right){
  int size;
  if(left.size() >= right.size()){
    size = right.size();
  } else {
    size = left.size();
  }
  string temp = "";
  for(int i(0); i != size; i++) {
    if(left[i] != right[i]) {
      char c = left[i];
      c++;
      temp += c;
      return temp;
    } else {
      temp += left[i];
    }
  }
  return temp;
}
