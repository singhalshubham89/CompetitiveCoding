#include<bits/stdc++.h>
using namespace std;
void display(vector<int> a){
    for(int i = 0; i < a.size(); i++)
        cout<<a[i]<<" ";
}
void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < n; i++){
        cin>>b[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    int ans = 0;
    int i = 0, j = 0, last = a.size();

    while(k > 0 && i < last && j < b.size()){
        if(a[i] >= b[j]){
            ans += a[i];
            i++;
        }else{
            last--;
            ans += b[j];
            j++;
            k--;
        }
    }
    while(i < last){
        ans += a[i];
        i++;
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