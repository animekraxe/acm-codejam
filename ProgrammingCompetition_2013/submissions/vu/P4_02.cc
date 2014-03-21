#include <iostream>
#include <vector>
using namespace std;

vector<unsigned int> count_sort(vector<unsigned int> & v)
{
	vector<bool> b(200000, false);
	vector<unsigned int> v2;
	unsigned int size = v.size();
	for(unsigned int i = 0; i < size; ++i)
	{
		b[v[i]] = true;
	} 
	
	for(unsigned int i = 0; i < 200000; ++i)
	{
		if(b[i]) v2.push_back(i);
	}
	return v2;
}

void funct(vector<unsigned int> s, unsigned int N)
{	
	unsigned int stop = N-2, stop2 = N-1;
	unsigned int i = 0;
	unsigned int a, a2, b, b2, c;
	for(;i < stop; ++i)
	{
		a = s[i];
		a2 = a * a;
		for(unsigned int j = i +1; j < stop2; ++j)
		{
			b = s[j];
			b2 = b * b;
			for(unsigned int k = j +1; k < N; ++k)
			 {
				c = s[k];
				if(a2+b2 == (c * c)){
					cout << a << ' ' <<  b << ' ' << c << endl; 
				}
			}
		}
	}
}

int main()
{
		vector<unsigned int> N;
		vector< vector<unsigned int> > s;
		unsigned int n, x;
		while(cin >> n && n != 0)
		{
		N.push_back(n);
		vector<unsigned int> v;
		for(unsigned int i = 0; i < n; ++i)
		{
			cin >> x;
			v.push_back(x);
		}
		 s.push_back(v);
		}
		
		
		unsigned int size =s.size();
		for(unsigned int i = 0; i < size; ++i)
		{
			funct(count_sort(s[i]), N[i]);
			if(i != size -1)cout << endl;
		}
		return 0;
}
