#include <iostream>
#include <iomanip>
#include <map>
#include <vector>

using namespace std;

int flipyear(int y){
	int m1 = y % 100;
	int d1 = y / 100;
	int m2,d2;
	switch(m1){
		case 50: m2=2; break;
		case 20: m2=5; break;
		case 80: m2=8; break;
		default: return -1;
	}
	switch(d1){
		case 50: d2=2; break;
		case 20: d2=5; break;
		case 80: d2=8; break;
		case 5: d2=20; break;
		case 55: d2=22; break;
		case 25: d2=25; break;
		case 85: d2=28; break;
		default: return -1;
	}
	return m2*100+d2;
}

int main(){
	int t;
	int y1,m1,d1,y2,m2,d2;
	cin >> t;
	while(t--){
		cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
		vector <int> years;
		for(int y=y1; y<=y2; ++y){
			int fy = flipyear(y);
			if (fy==-1) continue;
			int m = fy/100;
			int d = fy%100;
			if(y==y1 && (m<m1 || (m==m1 && d<d1) ) ){
				continue;
			}
			if(y==y2 && (m>m2 || (m==m2 && d>d2) ) ){
				continue;
			}
			years.push_back(y);
		}
		cout << years.size() << endl;
		for( auto y : years ){
			int fy = flipyear(y);
			cout << setfill('0') << setw(4) << y << " " << setw(2) << fy / 100 << " " << setw(2) << fy % 100 << endl;
		}
	}
}










