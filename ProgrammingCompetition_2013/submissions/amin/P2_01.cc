#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool exists(vector<string>&, string&);
void common_friends(map<string, vector<string> >&);
bool comp(vector<string>, vector<string>);
int main() {
  int sets;
  cin >> sets;
  for(int i(0); i != sets; i++) {
    int pairs;
    map<string,vector<string> > myMap; 
    cin >> pairs;
    for(int j(0); j != pairs; j++) {
      string first, second;
      cin >> first >> second;
      if(!exists(myMap[first],second)) {
        myMap[first].push_back(second);
        myMap[second].push_back(first);
      }
    }
    common_friends(myMap);
    cout << endl;
  }
  return 0;
}

bool exists(vector<string>& friends, string& second) {
  for(int i(0); i != friends.size(); i++){
    if(friends[i] == second)
      return true;
  }
  return false;
}

void common_friends(map<string, vector<string> >& myMap) {
  vector<string> v1 = myMap["Marcelo"];
  vector<string> final;
  bool temp;
  for(map<string, vector<string> >::iterator it = myMap.begin(); it != myMap.end(); it++){
    if(it->first != "Marcelo"){
      if(comp(v1, it->second)){
        final.push_back(it->first);
      }
    }
  }

  cout << final.size();
  for(int i(0); i != final.size(); i++){
    cout << endl << final[i];
  }
}

bool comp(vector<string> v1, vector<string> v2){
  bool match = false;
  for(int i(0); i != v1.size(); i++){
    for(int j(0); j != v2.size(); j++) {
      if(v1[i] == v2[j]){
        match = true;
      }
    }
    if(match != true){
      return false;
    }
  }
  return true;
}
