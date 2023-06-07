#include<bits/stdc++.h>
#define endl '\n'
#define push_back pb
using namespace std;
int calculatesum(string s){

	int ans = 0;


	int p = s.size()-1;

	for(int i=0; i<s.size(); i++){
		ans +=pow(2, p--)*(s[i]-'0');
	}
	return ans;
}
string addBin(string a, string b){

	int maxLength= max(a.size(), b.size());

	string result = "";

	int length1 = a.size();
	int length2 = b.size();
	int carry = 0;


	for(int i=0; i<maxLength; i++){
		int bit1 = (i<length1)?(a[length1-1-i]-'0'):0;
		int bit2 = (i<length2)?(b[length2-1-i]-'0'):0;
		int sum = bit1+bit2+carry;

		carry = sum/2;
		result.insert(0, to_string(sum%2));
	}
	if(carry>0)
		result.insert(0, to_string(carry));
	return result;

}
int calculateAns(int num){
	bitset<6> bin(num);
	string binString  = bin.to_string();

	int length=4;
	while(binString.size()>length){
		string firstPortion = binString.substr(0, binString.size()-length);
		binString.erase(0, binString.size()-length);
		binString = addBin(binString,firstPortion);

	}
	cout<<binString<<endl;

	string res = "";
	for(int i=0; i<binString.size(); i++){
		if(binString[i]=='1')
			res+='0';
		else
			res+='1';
	}
	cout<<res<<endl;
	return calculatesum(res);
}

int main()
{
	
	
    int num= 0;

    for(int i=0;i<5; i++){
    	string str;
    	cin>>str;
    	num+=calculatesum(str);
    }
    cout<<num<<endl;


    cout<<calculateAns(36);





	return 0;
}