#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector <pair <int, int> > req;
vector <bool> Y, N;


int p_lounge( int i ){
	if (i == req.size()) return 0;
	int min = 1e9;
	bool py1, py2, pn1, pn2;
	py1 = Y[req[i].first];
	py2 = Y[req[i].second];
	pn1 = N[req[i].first];
	pn2 = N[req[i].second];
	if ( 
		(py1 && !py2) ||
		(pn2 && !pn1) )
	{
		Y[req[i].first] = true;
		N[req[i].second] = true;
		min = p_lounge( i+1 );
		Y[req[i].first] = py1;
		N[req[i].second] = pn2;
		if (!py1) min++;
		return min;
	}

	if ( 
		(py2 && !py1) ||
		(pn1 && !pn2) )
	{
		Y[req[i].second] = true;
		N[req[i].first] = true;
		min = p_lounge( i+1 );
		Y[req[i].second] = py2;
		N[req[i].first] = pn1;
		if (!py2) min++;
		return min;
	}

	if ( !py1 && !py2 && !pn1 && !pn2 ){
		Y[req[i].first] = true;
		N[req[i].second] = true;
		min = p_lounge( i+1 );
		Y[req[i].first] = py1;
		N[req[i].second] = pn2;

		Y[req[i].second] = true;
		N[req[i].first] = true;
		int min2 = p_lounge( i+1 );
		Y[req[i].second] = py2;
		N[req[i].first] = pn1;
		if (min2 < min) min = min2;
		return min + 1;
	}
	return min;

}


int main(){
	int n, m;
	cin >> n >> m;
	int t1, t2, c;
	Y.resize(n+1,0);
	N.resize(n+1,0);
	int n_lounge = 0;
	for (int i=0; i<m; ++i){
		cin >> t1 >> t2 >> c;
		if( c == 0 ){
			N[t1] = true;
			N[t2] = true;
		}else if ( c == 2 ){
			Y[t1] = true;
			Y[t2] = true;
		}else{
			if (t1 < t2)
				req.push_back( make_pair(t1,t2) );
			else
				req.push_back( make_pair(t2,t1) );
		}
		if ( (N[t1] && Y[t1]) || (N[t2] && Y[t2]) ){
			cout << "impossible" << endl;
			return 0;
		}
	}

	for(int i=1; i<=n; ++i){
		if (Y[i]) n_lounge++;
	}

	sort(req.begin(), req.end(), [](pair <int, int> &a, pair <int, int> &b){return (a.first==b.first) ? a.second < b.second : a.first < b.first;});

	n_lounge += p_lounge( 0 );

	if (n_lounge > 1e8) cout << "impossible" << endl;
	else cout << n_lounge << endl;

}