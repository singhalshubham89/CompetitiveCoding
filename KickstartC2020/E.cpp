#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, m;
    cin>>n>>m;
    int ans = 0;
    int prev = m+1;
    int temp;
    for(int i = 0; i < n; i++){
        cin>>temp;
        if(temp == prev-1)
            prev = temp;
        else
        {
            prev = m+1;
        }
        
        if(prev == 1){
            ans++;
            prev = m+1;
        }
    }
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