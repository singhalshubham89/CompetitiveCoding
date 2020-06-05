#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n, k;
    cin>>n>>k;
    long long ans = (k*n)/(n-1);
    if(ans%n == 0)
        ans--;
    cout<<ans<<endl;
}
int main(){

    int t;
    cin>>t;
    for(int i = 1; i <= t;i++){
        solve();
    }

}