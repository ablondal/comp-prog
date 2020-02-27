#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

bool isprime(ll c){
	if (c<2) return false;
	for(ll i=2; i<=sqrt(c); ++i){
		if(c%i==0) return false;
	}
	return true;
}

/*
Ways:
a->b 
	if a is 2
	b-a is 2
a->a+2->b
	if a+2 is prime and b-a is 4
a->2->b
	if a-2 is prime and b-2 is prime
a->a+2->a+4->b
	if a+2 is prime and b-2 is prime
a->2->b+2->b
	if a-2 is prime and b+2 is prime
a->a+2->2->b
	if a+2 is prime and b-2 is prime
a->a+2->2->b+2->b
	if a+2, b+2 are prime


*/

int main(){
	ll a, b;
	cin >> a >> b;
	if(b-a == 2){
		cout << a << "->" << b << endl;
	}else if (a==3 && b==7){
		cout << "3->5->7" << endl;
	}else{
		bool ad, au, bd, bu;
		ad = isprime(a-2);
		au = isprime(a+2);
		bd = isprime(b-2);
		bu = isprime(b+2);
		
		if (a==2 && bd){
			cout << "2->" << b << endl;
		}else if( a==2 && bu ){
			cout << "2->" << b+2 << "->" << b << endl;
		}else if( (!(ad || au)) || (!(bd || bu)) ){
			cout << "Unlucky Benny" << endl;
		}else if( ad && bd ){
			cout << a << "->2->" << b << endl;
		}else if( ad && bu ){
			cout << a << "->2->" << b+2 << "->" << b << endl;
		}else if( bd ){
			cout << a << "->" << a+2 << "->2->" << b << endl;
		}else{
			cout << a << "->" << a+2 << "->2->" << b+2 << "->" << b << endl;
		}

/*
		if ( b-a == 4 && au){
			num3++;
		}
		if ( ad && bd ){
			num3++;
		}
		if ( b-a == 6 && au && bd ){
			num4++;
		}
		if ( ad && bu ){
			num4++;
		}
		if ( au && bd ){
			num4++;
		}
		if ( au && bu ){
			num5++;
		}
		if ( num3+num4+num5 == 0 ){
			cout << "Unlucky Benny" << endl;
		}else{
			if ( b-a == 4 && au){
				cout << a << "->" << a+2 << "->" << b << endl;
			}
			else if ( ad && bd ){
				cout << a << "->" << 2 << "->" << b << endl;
			}
			else if ( b-a == 6 && au && bd ){
				cout << a << "->" << a+2 << "->" << a+4 << "->" << b << endl;
			}
			else if ( ad && bu ){
				cout << a << "->" << 2 << "->" << b+2 << "->" << b << endl;
			}
			else if ( au && bd ){
				cout << a << "->" << a+2 << "->" << 2 << "->" << b << endl;
			}
			else if ( au && bu ){
				cout << a << "->" << a+2 << "->" << 2 << "->" << b+2 << "->" << b << endl;
			}
			else{
				int s = 0;
				int a = 3/s;
			}
		}*/
	}
}









