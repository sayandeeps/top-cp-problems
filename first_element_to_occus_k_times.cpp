#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		unordered_map<int,int>m;
		int c=0;
		//initial value of a key in ordered map is zero
		for(int i =0;i<n;i++){
			m[a[i]]++;
			if(m[a[i]]>=k) {
				cout<<a[i];
				c=1;
				break;
			}
			
		}
		if(c==0){
			cout<<-1;
		}

	}
}