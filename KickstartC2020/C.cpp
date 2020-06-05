#include<bits/stdc++.h>
using namespace std;
set<int> s;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1, 0);
    for(int i = 1; i <= n; i++){
        cin>> a[i];
        a[i] += a[i-1];
    }
    int ans =0;
    for(int i = 0; i <= n ; i++){
        for(int j = i+1; j<= n; j++){
            if(a[j] >= a[i]){
                double temp = sqrt(a[j] - a[i]);
                if(ceil(temp) == floor(temp))
                    ans++;
            }
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