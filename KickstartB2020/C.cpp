/*
Problem
Your country's space agency has just landed a rover on a new planet, which can be thought of as a grid of squares containing 109 columns (numbered starting from 1 from west to east) and 109 rows (numbered starting from 1 from north to south). Let (w, h) denote the square in the w-th column and the h-th row. The rover begins on the square (1, 1).

The rover can be maneuvered around on the surface of the planet by sending it a program, which is a string of characters representing movements in the four cardinal directions. The robot executes each character of the string in order:
N: Move one unit north.
S: Move one unit south.
E: Move one unit east.
W: Move one unit west.
There is also a special instruction X(Y), where X is a number between 2 and 9 inclusive and Y is a non-empty subprogram. This denotes that the robot should repeat the subprogram Y a total of X times. For example:
2(NWE) is equivalent to NWENWE.
3(S2(E)) is equivalent to SEESEESEE.
EEEE4(N)2(SS) is equivalent to EEEENNNNSSSS.

Since the planet is a torus, the first and last columns are adjacent, so moving east from column 109 will move the rover to column 1 and moving south from row 109 will move the rover to row 1. Similarly, moving west from column 1 will move the rover to column 109 and moving north from row 1 will move the rover to row 109. Given a program that the robot will execute, determine the final position of the robot after it has finished all its movements.

Input
The first line of the input gives the number of test cases, T. T lines follow. Each line contains a single string: the program sent to the rover.

Output
For each test case, output one line containing Case #x: w h, where x is the test case number (starting from 1) and w h is the final square (w, h) the rover finishes in.

Limits
Time limit: 10 seconds per test set.
Memory limit: 1GB.
1 ≤ T ≤ 100.
The string represents a valid program.
The length of each program is between 1 and 2000 characters inclusive.

Test set 1
The total number of moves the robot will make in a single test case is at most 104.

Test set 2
No additional constraints.

Sample

Input
 	
Output
 
4
SSSEEE
N
N3(S)N2(E)N
2(3(NW)2(W2(EE)W))

  
Case #1: 4 4
Case #2: 1 1000000000
Case #3: 3 1
Case #4: 3 999999995

  
In Sample Case #1, the rover moves three units south, then three units east.

In Sample Case #2, the rover moves one unit north. Since the planet is a torus, this moves it into row 109.

In Sample Case #3, the program given to the rover is equivalent to NSSSNEEN.

In Sample Case #4, the program given to the rover is equivalent to NWNWNWWEEEEWWEEEEWNWNWNWWEEEEWWEEEEW.

Analysis
To facilitate parsing of the program, let us define ClosingBracket(i) as the index of the closing bracket corresponding to the opening bracket at index i. We can find ClosingBracket(i) for each opening bracket using a stack in linear time, which is similar to checking whether a string is a correct bracket sequence or not, see this article for more details.

Test Set 1
The total number of moves is limited by 104 per test. Consider the expanded version of a program P to be the string consisting of characters N,S,W,E only and having the same moves as P. For example, the program 2(3(N)EW) would expand to NNNEWNNNEW. Since the number of moves is small, we can generate the expanded program, and calculate the position of the robot easily by taking one step at a time.

For an original subprogram between indices L and R, the equivalent expanded version Expanded(L, R) can be constructed recursively as follows. We start with an empty string Result, iterate the subprogram from the left index L to the right index R, and consider two cases:

If the i-th symbol is in {'N','S','E','W'}, append it to Result.
If the i-th symbol is a digit D then
Call Expanded(i+2, ClosingBracket(i+1)-1) to construct the expanded version P' of the next subprogram recursively,
Append P' to Result D times, and
Advance the current position i to ClosingBracket(i+1)+1.
The first case takes constant time. In the second case, it takes O(D × |P'|) time to append the subprogram P' to the result D times. Let LEN be the length of the expanded program. The total expanded length of the subprograms at the second nesting level is at most LEN/2. The total expanded length of subprograms at the third nesting level is at most LEN/4, and so on. Thus the time complexity would be bounded by LEN + LEN / 2 + LEN / 4 + LEN / 8 + .. which is equal to 2 × LEN as this is a geometric progression. Hence, the time complexity to generate the expanded version of the original program would be O(LEN).

Test Set 2
Now it is possible that the number of moves is exponential in the length of the original program. Thus it would be impossible to execute the moves one by one in the given time.

For the ease of explanation, let us assume that the rows and columns are numbered from 0 (inclusive) to 109 (exclusive). Suppose that the robot is at position (a, b) and now we come across instruction X(Y) in the program. Let us say subprogram Y changes the current position of the robot by dx, dy (because of the torus shape of Mars, we can assume that 0 ≤ dx < 109 and 0 ≤ dy < 109). Then the position of the robot after following the instruction X(Y) would be ((a + X * dx) mod 109, (b + X * dy) mod 109) as the subprogram Y is repeated X times. Hence, we just need to find the relative displacement of the robot by each subprogram.

For a subprogram between indices L and R, the relative displacement of the robot can be calculated using Evaluate(L, R) recursively as follows. Consider that we are currently at the square (a, b), which is initially the square (0, 0). Iterate the subprogram from the left index L to the right index R, and consider two cases:

If the i-th symbol is in {'N','S','E','W'}, change the current position of the robot accordingly.
If the i-th symbol is a digit D then
Call Evaluate(i+2, ClosingBracket(i+1)-1)to get the relative displacement (dx, dy) of the robot by the next subprogram recursively,
Change the current position to ((a + D * dx) mod 109, (b + D * dy) mod 109), and
Advance the current position i to ClosingBracket(i+1)+1.
Clearly, we visit each character in the program exactly once. Hence, the time complexity of the solution is O(N), where N is the length of the program.

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
    string s;
    cin>>s;
    vector<ll> total(2, 0);
    ll num = 1;
    ll mod = 1000000000;
    vector<ll> t;
    t.push_back(1);
    for(int i = 0; i < s.size(); i++){
         switch (s[i])
        {
        case 'N':
            total[0] = (total[0]-num+mod)%mod;
            break;
        case 'S':
            total[0] = (total[0]+num)%mod;;
            break;
        case 'W':
            total[1] = (total[1]-num+mod)%mod;
            break;
        case 'E':
           total[1] =(total[1]+num)%mod;;
            break;
        case '(':
            break;
        case ')':
            t.pop_back();
            num = t[t.size()-1];
            break;
        default:
            ll temp = (ll)(s[i]-'0');
            num = (num*temp)%mod;
            t.push_back(num);
            
        }
    }
    // while(total[0] < 0){
    //     total[0] += 1000000000;
    // }
    // while(total[1] < 0){
    //     total[1] += 1000000000;
    // }
    cout<<(total[1]%mod + 1)<<" "<<(total[0]%mod + 1)<<endl;
}
int main(){

    int t;
    cin>>t;
    for(int i = 1; i <= t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }

}