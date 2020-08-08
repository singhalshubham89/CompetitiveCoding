// Binary array:-  delete exactly one element
//  return longest subarry containing only onc

// 1 0 1 0 1 0 1
// // eg:- 1 1 1 0 1 1 1 0 1 1 0 1 0 1
// prev =7
// cur =7
// maxlength = 6
// first 7
// // return:- 6
// //eg :- 0 0 0 1 0 0 0 1 1 1 0
//

#include <bits/stdc++.h>
using namespace std;

int getLongestSubarry(vector<int> arr)
{
    int cur = 0;
    int prev = 0;
    int maxlength = 0;
    int firstzero = -1;
    bool zerofound = false;
    //(O(n)) //O(2n)
    for (cur = 0; cur < arr.size(); cur++)
    {
        if (arr[cur] == 0)
        {
            zerofound = true;
            if (firstzero == -1)
            {
                firstzero = cur;
            }
            else //second zero
            {
                // cout << cur << " " << prev << endl;
                maxlength = max(maxlength, cur - prev - 1);
                cur = firstzero;
                prev = firstzero + 1;
                firstzero = -1;
            }
        }
    }
    maxlength = max(maxlength, cur - prev - 1);
    if (zerofound == false)
        maxlength--;
    return maxlength;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << getLongestSubarry(arr);
}