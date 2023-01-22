#include <bits/stdc++.h>
using namespace std;
long long int max(long long int a){
	return (a*(a-1))/2;
}
long long int min(long long int n,long long int m){
	return (max(n/m+1)*(n%m))+(max(n/m)*(m-(n%m)));
}
int main(){
	long long int a,b,maxi=0,mini=0;
	cin>>a>>b;
	maxi=max(a-b+1);
	mini=min(a,b);
	cout<<mini<<" "<<maxi<<endl; 

}