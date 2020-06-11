#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        int num = 1;
        if (n % 2 == 0)
        {
            for(int i = 0; i < n; i++)
            {
                if(i%2 == 0){
                    for(int j = 0; j < n; j++)
                    {
                        cout<<num++<<" ";
                    }
                }
                else
                {
                    num += n-1;
                    for(int j = 0; j < n; j++)
                    {
                        cout<<num--<<" ";
                    }
                    num = (i+1)*n+1;
                }
                cout<<"\n";
            }
        }
        else
        {
            for(int i = 0; i < n ; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    cout<<num++<<" ";
                }
                cout<<"\n";
            }
        }
    }
}