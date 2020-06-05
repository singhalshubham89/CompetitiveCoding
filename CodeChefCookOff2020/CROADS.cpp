#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n;
    cin>>n;
    long long ans = n/2;
    long long t = n/2;
    if(n%2 == 1){
        ans++;
    }
    ans += (t)*(t+1);
    cout<<ans-1<<endl;
}
int main(){

    int t;
    cin>>t;
    for(int i = 1; i <= t;i++){
        solve();
    }

}