#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n, k;
    cin>>n>>k;
    if((n-k+1) > 0 && (n-k+1)%2 == 1){
        cout<<"YES"<<endl;
        for(int i = 1; i < k; i++){
            cout<<1<<" ";
        }
        cout<<n-k+1<<endl;
    }else if((n-((k-1)*2)) >0 && (n-((k-1)*2))%2 == 0){
        cout<<"YES"<<endl;
        for(int i = 1; i < k; i++){
            cout<<2<<" ";
        }
        cout<<(n-((k-1)*2))<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}
int main(){

    int t;
    cin>>t;
    for(int i = 1; i <= t;i++){
        solve();
    }

}