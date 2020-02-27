#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int T;
	int N,M,K;
	cin >> T;
	for(int c=1; c<=T; ++c){
		cin >> N >> M >> K;
		vector <vector <int> > P(N, vector<int>(M));
		for(int i=0; i<N; ++i){
			for(int j=0; j<M; ++j){
				cin >> P[i][j];
			}
		}

		// Max subsequence sum, but 2d
		// O(n^3) should work ez
		int area, maxarea=0, psum, beg;
		int minprice = 0;
		vector <int> MM(M);
		for(int lo=0; lo<N; ++lo){
			fill(MM.begin(),MM.end(),0);
			for(int hi=lo; hi<N; ++hi){

				for(int j=0; j<M; ++j){
					MM[j] += P[hi][j];
				}
				area = 0;
				beg = 0;
				psum = 0;
				for(int end=0; end<M; ++end){
					psum += MM[end];
					while(psum>K){
						psum -= MM[beg];
						beg++;
					}
					area = (hi-lo+1) * (end-beg+1);
					if( area > maxarea || (area == maxarea && psum < minprice) ){
						maxarea = area;
						minprice = psum;
					}
				}
			}
		}
		cout << "Case #" << c << ": " << maxarea << " " << minprice << endl;
	}
}














