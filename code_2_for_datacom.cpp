#include<bits/stdc++.h>
#define endl '\n'
#define push_back pb
using namespace std;

void createCodeword(string data){
	int count_of_one =0;
	for(int i=0; i<data.size(); i++){
		if(data[i]=='1')
			count_of_one++;
	}
	

	if(count_of_one%2==0){
		data+='0';
		cout<<"created codeword is : "<<data<<endl;
		cout<<"parity added: 0"<<endl;
	}
	else 
		{
		data+='1';
		cout<<"created codeword is : "<<data<<endl;
		cout<<"parity added: 1"<<endl;
	}


	
}


void checkCodeword(string data){
	int count_of_one =0;
	for(int i=0; i<data.size(); i++){
		if(data[i]==1)
			count_of_one++;
	}

	if(count_of_one%2==0)
		cout<<"Your codeword "<<data<<" is authentic"<<endl;
	else
		cout<<"Your codeword "<<data<<" is corrupted"<<endl;
}


int main()
{
	
	ios::sync_with_stdio(false);
    cin.tie(0);
    

    cout<<"Choose Option: \n1 - (create codeword)\n2 - (check corruption)\n"<<endl;
    int option;
    cin>>option;



string input;
    cin>>input;
    switch(option){
    	case 1:
    		createCodeword(input);
    		break;
    	case 2: 
    		checkCodeword(input);
    		break;
    	default: 
    		cout<<"You choose wrong option\n";
    		break;
    }





	return 0;
}