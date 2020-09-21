#include <iostream>
using namespace std;

struct hum{
	bool V;
	int next;
	int pass;
};

hum H[10007];

int DFS(int C, int p){
	if (C == 0) return -1;
	if (H[C].V){
		if (H[C].pass == p) return -1;
		else return 0;
	}
	H[C].V = true;
	H[C].pass = p;
	return 1 + DFS(H[C].next, p);
}

int main(){
	int n, m, a, b;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		H[i].V = false;
		H[i].pass = -1;
		H[i].next = 0;
	}
	for(int i=1; i<=m; ++i){
		cin >> a >> b;
		H[a].next = b;
	}
	int p=0;
	int tot = 0;
	for(int i=1; i<=n; ++i){
		if (H[i].V){
			continue;
		}
		tot += DFS(i, p);
		p++;
	}
	cout << tot << endl;
}







