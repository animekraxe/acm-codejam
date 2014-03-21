#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void findFriends( map<string,vector<string> >  mymap, string s)
{
	//int i = 0;
	
	map<string,int> marFriends;
	map<string,vector<string> > ::iterator it = mymap.begin();
	
	bool isFriend = false;

	for(unsigned j = 0; j < mymap.size(); j++,it++)
	{
		for (unsigned i = 0; i < mymap[s].size(); ++i) {
			if(it->first == mymap[s][i]) 
				isFriend = true;
		}
		
		if(!isFriend && it->first != s) {
				marFriends[it->first] = 0;
		}
		else
		{
			marFriends[it->first] = -1 * (INT_MAX - 1);
		}
		isFriend = false;
	}	
	
	map<string,int > ::iterator itr = marFriends.begin();
	
	for(unsigned j = 0; j < mymap[s].size(); j++)
	{
		string friends = mymap[s][j];
		for(unsigned i = 0; i < mymap[friends].size(); i++)
		{
			marFriends[mymap[friends][i]]++;
		}
	}
	
	vector<string> friends;
	
	for(unsigned i = 0; i < marFriends.size(); i++,itr++)
		if(itr->second > 1)
			friends.push_back(itr->first);
	sort(friends.begin(),friends.end());
	cout << friends.size() << endl;
	for(unsigned i = 0; i < friends.size(); i++)
	{
		cout << friends[i] << endl;
	}	
}

int main()
{
	int datasets = 0;
	int numofpeople = 0;
	//int count = 0;
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
