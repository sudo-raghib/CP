#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define w(x)            int x; cin>>x; while(x--)
void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
void nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	unordered_map<int, int> mp;
	vector<int> v;
	for (int i = 0; i < nums2.size(); i++)
	{
		mp.insert({nums2[i], i});
	}
	for (int i = 0; i < nums1.size(); i++)
	{
		bool check = true;
		int value = nums1[i];
		auto c = mp.find(value);
		for (int j = c->second; j < nums2.size(); j++)
		{

			if (nums2[j] > value)
			{
				check = false;
				v.push_back(nums2[j]);
				break;
			}

		}
		if (!check)
			v.push_back(-1);

	}


}
int binarySearch(int array[], int x, int low, int high) {

	// Repeat until the pointers low and high meet each other
	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (array[mid] == x)
			return mid;

		if (array[mid] < x)
		{
			if (array[mid] < 0)
			{
				low = mid + 1;
			}
			else if (mid + 1 < high && array[mid + 1] <= x)
			{
				low = mid + 1;
			}
			else
				return mid;

		}
		else
			high = mid - 1;
	}

	return -1;
}

int32_t main()
{
	c_p_c();

	w(x)
	{

		int a, b, c;
		cin >> a >> b >> c;
		int temp = abs(a - 1);
		int temp2 = abs(b - c) + abs(c - 1);
		if (temp < temp2)
			cout << 1 << endl;
		else if (temp2 < temp)
			cout << 2 << endl;
		else
			cout << 3 << endl;


	}

}
