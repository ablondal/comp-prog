#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi prime;
void getprime(){
	vi isprime(2000015,1);
	isprime[1]=0;
	for(ll i=2;i<2000005;++i){
		if(isprime[i]==0)continue;
		for(ll j=i*i;j<2000005;j+=i){
			isprime[j]=0;
		}
	}
	for(int i=2;i<2000005;++i){
		if(isprime[i]==1){
			prime.push_back(i);
		}
	}
}

void cnt(int diff, string& s, unordered_map<ull, int>&mp){
	int n=s.length();
	stack<ull>st;
	ull num=0;
	for(int i=0;i<n;++i){
		//cout<<"="<<i<<" "<<s[i]<<endl;
		if(s[i]=='('||s[i]==','){
			if(num!=0){
				st.push(prime[num+diff]);
				//cout<<"push "<<prime[num+diff]<<endl;
				++mp[prime[num+diff]];
				num=0;
			}
		}else if(s[i]<='9'&&s[i]>='0'){
			num=num*10+(s[i]-'0');
		}else if(s[i]==')'){
			if(num!=0){
				st.push(prime[num+diff]);
				//cout<<"push "<<prime[num+diff]<<endl;
				++mp[prime[num+diff]];
				num=0;
			}
			ull l=st.top();
			st.pop();
			//cout<<"pop "<<l<<endl;
			ull r=st.top();
			st.pop();
			//cout<<"pop "<<r<<endl;
			st.push(l*r);
			//cout<<"push "<<l*r<<endl;
			++mp[l*r];
		}
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	string l,r;
	int n,m,i,j,k,s,t;
	cin>>n;
	cin>>l;
	cin>>r;
	prime.clear();
	getprime();
	s=n*3;
	for(int diff=0;diff<20;++diff){
		//cout<<diff<<endl;
		unordered_map<ull,int>mpl,mpr;
		cnt(diff,l,mpl);
		cnt(diff,r,mpr);
		t=0;
		for(auto p:mpl){
			if(mpr.count(p.first)){
				t+=min(p.second,mpr[p.first]);
			}
		}
		s=min(s,t);
	}
	cout<<s<<endl;
}