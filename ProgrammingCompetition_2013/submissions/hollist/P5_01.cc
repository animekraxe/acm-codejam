#include <iostream>
#include <sstream>

using namespace std;

int ten_to_the( int n)
{
	int ret = 1;
	for( int i = 0; i < n; ++i)
	{
		ret *= 10;
	}
	return ret;
}

int main()
{
	int num = 0;
	int num_moves = 0;
	string s;
	cin >> s;
	for( ; s != "0"; cin >> s)
	{
		bool is_palindrome = true;
		for( int i = 0,j = s.size()-1; i <= j; ++i, --j)
		{
			if( s[i] != s[j])
				is_palindrome = false;
		}
		if( is_palindrome)
			cout << "0" << endl;
		else
		{

			num_moves = 0;
			while( !is_palindrome)
			{
							
				num = 0;
				int size = s.size();
				//convert to int
				for( int i = s.size()-1; i >= 0; --i)
				{
					char c = s[i];

					c -= 48;
					int n = c;
					
					num += n*ten_to_the(s.size()-1-i);
					 
				}
				num++;
				num_moves++;
				stringstream ss;
				
				ss << num;
				s = ss.str();
				string temp = "";
				for( int i = 0; i < size-s.size(); ++i)
				{
					temp += "0";
				}
				
				s = temp + s;
				is_palindrome = true;
				for( int i = 0,j = s.size()-1; i <= j; ++i, --j)
				{
					if( s[i] != s[j])
						is_palindrome = false;
				}

			}
			
			cout << num_moves << endl;
		}
	}
	return 0;
}
