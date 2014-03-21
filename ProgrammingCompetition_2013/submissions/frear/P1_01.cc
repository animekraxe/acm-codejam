#import <iostream>
#import <math.h>

using namespace std;

int main(){

	
	int input = -1;
	int past[4];
	int sizePast = 0;
	
	int aver[1000];
	int sizeAver = 0;
	
	cin >> input;
	
	while (input != 0){
		
		past[sizePast%4] = input;
		sizePast++;
		
		if (sizePast >= 4){
			int sum = 0;
			for (int i = 0; i < 4; i++){
				sum += past[i];
			}
			
			float average = sum;
			average = average/4;
			
			aver[sizeAver] = (int)floor(average);
			sizeAver++;
		}

	cin >> input;

	}
	
	for(int i = 0; i < sizeAver; i++){
		cout << aver[i] << endl;
	}
	cout << endl;
	return 0;
}
