#include<bits/stdc++.h>
using namespace std;
bool check(char ele,  vector<vector<char>> &a,  vector<vector<char>> &b){
    vector<vector<char>> c = b;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[0].size(); j++){
            if(a[i][j] == ele){
                if((i == 0) ||(c[i-1][j] != '.' ) || a[i-1][j] == ele)
                    c[i][j] = ele;
                else if(c[i-1][j] == '.')
                    return false;
            }
        }
    }
    b = c;
    return true;
}
void solve(){
    int r, c;
    cin>>r>>c;
    unordered_set<char> s;
    
    vector<vector<char>> a(r, vector<char>(c,'.'));
    vector<vector<char>> b(r, vector<char>(c,'.'));
    for(int i  = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin>>a[i][j];
            s.insert(a[i][j]);
        }
    }
    string ans;
    int flag = 1;
    while(flag){
        if(s.size() == 0)
            break;
        flag = 0;
        unordered_set<char> safter;
        for(auto itr = s.begin(); itr!= s.end(); ++itr){
            if(check(*itr, a, b)){
                flag = 1;
                ans.push_back(*itr);

            }
            else{
                safter.insert(*itr);
            }
        }
        s = safter;
    }
    if(flag){
        reverse(ans.begin(), ans.end());
        cout<<ans<<endl;
    }
    else
    {
            cout<<"-1"<<endl;
    }
    
}
int main(){

    int t;
    cin>>t;
    for(int i = 1; i <= t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }

}