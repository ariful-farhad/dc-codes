#include<bits/stdc++.h>
#define endl '\n'
#define push_back pb
using namespace std;

int minHam(string a, string b){
	int ans = 0;
	for(int i=0; i<a.size(); i++){
		if(a[i]!=b[i])
			ans++;
	}
	cout<<a<<" "<<b<<"--"<<ans<<endl;
	return ans;
}

int main()
{

	ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;

    vector<string> vec(n);
    for(int i=0; i<n; i++){
    	cin>>vec[i];
    }


    int ans = 40;
    for(int i=0; i<n-1; i++){
    	for(int j=i+1; j<=n-1; j++){
    		ans= min(ans, minHam(vec[i], vec[j]));
    	}
    }

    cout<<ans<<endl;



	return 0;
}