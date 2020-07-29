#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, p;
    cin>>n>>p;
    //cout<<n<<" "<<p<<endl;
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int inp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j+= 2)
        {
            if(j+1 == n)
            {
                cout<<"1 "<<i+1<<" "<<j+1<<" "<<i+1<<" "<<j+1<<endl;
                cin>>inp;
                if(inp == 1)
                    ans[i][j] = 1;
            }
            else
            {
                cout<<"1 "<<i+1<<" "<<j+1<<" "<<i+1<<" "<<j+2<<endl;
                cin>>inp;
                if(inp == 2)
                {
                    ans[i][j] = ans[i][j+1] = 1;
                }
                else if(inp == 1)
                {
                    cout<<"1 "<<i+1<<" "<<j+1<<" "<<i+1<<" "<<j+1<<endl;
                    cin>>inp;
                    if(inp == 1)
                        ans[i][j] = 1;
                    else
                    {
                        ans[i][j+1] = 1;
                    }
                    if(inp == -1)
                        exit(0);
                    
                } else if(inp == -1)
                {
                    exit(0);
                }
                
            }
            
        }
    }
    // queue<vector<int>> q;
    // int inp;
    // q.push({0, 0, n-1, n-1});
    // while(q.size() > 0 ){
    //     vector<int>ele = q.front();
    //     q.pop();
    //     cout<<"1 "<<ele[0]+1<<" "<<ele[1]+1<<" "<<ele[2]+1<<" "<<ele[3]+1<<endl;
    //     cin>>inp;
    //     if(inp > 0){
    //         int dist = (ele[2]-ele[0]+1)*(ele[3]-ele[1]+1);
    //         if(dist == inp){
    //             for(int i = ele[0]; i <= ele[2]; i++){
    //                 for(int j = ele[1]; j <= ele[3]; j++){
    //                     ans[i][j] = 1;
    //                 }
    //             }
    //         }
    //         else{
    //             if(dist == 2)
    //             {
    //                 cout<<"1 "<<ele[0]+1<<" "<<ele[1]+1<<" "<<ele[0]+1<<" "<<ele[1]+1<<endl;
    //                 cin>>inp;
    //                 if(inp == 1)
    //                     ans[ele[0]][ele[1]] = 1;
    //                 else
    //                 {
    //                      ans[ele[2]][ele[3]] = 1;
    //                 }
    //             }
    //             else{
    //                 int newx = (ele[0]+ele[2])/2;// 1
    //                 int newy = (ele[1]+ele[3])/2; // 1
    //                 q.push({ele[0], ele[1], newx, newy}); // 0 0 1 1
    //                 q.push({newx+1, newy+1, ele[2], ele[3]}); // 1 1 3 3
    //                 q.push({ele[0], newy+1, newx, ele[3]}); // 0 1 1 3
    //                 q.push({newx+1, ele[1], ele[2], newy}); // 1 0 3 1
    //             }
                
    //         }
    //     }
    //     if(inp == -1)
    //         exit(0);
    // }
    cout<<"2\n";
     for(int i = 0; i < n; i++){
        for(int j = 0; j < n ; j++){
            cout<<ans[i][j]<<" ";
        }
        if(i != n-1)
            cout<<"\n";
     }
     cout<<endl;
     cin>>inp;
     //cout<<"INP: "<<inp<<endl;
     if(inp == -1)
        exit(0);
}
int main(){

    int t;
    cin>>t;
    for(int i = 1; i <= t;i++){
        solve();
    }

}