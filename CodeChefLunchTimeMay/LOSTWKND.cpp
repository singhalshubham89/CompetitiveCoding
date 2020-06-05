#include<bits/stdc++.h>
using namespace std;
void solve(){
    int  ans;
    vector<int> a(6);
    ans = 0;
    
    for(int i = 0; i < 6; i++){
        cin>>a[i];
    }
    int prev = 0;
    for(int i = 0 ; i < 5; i++){
        prev = prev+(a[i]*a[5])-24;    
    }
    if(prev > 0 )
            ans = 1;
    if(ans)
        cout<<"Yes\n";
    else
    {
        cout<<"No\n";
    }
    
}
int main(){

    int t;
    cin>>t;
    for(int i = 1; i <= t;i++){
        solve();
    }

}