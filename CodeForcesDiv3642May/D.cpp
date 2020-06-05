#include<bits/stdc++.h>
using namespace std;
void display(vector<int> a){
    for(int i = 0; i < a.size(); i++)
        cout<<a[i]<<" ";
}
void solve(){
    int n;
    cin>>n;
    queue<pair<int, int>> q;
    vector<int> ans(n, 0);
    q.push({1, n});
    for(int i = 1; i <= n; i++){
        pair<int, int> p = q.front();
        q.pop();
        if(p.first != p.second){
            int mid;
            if((p.second - p.first +1)%2 == 1){
                 mid = (p.first+p.second)/2;
                 
            }
            else
            {
                mid = (p.first+p.second)/2;
            }
           
         
            int flag = 1;
            if(mid-1 >= p.first && mid-p.first >= p.second-mid){
                q.push({p.first, mid-1});
                flag = 0;
            }
            if(mid+1 <= p.second)
                q.push({mid+1, p.second});
            if(mid-1 >= p.first && flag)
                 q.push({p.first, mid-1});
            
           
            ans[mid-1] = i;
        }else{
            ans[p.first-1] = i;
        }
        
    }
    display(ans);
    cout<<endl;
}
int main(){

    int t;
    cin>>t;
    for(int i = 1; i <= t;i++){
        solve();
    }

}