#include<bits/stdc++.h>
using namespace std;
void solve(){
    string inp;
    int pairs = 0;
    cin>>inp;
    for(int i = 0; i < inp.size()-1; i++)
    {
        if((inp[i] == 'x' && inp[i+1] == 'y') || (inp[i] == 'y' && inp[i+1] == 'x'))
        {
            pairs++;
            i++;
        }    
        
    }
    cout<<pairs<<endl;
}
int main(){

    int t;
    cin>>t;
    for(int i = 1; i <= t;i++){
        solve();
    }

}