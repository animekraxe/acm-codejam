
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

#define maxN 10000

ofstream runavein;
ofstream runaveout;

void generate(int howmany)
{
	int i;
	int temps[maxN];
	double ave;
	int roundave;
	
	runavein << howmany << endl;
	for (i = 0; i < howmany; i++)
	{
		temps[i] = (int) 1 + rand() % 100;
		runavein << temps[i] << endl;
	}
	for (i = 3; i < howmany; i++)
	{
		ave = (double) 0.25 * ( temps[i-3] + temps[i-2] + temps[i-1] + temps[i] );
		roundave = floor( ave );
		runaveout << roundave << endl;
	}
}

int main () {

	srand(time(0));
  	runavein.open ("runave.in");
  	runaveout.open ("runave.out");
	generate(10);
	runaveout << endl;
	generate(100);
	runaveout << endl;
	generate(1000);
	runavein << 0 << endl;
	runavein.close();	
  	runaveout.close();
  	return 0;
}