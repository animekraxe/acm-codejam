#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void findFriends( map<string,vector<string> >  mymap, string s)
{
	int i = 0;
	map<string,int> marFriends;
	map<string,vector<string> > ::iterator it = mymap.begin();
	
	for(unsigned j = 0; j < mymap.size(); j++,it++)
	{
		if(it->first != s)
		marFriends[it->first] = 0;
	}		
	
	for(unsigned i = 0; i < mymap[s].size(); i++)
	{
		string result = mymap[s][i];
		for(unsigned j = 0; j < mymap[result].size(); j++)
		{
			marFriends[mymap[result][j]]++;
		}
	}
	//int count = 0;
	map<string,int> ::iterator itor = marFriends.begin();
	vector<string> friends; 
	for(unsigned j = 0; j < marFriends.size(); j++,itor++)
	{
		if(itor->second > 1)
			friends.push_back(itor->first);
	}
	
	if(friends.size() > 0)
	cout << friends.size() -1 << endl;
	else 
	cout << 0 << endl;
	
	sort(friends.begin(),friends.end());
	for(unsigned j = 0; j < friends.size(); j++)
		if(friends[j] != "Marcelo")
			cout << friends[j] << endl;
}

int main()
{
	int datasets = 0;
	int numofpeople = 0;
	int count = 0;
	cin >> datasets;
	while(datasets > 0)
	{
		cin >> numofpeople;
		map<string,vector<string> > mymap;
		
		while( numofpeople > 0)
		{
			string s1,s2;
			cin >> s1;
			cin >> s2;
			mymap[s1].push_back(s2);
			mymap[s2].push_back(s1);
			numofpeople--;
		}
		
		findFriends(mymap,"Marcelo");
		datasets--;
	}
	
	return 0;
}
