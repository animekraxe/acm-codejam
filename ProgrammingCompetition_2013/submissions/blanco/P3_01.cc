#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getNames(vector<string>& v, int n)
{
	string name;
	for(int i = 0; i < n; ++i)
	{
		cin >> name;
		v.push_back(name);
	}
}

string separatingString(vector<string>& v)
{
	int mid = v.size() / 2;
	string mid1 = v[mid-1];
	string mid2 = v[mid];
	string returnValue = "";
	
	for(int i = 0; i < mid1.size() && i < mid2.size(); ++i)
	{
		if(mid1[i] == mid2[i])
			returnValue.push_back(mid1[i]);
		else
		{
			char c = mid1[i];
			int i = c;
			++i;
			char c2 = i;
			returnValue.push_back(c2);
			return returnValue;
		}
	}
}

int main()
{
	
	int number;
	
	while(1)
	{
		vector<string>names;
		cin >> number;
		if(number == 0)
			break;
			
		getNames(names,number);
		sort(names.begin(),names.end());
		
		cout << separatingString(names) << endl;
	}
	return 0;
}
