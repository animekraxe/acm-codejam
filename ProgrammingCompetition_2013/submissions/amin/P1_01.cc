#include <iostream>
#include <vector>
using namespace std;

void compute_average(vector<int>&,int);

int main() {
  int input;
  bool hit = false;
  while(cin >> input) {
    if(input < 3 || input > 1001) {
      return 0;
    }
    vector<int> temperatures(input);
    int input2, i(0);
    while(cin >> input2 && i != input-1){
      temperatures[i] = input2;
      i++;
    }
    temperatures[i] = input2;
    compute_average(temperatures, input);
    cout << endl;
  }
  return 0;
}

void compute_average(vector<int>& temperatures, int input) {
  for(int i(3); i != temperatures.size(); i++) {
    int sum = temperatures[i] + temperatures[i-1] + temperatures[i-2] +
    temperatures[i-3];
    int avg = sum/4;
    cout << avg << endl;
  }
}

