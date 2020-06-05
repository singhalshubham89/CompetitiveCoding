#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<long long> a(n), b(n);
    long long t, ans = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < n; i++){
        cin>>b[i];
    }
    long long ax = a[0];
    long long by = b[0];
    if(ax == by){
        ans += a[0];
    }
    for(int i = 1; i < n; i++){
        if(ax == by && a[i] == b[i]){
            ans += a[i];
        }
        ax += a[i];
        by += b[i];
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