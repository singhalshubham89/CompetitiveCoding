#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, m;
    cin>>n>>m;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++)
        cin>>a[i].first;
    for(int i = 0; i < n; i++)
        cin>>a[i].second;
    unordered_map<int, vector<int>> mp;
    int u, v;
    for(int i = 0; i < m; i++)
    {
        cin>>u>>v;
        mp[u-1].push_back(v-1);
        mp[v-1].push_back(u-1);
    }
}
int main(){

    int t;
    cin>>t;
    for(int i = 1; i <= t;i++){
        solve();
    }

}