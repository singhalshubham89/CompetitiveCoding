#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ll n, m;
    cin>>n>>m;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < n; i++){
        cin>>b[i];
    }
    ll low = 0, high = 1e18;
    ll prevmid = (low+high)/2, mid;
    while(low <= high){
        mid = (low+high)/2;
        ll ballons = 0;
        for(int i = 0; i < n; i++){
            ballons += max((ll)0 , a[i]-(mid/b[i]));
        }
        //cout<<low<<" "<<mid<<" "<<high<<" "<<ballons<<" "<<m<<endl;
        if(ballons <= m){
            high = mid-1;
            prevmid = mid;
        }else{
            low = mid+1; 
        }
        
    }
    cout<<prevmid;

}