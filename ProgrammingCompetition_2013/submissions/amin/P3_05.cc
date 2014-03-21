#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

string mid(string, string);

int main() {
  int input;
  vector<string> final;
  while(cin >> input) {
    if(input <= 1 || input >= 1001){
      for(int i(0); i != final.size(); i++) {
        cout << final[i] << endl;
      }
      return 0;
    }
    string input2;
    int i(0);
    vector<string> myList;
    while(cin >> input2 && i != input - 1){
      myList.push_back(input2);
      i++;
    }
    myList.push_back(input2);

    int j(0);
    if(input > 1) {
      sort(myList.begin(), myList.end());
      final.push_back(mid(myList[(input/2)-1], myList[input/2]));
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
      char d = right[i];
      if(c != d - 1){
        c++;
        temp += c;
        return temp;
      }
      else{
        temp += c;
        return temp;
      }
    } else {
      temp += left[i];
    }
  }
  return temp;
}
