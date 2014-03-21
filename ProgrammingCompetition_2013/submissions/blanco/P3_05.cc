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
	
	for(unsigned i = 0; i < mid1.size() && i < mid2.size(); ++i)
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
			
			if(mid2 == returnValue)
			{
				return mid1;
			} 
			else return returnValue;
		}
	}
	
	return returnValue;
}

void print(const vector<string>& v)
{
	for(unsigned i = 0; i < v.size(); ++i)
		cout << v[i] << endl;
	cout << endl;
}

int main()
{
	
	int number;
	
	while(1)
	{
		vector<string>names(0);
		cin >> number;
		if(number == 0)
			break;
			
		getNames(names,number);
		sort(names.begin(),names.end());
		
		string separator = separatingString(names);
		cout << separator << endl;
	}
	
	return 0;
}
