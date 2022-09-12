#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
#define mk(v,n,type)  type *v=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

struct interval
{
	int size;
	std::vector<int> arr;

};
void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}
void SieveOfEratosthenes(int n)
{
	// Create a boolean array "prime[0..n]" and initialize
	// all entries it as true. A value in prime[i] will
	// finally be false if i is Not a prime, else true.
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));

	for (int p = 2; p * p <= n; p++) {
		// If prime[p] is not changed, then it is a prime
		if (prime[p] == true) {
			// Update all multiples of p greater than or
			// equal to the square of it numbers which are
			// multiple of p and are less than p^2 are
			// already been marked.
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}

	// Print all prime numbers
	for (int p = 2; p <= n; p++)
		if (prime[p])
			cout << p << " ";
}

int PositionRightmostSetbit(int n)
{
	int p = 1;

	// Iterate till number>0
	while (n > 0)
	{

		// Checking if last bit is set
		if (n & 1) {
			return p;
		}

		// Increment position and right shift number
		p++;
		n = n >> 1;
	}

	// set bit not found.
	return -1;
}
int BitsSetTable256[256];

// Function to initialise the lookup table
void initialize()
{

	// To initially generate the
	// table algorithmically
	BitsSetTable256[0] = 0;
	for (int i = 0; i < 256; i++)
	{
		BitsSetTable256[i] = (i & 1) +
		                     BitsSetTable256[i / 2];
	}
}

// Function to return the count
// of set bits in n
int countSetBits(int n)
{
	return (BitsSetTable256[n & 0xff] +
	        BitsSetTable256[(n >> 8) & 0xff] +
	        BitsSetTable256[(n >> 16) & 0xff] +
	        BitsSetTable256[n >> 24]);
}



int solve(string A, int i, int dp[301], unordered_set <string>& mp)
{
	if (i == A.size())
		return true;
	if (dp[i] != -1)
		return dp[i];
	for (int k = i; k < A.size(); k++)
	{
		string str = A.substr(i, k - i + 1);
		auto c = mp.find(str);
		if (c != mp.end() && solve(A, k + 1, dp, mp))
		{
			cout << str << endl;
			return dp[i] = true;
		}

	}
	return dp[i] = false;
}
bool wordBreak(string s, vector<string>& wordDict) {

	unordered_set<string> mp;
	for (int i = 0; i < wordDict.size(); i++)
	{
		mp.insert({wordDict[i]});
	}
	int dp[301];
	memset(dp, -1, sizeof(dp));
	return solve(s, 0, dp, mp);
}
// int solve(vi v, int n)
// {
// 	int dp[n];
// 	dp[n - 1] = v[n - 1];
// 	int dp2[n];
// 	int maxm = 0;
// 	for (int i = n - 2; i >= 0; i--)
// 	{
// 		dp[i] = v[i] + v[i + 1];

// 	}

// 	int k = 1;
// 	for (int i = n - 1; k <= 3 && i >= 0; i--, k++)
// 	{
// 		dp2[i] = dp[i];
// 		cout << i << endl;
// 	}
// 	for (int i = n - 4; i >= 0; i--)
// 	{
// 		dp2[i] = dp[i] + dp2[i + 3];
// 	}
// 	for (int i = 0; i < n; i++)
// 	{
// 		cout << dp[i] << " " << dp2[i] << endl;
// 	}
// }
bool cmp(pair<int, int>p1, pair<int, int>p2)
{
	return p1.first < p2.first;
}


int32_t main()
{
	c_p_c();


	w(x)
	{

		string str;
		map<char, vector<int> >mp;
		cin >> str;
		int count = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			mp[str[i]].push_back(i + 1);
		}
		int first = str[0] - str[str.size() - 1];
		auto c = mp.find(str[0]);
		auto final = mp.find(str[str.size() - 1]);

		int	diff = first > 0 ? -1 : 1;

		int cost = 0, j = 0;
		vector<int> jumps;
		while (c != final)
		{

			for (auto &ind : c->second) {
				jumps.push_back(ind);
				j++;
			}

			if (diff > 0) {
				c++;
			}
			else {
				c--;
			}
			//c += diff;

		}

		for (auto ind : final->second) {
			jumps.push_back(ind);
			j++;
		}

		cout << abs(first) << " " << j << endl;
		for (auto ind : jumps) {
			cout << ind << " ";
		}

		cout << endl;

	}





}
