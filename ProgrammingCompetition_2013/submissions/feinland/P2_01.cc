#include <iostream>
#include <vector>


using namespace std;

int main()
{
	int numberSets;
	int numPairs;
	vector<string> samefriend;
	int counter = 0;
	string friendPair;
	string friendone, friendtwo;
	string marceloFriend, friendsFriend;
	string conglomerate;
	vector<string>pairs;
	vector<string>friendofMarcelo;
	vector<string>friendsofFriends;
	
	cin >> numberSets;
	for(int i = 0; i < numberSets; i++)
	{
		cin >> numPairs;
		for(int j = 0; j <= numPairs; j++)
		{
			getline(cin, friendPair);
			pairs.push_back(friendPair);
			
			friendone = friendPair.substr(0, friendPair.find(" "));
			friendtwo = friendPair.substr(friendPair.find(" ")+1);
			//~ cout << friendone << endl << friendtwo<<endl;
			if(friendone == "Marcelo")
			{
				marceloFriend = friendtwo;	
				friendofMarcelo.push_back(marceloFriend);			
			}
			else if(friendtwo == "Marcelo")
			{
				marceloFriend = friendone;
				friendofMarcelo.push_back(marceloFriend);
			}
			
		 }
		//~ cout << endl<<friendofMarcelo.at(0)<< endl << friendofMarcelo.at(1)<<endl;
		 for(int j = 0; j < pairs.size(); j++)
		 {
			 for(int k = 0; k < friendofMarcelo.size(); k++)
			 {
				 if(pairs.at(j).find(friendofMarcelo.at(k)) != -1)
				 {
					 friendone = pairs.at(j).substr(0, pairs.at(j).find(" "));
			         friendtwo = pairs.at(j).substr(pairs.at(j).find(" ")+1);
			         //~ cout << friendone << endl << friendtwo <<endl;
					 if(friendone == friendofMarcelo.at(k)  && friendtwo != "Marcelo")
					 {
						 friendsofFriends.push_back(friendtwo);
					 }
					 else if(friendtwo == friendofMarcelo.at(k) && friendone != "Marcelo")
					 {
						 friendsofFriends.push_back(friendone);
					 }
				 }
			}
		}
			
			for(int m = 0; m < friendsofFriends.size(); m++)
			{
				for(int l = m; l < friendsofFriends.size()-1; l++)
				{
					if(friendsofFriends.at(m) == friendsofFriends.at(l+1))
					{
						    
						    if(conglomerate.find(friendsofFriends.at(m)) == -1)
						    {
								conglomerate += friendsofFriends.at(m);
								samefriend.push_back(friendsofFriends.at(m));
							}
						
					}
				}
			}

				

		//~ cout << endl << friendsofFriends.at(0)<<friendsofFriends.at(1)<<endl;
		counter = samefriend.size();
		cout <<counter << endl;
		string temp = "";
		for(int m = 0; m < samefriend.size(); m++)
		{
			for(int l = m; l < samefriend.size()-1; l++)
			{
				if(samefriend.at(m) > samefriend.at(l+1))
				{
					temp = samefriend.at(l+1);
					samefriend.at(l+1) = samefriend.at(m);
					samefriend.at(m) = temp;
				}
			}
		}
			
				
		for(int j = 0; j < samefriend.size(); j++)
		{
			cout << samefriend.at(j) << endl;
		}
		conglomerate = "";
		samefriend.clear();
		friendsofFriends.clear();
		friendofMarcelo.clear();
		pairs.clear();
		counter = 0;
		
				

   }
}

