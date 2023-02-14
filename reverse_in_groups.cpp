#include <bits/stdc++.h>
using namespace std;
void swap(int a[],int i,int j){
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
void subrev(int a[],int n,int k){
	for(int i=0;i<n;i+=k){
		int left =i;
		int right =min(i+k-1,n-1);
		while(left<right){
			swap(a[left++],a[right--]);
		}
		}
	}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		int k;
		cin>>n>>k;
		int a[n];
		for(int i =0;i<n;i++){
			cin>>a[i];
		} 
		subrev(a,n,k);
		for(int i =0;i<n;i++){
			cout<<a[i]<<" ";
		}
			}
}