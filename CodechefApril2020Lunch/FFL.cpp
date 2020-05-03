#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,s;
    cin>>n>>s;
    vector<int> price(n);
    for(int i = 0; i < n; i++){
        cin>>price[i];
    }
    int forward = 101, backward = 101, t;
    for(int i = 0; i < n; i++){
        cin>>t;
        if(t == 0){
            forward = min(forward, price[i]);
        }else{
            backward = min(backward, price[i]);
        }
    }
    if(s+forward+backward <= 100 )
        cout<<"yes"<<endl;
    else
    {
        cout<<"no"<<endl;
    }
    
}
int main(){

    int t;
    cin>>t;
    for(int i = 1; i <= t;i++){
        solve();
    }

}