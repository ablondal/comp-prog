/* Written by Ari */
/* If joining by size, -UF[root] is size of set */
const int INF = 1e7;
int UF[MAXN] = {0};

int find(int x){
	return UF[x] < 0 ? x : UF[x] = find(UF[x]);
}

void init(int n){
	rep(i,0,n) UF[i] = -1;
}

bool join(int a, int b){
	a = find(a), b = find(b);
	if (a==b) return false;
	if (UF[b] < UF[a]) swap(a,b);
	UF[a] += UF[b];
	UF[b] = a;
	return true;
}
