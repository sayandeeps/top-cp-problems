//problem link https://codeforces.com/problemset/problem/478/B
#include <bits/stdc++.h>
using namespace std;
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
vector<long long int>fact(long long int n){
	vector<long long int> v;
	v.push_back(1);
    for(long long int i =2;i<=n;i++){
        long long int carry =0;
        for(long long int j=0;j<v.size();j++){
            
            int val=karatsuba(v[j],i)+carry;
            v[j]=val%10;
            carry=val/10;
        }
            while(carry!=0){
                v.push_back(carry%10);
                carry=carry/10;
            }
        }
        reverse(v.begin(),v.end());
        return v;
   }
long long int print(vector<long long int> v){
	long long int value=0,a=1;
	for(long long int i=0,exp=v.size()-1;i<v.size();i++,exp--){

            value+=v[i]*pow(10,exp);
            
        }
        return value;
}
	long long int combinate(long long int n,long long int m){
		return print(fact(n))/(print(fact(m))*print(fact(n-m)));
	}

int main(){
	
		long long int a,b,min=0,max=0;
		cin>>a>>b;
		min=(combinate((long long int)a/b+1,2)*(a%b))+combinate((long long int)a/b,2)*(b-(a%b));
		max=combinate(a-b+1,2);
		cout<<min<<" "<<max<<endl;
	}
