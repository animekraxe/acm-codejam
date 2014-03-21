#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
	int numYears;
	int yearTemp;
	int sum = 0;
	
	double average;
	
	
	
	while(cin>>numYears && numYears != 0)
    {
	
		vector<int>yearTemps(0);
		for (int i = 0; i < numYears; i++)
		{
			cin >> yearTemp;
			
			yearTemps.push_back(yearTemp);
		}
		while(yearTemps.size() >= 4)
		{
			for(int i = 0; i < 4; i++)
			{
				sum += yearTemps.at(i);
				if(i == 3)
				{
					average = sum/4;
					cout << fixed << setprecision(0)<< average << endl;
				}
			}
			
			for(unsigned i = 0; i < yearTemps.size()-1; i++)
			{
				yearTemps.at(i) = yearTemps.at(i+1);
			}
			yearTemps.pop_back();
			sum = 0;
		}
		yearTemps.clear();
		cout << endl;
	}
		
		
	
	
	
	return 0;
}
