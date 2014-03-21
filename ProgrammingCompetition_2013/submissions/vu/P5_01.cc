#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

string itos(int a)
{
	stringstream s;
	s << a;
	string b;
	s >> b;
	return b;
}

bool is_palin(string str)
{
	unsigned int size = str.length();
	unsigned int half = size/2;
	for(unsigned int i = 0; i < half; ++i)
	{
		if(str[i] != str[size - i -1])
		{ 
			return false;
		}
	}
	return true;
}

unsigned int perm(string str)
{
	unsigned int size, nsize, dif; 
	unsigned int k;
	string nstr, flood;
	size = str.size();
	nstr = str;
	k = atoi(nstr.c_str());
	for(unsigned int c = 0 ;1; ++c, k = atoi(nstr.c_str()), ++k)
	{
		flood = "";
		nstr = itos(k);
		nsize = nstr.length();
		if(size > nsize)
		{
			
			dif = size - nsize;
			for(unsigned int i = 0; i <dif; ++i)
			{
				flood += "0";
			}
		}
		nstr = flood + nstr;
		if(is_palin(nstr)) return c;
	}
}

int main()
{
		string str;
		vector<unsigned int> results;
		
		while(cin >> str && str != "0")
		{
			results.push_back(perm(str));
		}
		unsigned int size =results.size();
		for(unsigned int i = 0; i < size; ++i)
		{
			cout << results[i];
			if(i != size -1) cout << endl;
		} 
		return 0;
}
