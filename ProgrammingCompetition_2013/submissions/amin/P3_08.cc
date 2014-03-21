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
  if(left == right)
    return left;
  int size;
  if(left.size() >= right.size()){
    size = right.size();
  } else {
    size = left.size();
  }
  string temp = "";
  int index(0);
  for(int i(0); i != size; i++) {
    if(left[i] != right[i]){
      index = i;
      break;
    }
  }

  string sol1, sol2, sol3, sol4;
  sol1 = left.substr(0, index + 1);
  sol2 = sol1;
  sol2[index]++;

  sol3 = right.substr(0,index + 1);
  sol4 = sol2;
  sol4[index]++;

  if(sol2 == right)
    return left;
  else
    return sol2;
}
