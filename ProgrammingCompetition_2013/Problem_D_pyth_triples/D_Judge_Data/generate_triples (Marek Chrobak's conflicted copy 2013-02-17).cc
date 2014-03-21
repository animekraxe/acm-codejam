
#include <iostream>
#include <fstream>
using namespace std;

#define Max 200

ofstream triples;

int main () {
	int u, v, x, y, z, maxuv;
	
  	triples.open ("triples.txt");

	runavein << 10 << endl;
	for (i = 0; i < 10; i++)
	{
		maxuv = 0.5*sqrt(Max);
		u = 1+ rand() % maxuv;
		v = + rand() % maxuv;
		x = u*u + 2*u*cv;
		y = 2*v*v + 2*u*v;
		z = u*u + 2*v*v + 2*u*v;
	}
	triples.close();	
  	return 0;
}