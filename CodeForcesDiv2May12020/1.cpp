#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    for(int i = 1; i <= t;i++){
       int n;
       cin>>n;
       long long ans = 1<<n;
       int count = 0; 
       for(int i = n-1; i >= 1; i--){
           //cout<<ceil(n/4)<<" "<<(int)(n/2)<<endl;
           if(count < (n/2)){
            ans -= 1<<i;
            //cout<<ans<<" ";
            count++;
           }
           else
           {
               //cout<<ans<<" ";
               ans += 1<<i;
           }
           
            
       }       
       cout<<ans<<endl;
    }

}