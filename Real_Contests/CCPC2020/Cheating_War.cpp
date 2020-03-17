#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

// DONE, stupid

int main(){
	vector <int> mine(13,0);
	vector <int> yours(13,0);
	int C;
	char inp;
	for(cin>>C;C>0;--C){
		mine.clear();
		mine.resize(13,0);
		yours.clear();
		yours.resize(13,0);
		for(int i=0;i<26;++i){
			cin >> inp;
			if (inp<='9' && inp>='2'){
				yours[inp-'2']++;
			}else if(inp=='T'){
				yours[8]++;
			}else if(inp=='J'){
				yours[9]++;
			}else if(inp=='Q'){
				yours[10]++;
			}else if(inp=='K'){
				yours[11]++;
			}else if(inp=='A'){
				yours[12]++;
			}
		}
		for(int i=0;i<26;++i){
			cin >> inp;
			if (inp<='9' && inp>='2'){
				mine[inp-'2']++;
			}else if(inp=='T'){
				mine[8]++;
			}else if(inp=='J'){
				mine[9]++;
			}else if(inp=='Q'){
				mine[10]++;
			}else if(inp=='K'){
				mine[11]++;
			}else if(inp=='A'){
				mine[12]++;
			}
		}
		
		int woncards = 0;
		// for(int i=0; i<26; ++i){
		// 	// int ms = 0;
		// 	// while(mine[ms]==0) ms++;
		// 	// int s = 0;
		// 	// while(yours[s]==0) s--;

		// 	int s = 0;
		// 	while(yours[s]==0) s++;
		// 	int ms = s+1;
		// 	while(ms < 13 && mine[ms]==0) ms++;
		// 	if(ms<13){
		// 		yours[s]--;
		// 		mine[ms]--;
		// 		woncards += 2;
		// 	}else if(mine[s]){
		// 		yours[s]--;
		// 		mine[s]--;
		// 		woncards += 1;
		// 	}else{
		// 		ms = 0;
		// 		while(mine[ms]==0) ms++;
		// 		yours[s]--;
		// 		mine[ms]--;
		// 	}
		// }
		vector <int> y(26);
		vector <int> m(26);
		int yi = 0;
		int mi = 0;
		for(int i=0; i<13; ++i){
			for(int j=0; j<yours[i]; ++j){
				y[yi++] = i;
			}
			for(int j=0; j<mine[i]; ++j){
				m[mi++] = i;
			}
		}
		int car = 0;
		for(int i=0; i<26; ++i){
			car = 0;
			for(int j=0; j<26; ++j){
				if(m[ (j+i)%26 ] == y[j]){
					car ++;
				}else if(m[ (j+i)%26 ] > y[j]){
					car += 2;
				}
			}
			woncards = max(woncards,car);
		}

		cout << woncards << endl;

	}
}
















