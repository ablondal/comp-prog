#include <iostream>
//#include <math>

using namespace std;

int main(){
	long long hx,hy,ux,uy,steps=0;
	int n;
	long long a,b,c;
	long long th,tu;
	cin >>hx>>hy>>ux>>uy;
	cin >> n;
	for(int i=0;i<n;++i){
		cin >>a>>b>>c;
		th = (a*hx)+(b*hy)+c;
		tu = (a*ux)+(b*uy)+c;
		if((th>0 && tu<0) || (tu>0 && th<0)){
			steps++;
		}
	}
	cout << steps <<endl;
}