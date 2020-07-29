#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int count = 0;
    int cmax = INT_MIN;
    int prev = -1;
    int prevval = 0;
    int inp;
    for(int i = 0; i < n; i++)
    {   
        cin>>inp;
        // if(i != 0)
        // {
            if(inp > prev)
            {
                
                if(prevval == -1)
                    count = 0;
                count++;
                prevval = 1;
            }
            else if(inp < prev)
            {
                
                 if(prevval == 1)
                    count = 0;
                count--;
                prevval = -1;
            }
                
        // }
        if(i == 0)
            count = 0;
        cout<<count<<" ";
        prev = inp;
        cmax = max(abs(count), cmax);
    }
    cmax = max(0, (cmax)/4);
    cout<<cmax<<endl;
}
int main(){

    int t;
    cin>>t;
    for(int i = 1; i <= t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }

}