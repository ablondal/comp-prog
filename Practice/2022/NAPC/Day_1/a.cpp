#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i< (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const double eps=1e-7;
bool eq(double l, double r){
	if(fabs(l-r)<eps)return true;
	return false;
}
bool check(ll l,ll t, ll xd){
	ll r=l*t;
	//cout<<l<<"=="<<r<<endl;
	if(l>=100000000)return false;
	rep(i,0,xd){
		if(r%10!=0)return false;
		r/=10;
	}
	string sl=to_string(l),sr=to_string(r);
	//if(sl.length()!=sr.length())return false;
	//cout<<sl<<" "<<sr<<endl;
	if(sl.length()<sr.length())return false;
	while(sl.length()>sr.length()){
		sr="0"+sr;
	}
	if(sl[0]!=sr[sl.length()-1])return false;
	rep(i,1,sl.length()){
		if(sl[i]!=sr[i-1])return false;
	}
	return true;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	double x,xx;
	ll xd,t,l,r,a,b,i,j,k;
	vector<ll>ans;
	cin>>x;
	xd=0;
	xx=x;
	while(!eq(xx,round(xx))){
		xx*=10;
		xd++;
	}
	t=round(xx);
	for(i=1;i<=9;++i){
		if(check(i,t,xd)){
			ans.push_back(i);
		}
	}
	//cout<<t<<" "<<xd<<endl;
	for(l=10;l<=1e8+5;l*=10){
		for(r=1;r<=1e8+5;r*=10){
			ll sl=t*l-r;
			ll sr=r*10-t;
			if(sl<0&&sr<0)sl=-sl,sr=-sr;
			if(sl>=0&&sr>=0){
				for(a=1;a<=9;++a){
					//cout<<a<<"?"<<sl<<" "<<sr<<endl;
					if((a*sl)%sr==0){
						//cout<<a<<" "<<l<<" "<<r<<" "<<sl<<" "<<sr<<" "<<a*l+a*sl/sr<<endl;
						if(check(a*l+a*sl/sr,t,xd)){
							ans.push_back(a*l+a*sl/sr);
						}
					}
				}
			}
		}
	}
	if(ans.size()==0){
		cout<<"No solution"<<endl;
	}else{
		sort(ans.begin(),ans.end());
		for(auto anss: ans){
			cout<<anss<<endl;
		}
	}
}