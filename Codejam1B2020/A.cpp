#include<bits/stdc++.h>
using namespace std;
void backtrack(string& ans, int i, int j, int &x, int &y){
    
}

void solve(){
    string ans;
    int x, y;
    cin>>x>>y;
    backtrack(ans, 0, 0, x, y);
}
int main(){

    int t;
    cin>>t;
    for(int i = 1; i <= t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }

}