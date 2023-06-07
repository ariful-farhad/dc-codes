#include<bits/stdc++.h>
#define endl '\n'
#define push_back pb
using namespace std;



string XOR(string dataword, string divisor){
	string ans = "";

	bool flag = false;
	int i;
	for(i=0; i<divisor.size(); i++){
		if(dataword[i]==divisor[i]){
			if(flag){
				ans+='0';
			}
		}
		else{
			ans+='1';
			flag = true;
		}
	}
	string last = dataword.substr(i, dataword.size());
	ans+=last;
	//cout<<ans<<endl;
	return ans;

}


void createCodeword(string dataword, string divisor){
	for(int i=0; i<divisor.size()-1; i++)
		dataword+='0';
	string tempData = dataword;




	while(tempData.size()>=divisor.size()){
		tempData=XOR(tempData, divisor);
	}

	if(tempData.size()==0)
		cout<<dataword<<endl;
	else{
		dataword = dataword.erase(dataword.size()-tempData.size(), dataword.size());
		dataword+=tempData;
		cout<<dataword<<endl;
	}



}

int calculateNumerical(string a){
	int p = a.size()-1;
	int ans=0;
	for(int i=0; i<a.size(); i++){
		ans+=pow(2, p--)*(a[i]-'0');
	}
	return ans;
}


void checkCode(string codeword, string divisor){

	string tempData = codeword;




	while(tempData.size()>=divisor.size()){
		tempData=XOR(tempData, divisor);
	}


	if(calculateNumerical(tempData)==0){
		cout<<"your codeword is valid"<<endl;
	}
	else{
		cout<<"your codeword is not valid"<<endl;
	}
}

int main()
{
	createCodeword("0001", "1011");

	checkCode("1010011110101", "10111");
	checkCode("0001011", "1011");



	return 0;
}