#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        vector<int> a(3);
        vector<int> b(3);
        vector<int> sub;
        vector<int> mul;
        vector<int> mulnotdiv;
        vector<int> p;
        int flag = 1;
        int ans = 0;
        for(int i = 0; i < 3; i++)
        {
            cin>>a[i];
        }
        for(int i = 0; i < 3; i++)
        {
            cin>>b[i];
            //sub[i] = b[i]-a[i];
           // mul[i] = b[i]/a[i];
            if(b[i] != a[i] ){
                if(b[i] != 0)
                {

                    if(b[i] < a[i]){
                        if(flag)
                        {
                            ans++;
                            flag = 0;
                        }
                        a[i] = 0;
                    }
                        
                    p.push_back(a[i]);
                    p.push_back(b[i]);
                    sub.push_back(b[i]-a[i]);
                    if( a[i] != 0 && b[i]%a[i] == 0) 
                        mul.push_back(b[i]/a[i]);
                    if(a[i] != 0)
                        mulnotdiv.push_back((int)ceil((double)(b[i])/(double)(a[i])));
                    
                }else if(b[i] == 0 && flag){
                    ans++;
                    flag = 0;
                }
            }
        }
        sort(sub.begin(), sub.end());

        if(p.size() == 6){
            if(sub[0] == sub[1] &&  sub[1] == sub[2])
            {
                ans += 1;
            }
            else if(mul.size() == 3 && mul[0] == mul[1] && mul[1] == mul[2]){
                ans += 1;
            }
            else if(sub[0] == sub[1] || sub[1] == sub[2] || sub[0] == sub[2] || (sub[1]-sub[0] == sub[2]-sub[1]))
            {
                ans += 2;
            }
            else if(mul.size() == 3 && (mul[0] == mul[1] || mul[1] == mul[2] || mul[0] == mul[2])){
                 ans += 2;
            }
            else if(mul.size() == 2 && mul[0] == mul[1]){
                ans += 2;
            }
            else if(a[1]-a[0] != 0 && a[2]-a[1] != 0 && (b[1]-b[0])%(a[1]-a[0]) == 0 && (b[2]-b[1])%(a[2]-a[1]) == 0 && (b[1]-b[0])/(a[1]-a[0])== (b[2]-b[1])/(a[2]-a[1])){
                ans += 2;
            }
            else{
                ans += 3;
            }
        }
        else if (p.size() == 4)
        {

            if((sub[0] == sub[1]) || (mul.size() == 2 && mul[0] == mul[1]))
            {
                ans += 1;
            }
            else
            {
                ans += 2;
            }
            
        }
        else if(p.size() == 2){
            ans += 1;
        }
        cout<<ans<<endl;
    }

}