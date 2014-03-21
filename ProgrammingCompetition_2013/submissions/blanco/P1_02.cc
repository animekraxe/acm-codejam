#include <iostream>
#include <vector>

using namespace std;
bool isFirst = true;

void averages(const vector<int> & v)
{
	if(isFirst)
	{
	}
	else 
	cout << endl;
		for(unsigned i = 0; i < v.size() -3; i++)
		{
			int average = 0;
			for(unsigned j = i; j < i+4; j++)
			{
				average += v[j];
			} 
			cout << average/4 << "\n";
		}
	
}
int main()
{
	
	int number;
	while(true)
	{
		cin >> number;
		if(number == 0)
		break;
		
		vector<int> vec;
		int count = 0;
		//int input;
		while(count < number)
		{
			int input;
			cin >> input;
			vec.push_back(input);
			count++;
		}	
		if( number == 0)
			break;
		averages(vec);
		isFirst = false;
		
		
	}
}
