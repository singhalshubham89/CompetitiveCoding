#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int prev = -1;
    for(int i = 1; i < n; i++)
    {
        
        if(a[i-1] > prev && a[i-1] > a[i])
        {
            //cout<<i<<" ";
             ans++;
        }
           
        prev = max(prev, a[i-1]);
    }
    if(a[n-1] > prev)
        ans++;
    cout<<ans<<endl;
}
int main(){

    int t;
    cin>>t;
    for(int i = 1; i <= t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }

}