#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	int n_years = 0;
	int total = 0;
	int average = 0;
	int input = 0;
	
	cin >> n_years;

	while (n_years != 0)
	{
		total = 0;
		vector<int> v;
		for(int i = 0; i < n_years; i++)
		{
			cin >> input;
			v.push_back(input);
		}
		
		for(int i = 0; i <= n_years - 4; i++)
		{
			total = 0;
			for(int j = i; j < i + 4; j++)
			{
				total = total + v[j];
			}
			
			average = total / 4;
			cout << average << endl;
		}
		cin >> n_years;
		if(n_years != 0)
			cout << endl;
		
	}

	return 0;
}
