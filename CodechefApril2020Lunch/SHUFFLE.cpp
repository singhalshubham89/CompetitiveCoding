#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, k;
    cin>>n>>k;
    vector<vector<int>> karray(k);
    vector<int> A;
    int t;
    for(int i = 0; i  < n; i++){
        cin>>t;
        karray[i%k].push_back(t);
    }
    for(int i = 0; i < k; i++){
        sort(karray[i].begin(), karray[i].end());
    }
    int aflag = 1;
    int prev = 0;
    for(int i = 0 ; i < n/k && aflag; i++){
        for(int j = 0; j < k && aflag; j++){
            if(i < karray[j].size()){
                //cout<<karray[j][i]<<" ";
                if(prev > karray[j][i]){
                    aflag = 0;
                    break;
                }
                
                prev = karray[j][i];
            }
            else
            {
                break;
            }
        }
    }
    //cout<<endl;
    if(aflag)
        cout<<"yes"<<endl;
    else
    {
        cout<<"no"<<endl;
    }
    
    // int bflag = 1, aflag =1;
    // for(int i = 1; i < n; i++){
    //     if(A[i] < A[i-1]){
    //         aflag = 0;
    //         break;
    //     }
    // }
    // for(int i = 1; i < n && !aflag; i++){
    //     if(B[i] > B[i-1]){
    //         bflag = 0;
    //         break;
    //     }
    // }
    // if(bflag || aflag)
    //     cout<<"yes"<<endl;
    // else
    // {
    //         cout<<"no"<<endl;
    // }
    
}
int main(){

    int t;
    cin>>t;
    for(int i = 1; i <= t;i++){
        solve();
    }

}