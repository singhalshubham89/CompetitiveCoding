#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void solve(){
    ll k, n;
    cin>>n>>k;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++)
        cin>>a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    for(ll i = 0; i < k; i++)
    {
        ans += a[i]*(i+1);
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