#include<bits/stdc++.h>
#define endl '\n'
#define push_back pb
using namespace std;

string calculateXOR(string dataword, string divisor){
	
	string result = "";
	int i;
	bool startingzero = true;
	for(i=0; i<divisor.size(); i++){
		if(dataword[i]==divisor[i]){
			if(!startingzero)
				result+='0';
		}
		else{
			result+='1';
			startingzero=false;
		}
	}

	if(dataword.size()>divisor.size()){
		string subString = dataword.substr(i, dataword.size());
		result+=subString;
	}
	return result;
}



void createCRC(string dataword, string divisor){

	for(int i=0; i<divisor.size()-1; i++){
		dataword+='0';
	}
	string redundancyBits = dataword;




	while(redundancyBits.size()>=divisor.size()){
		redundancyBits = calculateXOR(redundancyBits, divisor);
		
	}

	//replacing last bits with redundancy bits
	dataword = dataword.erase((dataword.size()-redundancyBits.size()), dataword.size());
	dataword=dataword+redundancyBits;


	cout<<"redundancyBits-->"<<redundancyBits<<endl;
	cout<<"codeword-->"<<dataword<<endl;
}


void checkCrc(string codeword, string divisor){

	string redundancyBits = codeword;

	while(redundancyBits.size()>=divisor.size()){
		redundancyBits = calculateXOR(redundancyBits, divisor);
		
	}
	if(redundancyBits.size()==0)
		redundancyBits='0';


	if(redundancyBits.size()>1 ||(redundancyBits.size()==1 && redundancyBits[0]=='1')){
		cout<<"Your codeword is corrupted\n";
		cout<<"Your remainder is "<<redundancyBits<<endl;
	}
	else{
		cout<<"Your codeword is correct\n";
		cout<<"Your remainder is "<<redundancyBits<<endl;
	}
}

int main()
{

	int option;
	cout<<"choose option: \n1 -- createCRC\n2 -- checkCrc\n";
	cin>>option;


	switch(option){
	case 1:
		createCRC("101001111", "10111");
		createCRC("0000", "1011");
		// createCRC("0001", "1011");
		// createCRC("0010", "1011");
		// createCRC("0011", "1011");
		// createCRC("0100", "1011");
		// createCRC("0101", "1011");
		// createCRC("0110", "1011");
		// createCRC("0111", "1011");
		// createCRC("1000", "1011");
		// createCRC("1001", "1011");
		// createCRC("1010", "1011");
		// createCRC("1011", "1011");
		// createCRC("1100", "1011");
		// createCRC("1101", "1011");
		// createCRC("1110", "1011");
		// createCRC("1111", "1011");
		break;
	case 2:
		//checkCrc("1010011110101", "10111");
		// checkCrc("1010011110100", "10111");
		// checkCrc("1001110", "1011");
		checkCrc("0000000", "1011");
		// checkCrc("1001111", "1011");
		break;
	default: 
		cout<<"you choosed incorrect option\n";




	}
	




	return 0;
}