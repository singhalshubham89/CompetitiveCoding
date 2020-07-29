#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, x;
    cin>>n>>x;
    vector<int> a(n+1, 0);
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        a[i] = a[i]+a[i-1];
    }
    int ans = -1;
    int i = 0, j = n;
    while(i <= j)
    {
        if((a[j]-a[i])%x != 0)
        {
            ans = j-i;
            break;
        }
        else if()

    }

}
int main(){

    int t;
    cin>>t;
    for(int i = 1; i <= t;i++){
        solve();
    }

}