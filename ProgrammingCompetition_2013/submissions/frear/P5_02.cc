#import <iostream>
#import <fstream>
#import <sstream>
#import <math.h>


using namespace std;

int main(){
	int input = -1;
	
	int count = 0;


	bool isFirst = true;

	string inputString;
	cin >> inputString;
	
	while (input != 0){
		input = atoi(inputString.c_str());
	
		int size = inputString.length();
	
		//cout << size<< endl << input;
	
		int numbers[size];
		
		for (int i = 0; i < size; i++){
			int temp = atoi( &inputString.c_str()[i] );
			
			numbers[i] = (int)(temp/((int)pow(10,size-i -1)));
			//cout << numbers[i] << endl;
			/*
			int mod = (int)pow(10,i+1);
			int temp = temp%(mod);
			numbers[i] = (int)(temp/((int)pow(10,i)));
			*/
		}
		bool failed = false;
		
		for (int i = 0; i < (int)floor(size/2); i++){
			if (numbers[i] != numbers[size - i - 1]){
				failed = true;
				break;
			}
		}
	
		if(failed){
			input = input + 1;
			stringstream ss;
			ss << input;
			inputString = ss.str();
			
			int diff = size - inputString.length();
			for(int i = 0; i < diff; i++){
				inputString = "0" + inputString;
			}
			
			
			count++;
			failed = false;
			continue;
		}
	
		
		
		if(!isFirst){cout << endl;}
		else{isFirst = false;}
		//cout << input<< endl;
		cout << count;
		
		count = 0;
		cin >> inputString;	
	}

	return 0;
}
