
struct SuffixAutomaton{
	static const int N = 2e5+7;
	string s;
	int link[N], len[N], ct[N]={0}, t[N]={0}, la=0, ni=1;
	map<char,int> nx[N];
	void add_c(char x){
		int a=la, c=ni++;
		len[c] = len[a]+1; ct[c]=1; la=c;
		while(a!=-1 && !nx[a].count(x)){
			nx[a][x]=c;a = link[a];
		}
		if (a==-1) {
			link[c] = 0;
		} else {
			int q = nx[a][x];
			if (len[a]+1==len[q]){
				link[c]=q;
			} else {
				int cl = ni++;
				link[cl] = link[q]; nx[cl]=nx[q];
				len[cl] = len[a]+1;
				while(a != -1 && nx[a][x]==q){
					nx[a][x]=cl; a=link[a];
				}
				link[q] = link[c]=cl;
			}
		}
	}
	SuffixAutomaton(string s):s(s){
		link[0]=-1; len[0]=0;
		for(auto x:s) add_c(x);
		t[la]=true;
		vi a(ni, 0); iota(all(a), 0);
		sort(all(a), [this](int b, int c){return len[b]<len[c];});
		for(int i=ni-1; i>0; --i){
			t[link[a[i]]] = t[a[i]];
			ct[link[a[i]]] += ct[a[i]];
		}
		ct[0]=0;
	}
};