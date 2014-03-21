#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main ()
{
	bool b = false;
	
	while ( true ) {
		
		
	
		int num_years;
		int input;
		double avg = 0;
	
		vector <int> all;
	
		cin >> num_years;
	
		if (num_years != 0) {
	
			for ( num_years; num_years > 0; num_years -- ) {
				cin >> input;
				all.push_back(input);
			}
	
			if ( all.size() >= 4 ) {
				
				if ( b ) {
					cout << endl;
				}
		
				b = true;
			
				for ( int i = 3; i < all.size(); i++ ) {
					avg = all[i];
		
					for ( int j = i - 1; j >= i - 3; j -- ) {
						avg += all[j];
					}
					avg = avg / 4;
					cout << static_cast<int> (avg);
					cout << endl;
				}
			}
			
		}
		
		else { break; }
	}
		
		
	return 0;
}
