#include<bits/stdc++.h>
using namespace std;
void display(vector<int> a){
    for(int i = 0; i < a.size(); i++)
        cout<<a[i]<<" ";
}
void solve(){
    int n, m;
    cin>>n>>m;
    if(n == 1)
        cout<<0;
    else if(n == 2)
        cout<<m;
    else{
        cout<<(2*m);
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