#include<bits/stdc++.h>
using namespace std;
void display(vector<int> a){
    for(int i = 0; i < a.size(); i++)
        cout<<a[i]<<" ";
}
void solve(){
    long long n;
    long long ans = 0;
    long long prev=1;
    cin>>n;
    n /= 2;
    for(long long i =1; i <= n; i++){
        ans += (8*i*i);
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