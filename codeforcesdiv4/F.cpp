#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n0, n1, n2;
    cin>>n0>>n1>>n2;
    string ans(n0+n1+n2+1, '0');
    int i  = 0;
    while(n2 > 0){
        ans[i] = '1';
        ans[i+1] = '1';
        i++;
        n2--;
    }
    int flag = 1;
    while(n1 > 0){
        if(flag){
            ans[i] = '1';
            ans[i+1] = '0';
        }
        else
        {
            ans[i] = '0';
            ans[i+1] = '1';
        }
        i++;
        flag = !flag;
        n1--;
    }
    while(n0 > 0){
        ans[i] = '0';
        ans[i+1] = '0';
        i++;
        n0--;
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