#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

bool visited[500007];
bool cyc[500007];
bool nxt[500007];
vector <int> rents[500007];

typedef struct _node{
	int dep;
	int L=0, R=0;
} node;

node heep[500007];

// Skew Heap, my fav shitpost
int merge(int A, int B){
	if (!A) return B;
	if (!B) return A;
	if (heep[A].dep > heep[B].dep) {
		int tmp = heep[A].R;
		heep[A].R = heep[A].L;
		heep[A].L = merge(B, tmp);
		return A;
	} else {
		return merge(B, A);
	}
}

int main(){
	int n;
	int k;
	
}

















