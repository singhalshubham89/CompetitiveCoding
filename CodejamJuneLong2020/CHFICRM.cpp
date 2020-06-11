#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> coins = {0, 0, 0};//5 coins 10 coins 15 coins
    vector<int> cust(n);
    int flag = 1;
    for(int i = 0; i < n; i++){
        cin>>cust[i];
    }
    for(int i = 0; i < n && flag; i++){
        if(cust[i] == 5){
            coins[0]++;
        }
        else if (cust[i] == 10){
            if(coins[0] == 0){
                flag = 0;
                break;
            }
            else{
                coins[0]--;
                coins[1]++;
            }
        }
        else{
            if(coins[0] <= 1 && coins[1] == 0){
                flag = 0;
                break;
            }
            else if(coins[1] > 0){
                coins[1]--;
            }
            else{
                coins[0] -= 2;
            }
        }
    }
    if(flag)
        cout<<"YES\n";
    else
    {
        cout<<"NO\n";
    }
    
}
int main(){

    int t;
    cin>>t;
    for(int i = 1; i <= t;i++){
        solve();
    }

}