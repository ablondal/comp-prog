#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<unordered_map>
#include<utility>
#include<string>
#include<cmath>
#include<algorithm>

#include<stdlib.h>
#include<string.h>

using namespace std;

const int maxn = 100010;
const int INF = 998244353;

long long f[maxn][11];  // number of rainbows when i-th number equals j

void init() {
	for (int i = 0; i <= 9; ++i)
		f[1][i] = 1;

	for (int i = 2; i < maxn; ++i) 
		for (int j = 0; j <= 9; ++j) {
			for (int k = 0; k <= 9; ++k)
				if (k != j)
					f[i][j] = (f[i][j] + f[i - 1][k]) % INF;
		}
}

long long dp(string str) {
	// no leading zero string

	if (str.size() == 1 and str[0] == '0') return 0;

	// number
	int s_len = str.size();
	vector<int> nums(s_len);
	for (int i = 0; i < s_len; ++i) {
		nums[i] = str[s_len - 1 - i] - 48;
	}

	long long res = 0;
	int last = -1;

	for (int i = nums.size() - 1; i >= 0; i--) {
		int x = nums[i];
		for (int j = (i == nums.size() - 1); j < x; j++) {
			if (j != last)
				res = (res + f[i + 1][j]) % INF;
		}

		if (x == last) break;

		last = x;

		if (i == 0) res = (res + 1) % INF;

	}

	// leading zero case
	for (int i = 1; i < nums.size(); i++)
		for (int j = 1; j <= 9; j++)
			res = (res + f[i][j]) % INF;

	return res;
}



int main(void) {

	init();

	string l, u;

	cin>>l;
	cin>>u;

	// let l = l - 1
	int k = l.size() - 1;
	while (l[k] == '0') {
		l[k] = '9';
		k--;
	}
	l[k] = l[k] - 1;
	k = 0;
	while (k < l.size() - 1 && l[k] == '0')
		k++;
	l = l.substr(k, l.size() - k);

	// ans
	cout<<(dp(u) - dp(l) + INF) % INF <<endl;

	return 0;
}