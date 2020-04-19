/*
Problem
Jemma is competing in a robotics competition. The challenge for today is to build a robot that can navigate around a hole in the arena.

The arena is a grid of squares containing W columns (numbered 1 to W from left to right) and H rows (numbered 1 to H from top to bottom). The square in the x-th column and y-th row is denoted (x, y). The robot begins in the top left square (1,1) and must navigate to the bottom right square (W, H).

A rectangular subgrid of squares has been cut out of the grid. More specifically, all the squares that are in the rectangle with top-left square (L, U) and bottom-right square (R, D) have been removed.

Jemma did not have much time to program her robot, so it follows a very simple algorithm:
If the robot is in the rightmost column, it will always move to the square directly below it. Otherwise,
If the robot is in the bottommost row, it will always move to the square directly right of it. Otherwise,
The robot will randomly choose to either move to the square directly to the right, or to the square directly below it with equal probability.

Jemma passes the challenge if her robot avoids falling into the hole and makes it to the square (W, H). What is the probability she passes the challenge?

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of a single line containing W, H, L, U, R and D.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is a real number between 0 and 1 inclusive, the probability that Jemma passes the challenge.

y will be considered correct if it is within an absolute or relative error of 10-5 of the correct answer. See the FAQ for an explanation of what that means, and what formats of real numbers we accept.

Limits
Time limit: 15 seconds per test set.
Memory limit: 1GB.
1 ≤ T ≤ 100.
1 ≤ U ≤ D ≤ H.
1 ≤ L ≤ R ≤ W.
Neither the top-left nor bottom-right squares will be missing.

Test set 1
1 ≤ W ≤ 300.
1 ≤ H ≤ 300.

Test set 2
1 ≤ W ≤ 105.
1 ≤ H ≤ 105.

Sample

Input
 	
Output
 
4
3 3 2 2 2 2
5 3 1 2 4 2
1 10 1 3 1 5
6 4 1 3 3 4

  
Case #1: 0.5
Case #2: 0.0625
Case #3: 0.0
Case #4: 0.3125

  
Analysis
Test Set 1
We can solve this test set using dynamic programming. Let f(x, y) be the probability Jemma passes the challenge if she is currently in the square (x, y). The base case of this function is f(W, H) = 1. Also, if the square (x, y) has been removed, then f(x, y) = 0.

If there is only one possible square to go to from square (x, y) (i.e. either x = W or y = H), then f(x, y) = f(x', y'), where (x', y') is the possible next square. Otherwise, let (x1', y1') and (x2', y2') be the possible next squares. Since they have the same probability to become the next square, f(x, y) = 0.5 × f(x1', y1') + 0.5 × f(x2', y2').

The running time and space of this solution is O(W × H).

Test Set 2
The first observation to solve this problem is to realize that there are two ways to avoid the hole: either going to the left and the bottom of the hole (illustrated by the red path in the figure below), or going to the top and the right of the hole (illustrated by the blue path in the figure below).


It can be seen that the set of paths in the red path and the blue path are disjoint--there is no path that goes both to the left of the hole and to the top of the hole simultaneously. Therefore, we can compute the probability that Jemma passes the challenge by taking the red path and the blue path separately and compute the sum of both probabilities.

Since the probability of passing the challenge by taking the blue path can be computed similarly, we only focus on computing the probability of passing the challenge by taking the red path for the rest of the discussion. The next observation to solve this problem is that we can choose a set of squares diagonally from the bottom-left corner of the hole (illustrated by the green squares below) such that Jemma has to pass exactly one of the squares to pass the challenge by taking the red path. Also, by landing on one of the squares, it is no longer possible that Jemma will fall to the hole, thus passing the challenge by taking the red path is now guaranteed.


Therefore, computing the probability of passing the challenge by taking the red path is equivalent to computing the probability that Jemma will land on one of the green squares. Similar to the red and blue paths discussion, since Jemma cannot pass two green squares simultaneously, we can compute the probability that Jemma lands on each square separately and compute the sum of all probabilities.

Let us take square X for an example. Consider all paths that go to the square X. For each move in the path, there is a 0.5 probability that the move will follow the path. Since the number of moves to square X is (L + D - 2), there is a (0.5)(L + D - 2) probability that this path will be taken. This number has to be multiplied with the number of paths to go to square X, which can be computed using a single binomial coefficient. The probability of reaching any particular green square is the same for all but the green square in the last row, which is left to the reader as an exercise.

To handle floating point issues, we can store every huge number in their log representation (i.e. storing log2(x) instead of x). We can then compute the value of C(n, k) / 2n using 2log2(n! / (k! × (n - k)!) / 2n) = 2log2(n!) - log2(k!) - log2((n - k)!) - n, which takes constant time to compute if we have precomputed every value of log2(x!). Since there can be at most O(N) green squares, where N is the larger length of the grid (i.e. N = max(H, W)), the total running time of this solution is O(N).
*/

#include<bits/stdc++.h>
using namespace std;
float backtrack(int x, int y, int l, int u, int r, int d){
    //cout<<x<<" "<<y<<endl;
    if( x < 0 || y <0 || x >= a.size() ||y >= a[0].size())
        return 1.0;
    if(a[x][y] != -1)
        return a[x][y];

    if(x+1 == a.size() && y+1 == a[0].size())
    {
        a[x][y] = 1.0;
        return 1.0;
    }else if(x+1 == a.size()){
        a[x][y] = backtrack(x, y+1, a);
        return  a[x][y];
    }else if(y+1 == a[0].size()){
        a[x][y] = backtrack(x+1, y, a);
        return  a[x][y];
    }
    float c = backtrack(x+1, y, a);
    float d = backtrack(x, y+1, a);
    a[x][y] = (c+d)/2;
    return (c+d)/2;
}
void solve(){
    int x, y, l, u, r, d;
    cin>>x>>y>>l>>u>>r>>d;
    
    cout<<backtrack(0,0,l,u,r,d)<<endl;
    
    
}
int main(){

    int t;
    cin>>t;
    for(int i = 1; i <= t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }

}