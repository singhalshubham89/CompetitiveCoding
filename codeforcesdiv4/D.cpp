#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<long long> candy(n);
    for(int i = 0; i < n; i++){
        cin>>candy[i];
    }
    long long a = 0, b = 0, m = 0, preva = 0, prevb = 0, consume = 0;
    int aindex = 0, bindex = n-1;
    while(aindex <= bindex){
        consume = 0;
        while( aindex <= bindex && prevb >= consume){
            consume +=  candy[aindex];
            aindex++;
        }
        if(consume > 0)
            m++;
        a += consume;
        preva = consume;
        //cout<<consume<<" ";
        consume = 0;
        while( aindex <= bindex && preva >= consume){
            consume +=  candy[bindex];
            bindex--;
        }
        if(consume > 0)
            m++;
        b += consume;
        prevb = consume;
        //cout<<consume<<endl;
    }
    cout<<m<<" "<<a<<" "<<b<<endl;
}
int main(){

    int t;
    cin>>t;
    for(int i = 1; i <= t;i++){
        solve();
    }

}