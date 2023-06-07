#include<bits/stdc++.h>
#define endl '\n'
#define push_back pb
using namespace std;
const int N = 10000000;
int dp[N];

int hammingDistance(string binary1, string binary2){
	int answer = 0;
	
	for(int i=0; i<binary1.size(); i++){
		if(binary1[i] != binary2[i])
			answer++;
	}
	cout<<binary1<< "  "<<binary2<<" -->"<<answer<<endl;
	return answer;

}


int main()
{

	ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;

    // bitset<12> binn(36);
    // cout<<binn<<endl;
    
    vector<string> codewords(n);
    for(int i =0; i<n; i++)
    	cin>>codewords[i];

    int answer = codewords[0].size();


    for(int i=0; i<n-1; i++){
    	for(int j = i+1; j<n; j++){
    		cout<<i<<"  "<<j<<endl;
    		answer = min(answer, hammingDistance(codewords[i], codewords[j]));
    	}
    }
    cout<<answer<<endl;









	return 0;
}