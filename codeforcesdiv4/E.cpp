#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> m(n+1, 0);
    vector<int> arr;
    vector<int> prefix(n+1, 0);
    int inp;
    for(int i = 1; i <= n; i++){
        cin>>inp;
        arr.push_back(inp);
        prefix[i] = inp+prefix[i-1];
    }
    int ans = 0;
    for(int i = 0; i <= n; i++){
        for(int j = i+2; j <= n && prefix[j]-prefix[i] <= n; j++){
            int temp = prefix[j]-prefix[i];
            m[temp] = 1;
        }
    }
    for(int i = 0; i < n; i++){
        ans += m[arr[i]];
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