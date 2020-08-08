//
// array of  integers of even length int k divide:-  array n/2 pairs
// 6 :- 3
//pair such that sum of each pair is divisible by k
//if all pairs exist true else false
//
// (a+b)
// a:- 6    k =2
//furst :- a%k = 0

//inpu :- 1 2 1 0 0 4 5, k = 2
//4 0 1 2 3 3 0 1 2
// 0 1 2
// 0:- is not even
// i+k-i

#include <bits/stdc++.h>
using namespace std;
bool isKDividePair(vector<int> arr, int k)
{
    vector<int> freqArr(k, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        freqArr[arr[i] % k]++;
    }
    // k:- odd or k:- even
    if (freqArr[0] % 2 == 1)
    {
        return false;
    }
    for (int i = 1; i < ceil(k / 2); i++)
    {
        if ((freqArr[i] + freqArr[k - i]) % 2 == 1)
            return false;
    }
    // 3:- 0 1 2
    if (k % 2 == 0 && freqArr[k / 2] % 2 == 1)
    {
        return false;
    }
    return true;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << isKDividePair(arr, k);
}