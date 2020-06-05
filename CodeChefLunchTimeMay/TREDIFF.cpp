#include<bits/stdc++.h>
using namespace std;
vector<int> find( vector<int>& parent, int index){
    vector<int> factor;
    factor.push_back(index);
    while(parent[index] != -1){
        index = parent[index];
        factor.push_back(index);
    }
    return factor;
}
void solve(){
    int n, q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    vector<int> parent(n, -1);
    int value, index;
    for(int i = 0; i < n-1; i++){
        cin>>value>>index;
        if(value > index)
            swap(value, index);
        parent[index-1] = value-1;
    }
    while(q--){
        int src, dest;
        cin>>src>>dest;
        vector<int> s = find(parent, src-1);
        vector<int> d = find(parent, dest-1);
        for(int k = s.size()-1, l = d.size()-1; k > 0 && l > 0 ; k--, l-- ){
          
            if(s[k-1] != d[l-1])
                break;
            //cout<<s[k]<<" "<<d[l]<<endl;
            s.pop_back();
            d.pop_back();
        }
        multiset<int> ord;
        for(int i = 0; i < s.size()-1; i++){
            //cout<<s[i]<<" ";
            ord.insert(a[s[i]]);
        }
        //cout<<endl;
        for(int i = 0; i < d.size(); i++){
            //cout<<d[i]<<" ";
            ord.insert(a[d[i]]);
        }
        //cout<<endl;
        auto itr = ord.begin();
        int p = *itr;
        ++itr;
        int ans = INT_MAX;
        while(itr != ord.end()){
            if(ans > (*itr - p)){
                ans = (*itr - p);
            }
            if(ans == 0)
                break;
            p = *itr;
            ++itr;
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