#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int C, N;
	vector <int> chan_to_indice;
	
	vector <int> channels;
	int ch1, ch2;
	while( cin >> C )
	{
		channels.clear();
		chan_to_indice.clear();
		chan_to_indice.resize(1000, -1);
		for (int i=0; i<C; ++i)
		{
			cin >> ch1 >> ch2;
			for(int j=ch1; j<=ch2; ++j){
				chan_to_indice[j] = 1;
			}
		}
		int l = 0;
		for (int i=0; i<1000; ++i){
			if(chan_to_indice[i] != -1)
			{
				chan_to_indice[i] = l;
				l++;
			}
		}
		// l is the number of channels
		cin >> N;
		channels.resize(N, 0);
		for (int i=0; i<N; ++i)
		{
			cin >> chan_to_indice[ channels[i] ];
		}
		// Now this is basically Hamiltonian Path problem -_-
		// That's NP-complete btw
		// Could do it for every possible order with pruning I guess
		int S = 0;
		cin >> S;
		int totclicks = 0;

		int scroll;
		int z_to_scroll;

		int next_ch;

		for (int i=0; i<N; ++i)
		{
			next_ch = chan_to_indice[ channels[i] ];

			if (S >= next_ch )
			{
				scroll = min ( S - next_ch, next_ch + l - S );
			}
			else
			{
				scroll = min( next_ch - S , S + l - next_ch );
			}
			z_to_scroll = 2 + min( next_ch, abs(l - next_ch));
			
			totclicks += min( scroll, z_to_scroll );
			S = next_ch;
		}
		cout << totclicks << endl;
	}
}




















