#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void solve(){
    ll a, b, q, l, r;
    cin>>a>>b>>q;
    ll lcmnum = (a*b)/__gcd(a,b);
    vector<ll> lcmv(lcmnum);
    ll count = 0;
    for(int i = 0; i <lcmnum; i++){
        if(((i%a)%b) == ((i%b)%a)){
            //cout<<i<<" ";
            if(i == 0){
                lcmv[i] = 0;
            }else{
                lcmv[i] = lcmv[i-1];
            }
        }else{
            lcmv[i] = lcmv[i-1]+1;
        }
        
    }
    //cout<<endl;
    while(q--){
        cin>>l>>r;
        l--;
        ll k = l/lcmnum;
        ll countl = lcmv[lcmv.size()-1]*k;
        l = l - (lcmnum*k);
        countl += lcmv[l];
        
        k = r/lcmnum;
        ll countr = lcmv[lcmv.size()-1]*k;
        r = r - (lcmnum*k);
        countr += lcmv[r];
        cout<<countr-countl<<" ";
        //cout<<countr<<" "<<countl<<" "<<lcmv[lcmv.size()-1]<<endl;
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