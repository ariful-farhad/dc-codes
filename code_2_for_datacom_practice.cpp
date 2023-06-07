#include<bits/stdc++.h>
#define endl '\n'
#define push_back pb
using namespace std;

void createCode(string  a){
	int ans =0; 
	for(int i=0; i<a.size(); i++){
		if(a[i]=='1')
			ans++;
	}
	if(ans%2==0)
	{
		cout<<"parity bit added 0"<<endl;
		a+='0';
	}
	else{
		cout<<"parity bit added 1"<<endl;
		a+='1';
	}
	cout<<a<<endl;
}

void checkCode(string a){
int ans =0; 
	for(int i=0; i<a.size(); i++){
		if(a[i]=='1')
			ans++;
	}
	if(ans%2==0)
	{
		cout<<"codeword is correct"<<endl;
		
	}
	else{
		cout<<"codeword is corrupted"<<endl;
		
	}
	cout<<a<<endl;
}



int main()
{

	ios::sync_with_stdio(false);
    cin.tie(0);
    createCode("100");
    checkCode("10100");





	return 0;
}