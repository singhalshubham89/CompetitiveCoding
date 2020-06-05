#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main()
{
	FIO;
	int tc; cin >> tc;
	for (int tnum = 1; tnum <= tc; ++tnum)
	{
		bool done = 0;

		int x, y; cin >> x >> y;
		string s; cin >> s;

		if (x == 0 && y == 0)
		{
			cout << "Case #" << tnum << ": " << 0 << '\n';
			continue;
		}

		for (int i = 0; i < s.length(); ++i)
		{

			char ch = s[i];

			if (ch == 'N')
				y++;
			else if (ch == 'S')
				y--;
			else if (ch == 'E')
				x++;
			else
				x--;

			//cout << x << ' ' << y << '\n';

			if (abs(x) + abs(y) <= i + 1)
			{
				cout << "Case #" << tnum << ": " << i + 1 << '\n';
				done = 1;
				break;
			}
		}


		if (!done)
			cout << "Case #" << tnum << ": " << "IMPOSSIBLE" << '\n';
	}
	return 0;
}