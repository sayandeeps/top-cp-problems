#include <bits/stdc++.h>
using namespace std;
vector<long long int> v;
void printvec(vector<long long int> v){
    for(int i=0;i<v.size();i++){
            cout<<v[i];
        }
}
int main(){
    long long int n;
    cin>>n;
    v.push_back(1);
    for(long long int i =2;i<=n;i++){
        long long int carry =0;
        for(long long int j=0;j<v.size();j++){
            
            int val=v[j]*i+carry;
            v[j]=val%10;
            carry=val/10;
        }
            while(carry!=0){
                v.push_back(carry%10);
                carry=carry/10;
            }
        }
        reverse(v.begin(),v.end());
        printvec(v);

    }

