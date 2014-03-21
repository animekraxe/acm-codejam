#import <iostream>
#import <math.h>

using namespace std;

int main(){

	
	int input = -1;
	int past[4];
	for (int i = 0; i < 4; i++){
		past[i] = 0;
	}
	
	
	int aver[1000];
	int sizeAver = 0;
	
	int dataSetSize = -1;
	int count = 0;
	
	cin >> input;
	
	while (input != 0){		
		
		if(count >= dataSetSize){
			cout << endl;
			count = 0;
			dataSetSize = input;
			
			for (int i = 0; i < 4; i++){
					past[i] = 0;
				}
			
		}
		
		else{
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
	cin >> input;

	}
	/*
	for(int i = 0; i < sizeAver; i++){
		cout << aver[i] << endl;
	}*/
	cout << endl;
	return 0;
}
