#include <iostream>
#include <vector>

using namespace std;


int main()
{
	int numInts;
	int integer;
	int sum;
	int temp;
	vector<int>integers;
	vector<int> squares;
	
	cin >> numInts;
	while(numInts != 0)
	{
		for( int i = 1; i <= numInts; i++)
		{
			cin >> integer;
			integers.push_back(integer);

		}
		
		for(int m = 0; m < integers.size(); m++)
		{
			for(int l = m; l < integers.size()-1; l++)
			{
				if(integers.at(m) > integers.at(l+1))
				{
					temp = integers.at(l+1);
					integers.at(l+1) = integers.at(m);
					integers.at(m) = temp;
					
				}
			}
		}
		
		
		for(int m = 0; m < integers.size(); m++)
		{
			for(int l = m; l < integers.size()-1; l++)
			{
				
				if(integers.at(m) == integers.at(l+1))
				{
					for(int g = l; g < integers.size()-1; g++)
					{
						integers.at(g) = integers.at(g+1);
		
					}
					integers.pop_back();
				}
			}		
		}

		for(int i = 0; i < integers.size(); i++)
		{
			squares.push_back(integers.at(i) * integers.at(i));
		}
		
		
		
		for(int i = 0; i < integers.size(); i++)
		{
			for(int j = i; j <  integers.size()-1; j++)
			{
				int holder = integers.at(i);
				int mover = integers.at(j+1);
				sum = (holder*holder) + (mover*mover);
				for(int k = 0; k < squares.size(); k++)
				{
					if(sum == squares.at(k))
					{
						cout << holder << " " << mover << " " << integers.at(k) << endl;
					}
				}
			}
		}
    squares.clear();
    integers.clear();
	cin >> numInts;
	if(numInts != 0)
	{
	 cout << endl;
	}
}
			
			

	

  return 0;
}
