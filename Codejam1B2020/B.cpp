#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    int a, b;
    cin >> t >> a >> b;
    string ans;
    while (t--)
    {

        int flag = 0;
        pair<int, int> hstart, hend;
        int hflag = 0;
        for (int i = -50; i <= 50; i++)
        {
            cout << i << " " << i << endl;
            cin >> ans;
            if (ans == "CENTER")
            {
                flag = 1;
                break;
            }
            else if (ans == "HIT")
            {
                if(hflag == 0){
                    hstart = {i, i};
                    hflag = 1; 
                }
            }
            else if (ans == "MISS")
            {
                if(hflag == 1){
                    hend = {i, i};
                    break;
                }
            }
            else
            {
                exit(0);
            }
        }
        if(!flag){
            int x = (hstart.first-hend.first)/2;
            int y = (hstart.second-hend.second)/2;
        }
        
    }
}