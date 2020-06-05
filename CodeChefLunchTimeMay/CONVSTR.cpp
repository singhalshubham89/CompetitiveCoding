#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    string a, b;
    cin>>a>>b;
    vector<vector<int>> ans;
    vector<int> temp;
    int flag = 0;
    int bflagindex, bflag = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 'b')
            bflagindex = i;
        if(b[i] == 'b' && a[i] == 'b' && bflag >= 0)
        {
            temp.push_back(i);
            bflag = -1;
        }
        if(b[i] == 'b' && a[i] > 'b')
            temp.push_back(i);
        if(b[i] == 'b' && a[i] < 'b')
        {
            flag = 1;
            break;
        }
    }
    //cout<<flag<<" flag\n";
    if(!flag){
        if(bflag >= 0 && temp.size() > 1)
            temp.push_back(bflagindex);
        if(temp.size() > 1)
            ans.push_back(temp);
        bflag = 0;
        temp.clear();
        for(int i = 0; i < b.size(); i++){
            
            if(b[i] == 'a' && a[i] == 'a' && bflag == 0)
            {
                temp.push_back(i);
                bflag = -1;
            }
            if(b[i] == 'a' && a[i] > 'a')
                temp.push_back(i);
        }
        if(bflag == 0)
            flag = 1;
        else if(temp.size() > 1)
        {
            ans.push_back(temp);    
        }
    }
    
    
    /* vector<vector<int>> fb(26);
    vector<vector<int>> fa(26);
    for(int i = 0; i < n; i++){
       fa[(int)(a[i]-'a')].push_back(i);
    }
    for(int i = 0; i < n; i++){
       fb[(int)(b[i]-'a')].push_back(i);
    }
    int flag = 0;
    vector<vector<int>> ans;
    for(int i = 25; i >= 0 && flag == 0; i--){
        if(fb[i].size() > 0 && flag == 0){
            char c =(char)('a'+i);
            vector<int> e = fb[i];
            int eflag = 0;
            for(int j = 0; j < e.size(); j++){
                if(a[e[j]] < c){
                    flag = 1;
                    break;
                }else if(a[e[j]] == c){
                    eflag = 1;
                }
                a[e[j]] = c;
            }
            ans.push_back(fb[i]);
            if(eflag == 0){
                if(fa[i].size() > 0){
                     ans[ans.size()-1].push_back(fa[i][fa[i].size()-1]);
                }
                else{
                    flag = 1;
                    break;
                }
            }
        }
    } */
    // vector<vector<int>> f(26);
    // for(int i = 0; i < n; i++){
    //    f[(int)(b[i]-'a')].push_back(i);
    // }
    // vector<vector<int>> ans;
    // int flag = 0;
    // for(int i = 25; i >= 0 && flag == 0; i--){
    //     if(f[i].size() > 0){
    //         char c =(char)(i+'a');
    //         vector<int> temp = f[i];
    //         // char mxch;
    //         char mnch;
    //         for(int j = 0; j < temp.size(); j++){
    //             if(j == 0)
    //             {
    //                 //mxch = a[j];
    //                 mnch = a[temp[j]];
    //             }
    //             // if(mxch < a[j]){
    //             //     mxch = a[j];
    //             // }
    //             if(mnch > a[temp[j]])
    //                 mnch =a[temp[j]];
    //             //a[j] = c;
    //          }
    //         if(mnch != c)
    //         {
    //             flag = 1;
    //             break;
    //         }
    //         else{
    //             ans.push_back(temp);
    //         }
    //     }
    // }
    if(flag)
        cout<<-1<<endl;
    else{
        cout<<ans.size()<<endl;
        for(int i = 0; i < ans.size(); i++){
            cout<<ans[i].size();
            for(int j = 0; j < ans[i].size(); j++){
                cout<<" "<<ans[i][j];
            }
            cout<<endl;
        }
    }
    
}
int main(){

    int t;
    cin>>t;
    for(int i = 1; i <= t;i++){
        solve();
    }

}