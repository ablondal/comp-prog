#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include<unordered_map>

using namespace std;

long long maxPriceFinder(long long day, vector<long long> prices, unordered_map<long long,long long> current)
{
	if (day == prices.size())
	{
		return current[0];
	}
	unordered_map<long long, long long> temp;
	int index = 0;
	for (auto& it : current)
	{
		long long x = it.second + index*prices[day];
		long long repeat = x / prices[day];
		
		for (long long i = 0; i <= repeat; i++)
		{
			if (temp.count(i))
			{
				if (temp[i] < x) temp[i] = x;
			}
			else temp.insert({ i, x });
			x -= prices[day];
		}
		++index;
	}

	return maxPriceFinder(day+1, prices, temp);
}

int main()
{
	//Daydreaming Stockbroker//
	//Goes back in time with 100$
	//Must buy whole shares, total number of shares is 100000 so Gina cannot own more than that
	//No fees, prices change once a day, trading does not influence stock evaluation even though she is buying fucking all of it
	
	//First input is # of days Gina goes back in time
	//The following d inputs are the prices of stocks on that day
	long long days,temp;
	vector<long long> prices;
	unordered_map<long long, long long> current;
	current.insert({ 0, 100 });

	cin >> days;
	for (long long i = 0; i < days; i++)
	{
		cin >> temp;
		prices.push_back(temp);
	}
	cout << maxPriceFinder(0, prices, current);
	return 0;
}