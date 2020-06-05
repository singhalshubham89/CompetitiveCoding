#include<bits/stdc++.h>
using namespace std;
void solve(){
    string inp;
    cin>> inp;
    int total = (inp.size())/2;
    int ans = 0;
    for(int i = 1; i < total; i++){
        //cout<<i<<" "<<inp.substr(0, i)<<" "<<inp.substr(i,i)<<" "<<inp.substr(2*i, total-i)<<" "<<inp.substr(total+i, total-i)<<endl;

        if((inp.substr(0, i) == inp.substr(i,i)) && (inp.substr(2*i, total-i) == inp.substr(total+i, total-i)))
        {
            ans++;
        }

        
    }
    cout<<ans<<endl;
    
}
int main(){

    int t;
    cin>>t;
    for(int i = 1; i <= t;i++){
        solve();
    }

}