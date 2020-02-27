#include <iostream>
#include <vector>
using namespace std;
int main(){
	int y;
	cin >> y;
	while(y){
		if(y>1918){
			if((y%400==0)||(y%4==0 && y%100!=0)){
				cout << "12.09."<<y<<endl;
			}else{
				cout << "13.09."<<y<<endl;
			}
		}else if(y<1918){
			if(y%4==0){
				cout << "12.09."<<y<<endl;
			}else{
				cout << "13.09."<<y<<endl;
			}
		}else{
			cout << "26.09.1918"<<endl;
		}
		cin>>y;
	}
	return 0;
}