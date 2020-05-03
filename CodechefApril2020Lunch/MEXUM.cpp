#include<bits/stdc++.h>
using namespace std;
/* int  count(int prev, int i, vector<int> &seq){
    
    if(i == seq.size())
        return prev+1;
    if(seq[i] != prev+1 && seq[i] != prev){
        return count(prev, i+1, seq)+count(prev, i+1, seq);
    }else
    {
        return count(seq[i], i+1, seq)+count(prev, i+1, seq);
    }
    
} */
int main(){

    int t;
    cin>>t;
    for(int i = 1; i <= t;i++){
        int n;
        cin>>n;
        vector<int> seq(n);
        for(int i = 0; i < n; i++){
            cin>>seq[i];
        }
        sort(seq.begin(), seq.end());
        long long ans = 1;
        long long prev = 0;
        for(long long i = 0; i < seq.size(); i++){
            if(prev+1 == (long long)(seq[i])){
                prev = (long long)(seq[i]);
            }
            ans += (i+1)*(prev+1);
        }
        cout<<ans<<endl;
    }

}