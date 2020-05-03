#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long  x, y;
    long long a,b;
    cin>>x>>y>>a>>b;
    long long ans;
    if((x > 0 && y < 0) || y>0 && x<0){
        ans = abs(x)+abs(y);
        ans = ans*a;
    }else{
        ans = (min(abs(x), abs(y)) * b) + (abs(x-y)*a);
        ans = min(ans,(abs(x)+abs(y))*a );
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