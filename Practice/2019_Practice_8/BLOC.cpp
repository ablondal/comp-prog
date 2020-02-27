#include <iostream>
#include <vector>
// Complete, success
#include <string>
#include <cstring>

using namespace std;

int main()
{
	int T, M, N;
	vector<int> x, y;
	int Sx, Sy;
	string line;
	for (cin >> T; T > 0; T--)
	{
		cin >> M >> N;
		x.clear();
		y.clear();

		for(int i=0;i<M;++i)
		{
			cin >> line;
			for(int j=0;j<N;++j)
			{
				if ( line[j] == 'B' )
				{
					x.push_back(j);
					y.push_back(i);
				}
				else if ( line[j] == 'S' )
				{
					Sx = j;
					Sy = i;
				}
			}
		}

		int movesum = 0;
		for(int i = 0; i< x.size(); ++i)
		{
			movesum += 2*abs(x[i] - Sx) + 2*abs(y[i] - Sy);
		}
		cout << movesum << " seconds to blocks get!" << endl;
	}
}