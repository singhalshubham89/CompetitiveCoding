#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin>>s;
    char first = s[0];
    char diff = s[0];
    for(int i = 0; i    < s.size(); i++){
            if(s[i] != diff){
                diff = s[i];
                break;
            }
    }
    for(int i = 0; i < s.size(); i++){
        cout<<first<<diff;
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