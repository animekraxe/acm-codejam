#import <iostream>
#import <math.h>

using namespace std;

int main(){

	
	int input = -1;
	int past[4];
	for (int i = 0; i < 4; i++){
		past[i] = 0;
	}
	
	bool isFirst = true;
	int aver[1000];
	int sizeAver = 0;
	
	int dataSetSize = -1;
	int count = 0;
	
	while (input != 0){		
		
		if(count >= dataSetSize){
			cin >> input;
			if (input == 0){return 0;}
		
			if(!isFirst){cout << endl;}
			else{isFirst = false;}
			count = 0;
			dataSetSize = input;
			
			for (int i = 0; i < 4; i++){
					past[i] = 0;
			}
			
		}
		
		else
		{
			cin >> input;
			if (input == 0){return 0;}
		
			count++;
			
			past[count%4] = input;
			
			if (count >= 4){
				int sum = 0;
				for (int i = 0; i < 4; i++){
					sum += past[i];
				}
				
				float average = sum;
				average = average/4;
				
				aver[sizeAver] = (int)floor(average);
				sizeAver++;
				cout << (int)floor(average) << endl;
			}
		}
	
	}

	return 0;
}
