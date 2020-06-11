#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
     int st = 1;
     int end = n;
    while(st <= end)
    {
        int mid = (st+end)/2;
        vector<char> reply(5);
        cout<<mid<<endl;
        cin>>reply[0];
        if(reply[0] == 'E')
            break;
        cout<<mid<<endl;
        cin>>reply[1];
         if(reply[1] == 'E')
            break;
        cout<<mid<<endl;
        cin>>reply[2];
         if(reply[2] == 'E')
            break;
        cout<<st<<endl;
        cin>>reply[3]; 
        if(reply[3] == 'E')
            break;
        cout<<st<<endl;
        cin>>reply[4]; 
        if(reply[4] == 'E')
            break;
        char finalreply = reply[0];
        if(reply[0] == reply[1])
        {
            finalreply = reply[0];
        }
        else if(reply[1] == reply[2])
        {
            finalreply = reply[1];
        }
        else if(reply[3] == 'L' && )//false
        {
            finalreply = reply[2];
        }
        else if(reply[3] == 'G')
        {
            finalreply = reply[1];
        }
        if(finalreply == 'G')
        {
            st = mid+1;
        }
        else
        {
            end = mid-1;
        }
        
    }
    
}
int main(){

    solve();

}