#include<bits/stdc++.h>
using namespace std;



// void findmax(long long bits, long long &x, long long &y, long long cur, long long &l, long long &r){
//     if(bits < 0)
//         return;
//     while(bits >= 0 && cur&(1<<bits) == 0)
//         bits--;
//     if(bits < 0)
//         return;
    
//     long long bits0 = min(x&(cur^(1<<bits)), y&(cur^(1<<bits)));
//     long long bits1 = min(x&(cur), y&(cur));
//     if(bits0 > curmin && (cur^(1<<bits)) >= l && (cur^(1<<bits)) <= r){
//         ans = cur^(1<<bits);
//         curmin = bits0;
//     }
//     if(bits1 > curmin && cur >= l && cur <= r)
//     {
//         ans = cur;
//         curmin = bits1;
//     }
//     findmax(bits-1, x, y, cur^(1<<bits), l, r);
//     findmax(bits-1, x, y, cur, l, r);

// }
void solve(){   
    long long x, y, l ,r;
    cin>>x>>y>>l>>r;
    if(x == 0 || y == 0)
     {
         cout<<l<<endl;
         return;
     }   
    
    int ybits = log2(y)+1;
    long long finalans;
    long long curmin = -1;
    long long ans;
    long long curmax = -1; 
    finalans = x|y;
     if(finalans <= r && finalans >= l)
     {
        cout<<finalans<<endl;
        return;
     }else{
        //   for(long long i = l; i <= r; i++){
        //       if(i&finalans == 0)
        //         i *= 2;
        //       if(i <= r){
        //         if(min(i&x, i&y) > curmin){
        //             ans = i;
        //             curmin = min(i&x, i&y);
        //             curmax = max(i&x, i&y);
        //         }else if(min(i&x, i&y) == curmin && curmax < max(i&x, i&y)){
        //             ans = i;
        //             curmax = max(i&x, i&y);
        //         }
        //       }
        //   }
        ans = finalans;
        while(x > 0 && y > 0 && (ans > r || ans < l)){
            if(y >x)
                swap(y, x);
            int bit = log2(x);
            x = x-(1<<bit);
            if((y&(1<<bit)) > 0)
                y = y-(1<<bit);
            ans = x|y;
        }
          cout<<ans<<endl;
     }
}
int main(){

    int t;
    cin>>t;
    for(int i = 1; i <= t;i++){
        solve();
    }

}