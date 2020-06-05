#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> ans;
    int count = 0;
    int t = 1;
    while(n > 0){
        if(n%10 != 0){
            count++;
            ans.push_back((n%10) *t);
        }
        n /= 10;
        t *= 10;
    }
    cout<<count<<endl;
    for(int i = 0; i < count; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main(){

    int t;
    cin>>t;
    for(int i = 1; i <= t;i++){
        solve();
    }

}