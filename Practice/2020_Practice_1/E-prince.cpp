#include <iostream>
#include <vector>

using namespace std;

int main(){
	int T, n, p, q, tmp;
	vector <int> order;
	vector <int> seq;
	vector <int> s_len;
	cin >> T;
	for(int t=1; t<=T; ++t){
		cin >> n >> p >> q;
		order.clear();
		order.resize(n*n+1,0);
		seq.clear();
		s_len.clear();

		for(int i=1;i<= p+1;++i){
			cin >> tmp;
			order[tmp] = i;
		}
		for(int i=0; i<=q; ++i){
			cin >> tmp;
			if (order[tmp]){
				seq.push_back(order[tmp]);
			}
		}

		// Now start longest increasing subsequence
		s_len.push_back(0);
		// length 0 has min ending of 0 :P
		int lo, hi, mid;
		for(int i=0; i<seq.size(); ++i){
			
			// Bin search to find the smallest index seq[i] is smaller than
			
			lo = 0;
			hi = s_len.size()-1;
			while(lo<hi){
				mid = (lo + hi + 1)/2;
				if( s_len[mid] > seq[i] ) hi = mid-1;
				else lo = mid;
			}
			// Thing to replace is lo+1
			if( lo == s_len.size()-1 ){
				s_len.push_back(seq[i]);
			}else{
				s_len[lo+1] = seq[i];
			}

		}

		cout << "Case " << t << ": " << s_len.size()-1 << endl;

	}
}