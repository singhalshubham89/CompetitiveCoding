#include<bits/stdc++.h>
using namespace std;
void solve(){
    int p, ans;
    vector<int> a(5);
    ans = 0;
    p = 0;
    
    for(int i = 0; i < 5; i++){
        cin>>a[i];
    }
    cin>>p;
    int prev = 0;
    for(int i = 0 ; i < 5; i++){
        int cur = a[i]*p;
        if(prev-24 > 0 )
            ans = 1;
        prev = prev+cur-24;    
    }
    if(prev > 0 )
            ans = 1;
    if(ans)
        cout<<"YES\n";
    else
    {
        cout<<"NO\n";
    }
    
}
int main(){

    int t;
    cin>>t;
    for(int i = 1; i <= t;i++){
        solve();
    }

}