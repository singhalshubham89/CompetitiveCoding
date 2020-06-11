#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        long long tom, tillvalue = 0, pow2 = 1;
        cin>>tom; 
        tillvalue = tom;
        while(tillvalue%2 == 0)
        {
            pow2++;
            tillvalue /= 2;
        }
        tom--;
        cout<<tom/(1<<pow2)<<endl;
    }
}