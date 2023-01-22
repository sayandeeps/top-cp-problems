#include <bits/stdc++.h>
using namespace std;
int max(int a,int b){
	if(a<b){
		return b;
	}
	else{
		return a;
	}
}
int numdig(int n){
	int count=0;
	while(n!=0){
		int a =n%10;
		count++;
		n=n/10;
	}
	return count;
}
int karatsuba(long long int x, long long int y){
	if(x<10 &&y<10){
		return x*y;
	}
	
	long long int n=max(numdig(x),numdig(y));
	long long int m=ceil((float)n/2.0);
	long long int x1=floor(x/pow(10,m));
	long long int x2=x%((long long int)pow(10,m));
	long long int y1=floor(y/pow(10,m));
	long long int y2=y%((long long int)pow(10,m));
	long long int s1=karatsuba(x1,y1);
	long long int s2=karatsuba(x2,y2);
	long long int s3=karatsuba(x1+x2,y1+y2);
	long long int s4 =s3-s2-s1;
	return (s1*(pow(10,m*2)))+(s4*(pow(10,m)))+s2;
}
int main(){
	long long int n,m;
	cin>>n>>m;
	cout<<karatsuba(n,m);
}