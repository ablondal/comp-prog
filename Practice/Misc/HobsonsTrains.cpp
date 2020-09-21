#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
#define min(a,b) ((a<b)?a:b)

int k, n;
int visited[500007] = {0};
int cyc[500007] = {0};
int nxt[500007];
int s_left[500007] = {0};
int total[500007] = {0};
vector <int> rents[500007];

typedef struct _node{
	int dep;
	int source;
	int L=0, R=0;
} node;

node heep[500007];

// Skew Heap, my fav shitpost
int merge(int A, int B){
	// printf("Merge %d %d", A, B);
	if (!A) return B;
	if (!B) return A;
	if (heep[A].dep > heep[B].dep) {
		int tmp = heep[A].R;
		heep[A].R = heep[A].L;
		heep[A].L = merge(B, tmp);
		return A;
	} else {
		int tmp = heep[B].R;
		heep[B].R = heep[B].L;
		heep[B].L = merge(A, tmp);
		return B;
	}
}

// Skew empty
inline bool isEmpty(int R){
	return R == 0;
}

// Skew Pop, shitpost extension
// Use by letting newroot = Pop(oldroot)
inline int Pop(int R){
	if (isEmpty(R)) return 0;
	return merge(heep[R].L, heep[R].R);
}

inline int getCycle(int A){
	int i=1;
	while(!cyc[A]){
		cyc[A] = i++;
		A = nxt[A];
	}
	cyc[A] = i;
	return A; // cycle length is cyc[A] + 1 - cyc[nxt[A]]
}

int DFS(int R, int depth, int &H, int source, int no){
	if (R==0){
		H = 0;
		return 0;
	}
	visited[R] = true;
	H = R;
	heep[H].dep = depth;
	heep[H].source = source;
	int H1, tot=1;
	s_left[source]++;
	for(auto child : rents[H]){
		if (child==no) continue;
		tot += DFS(child, depth+1, H1, source, 0);
		// printf("merging %d with %d\n", R, child);
		// printf("The heaps are %d and %d\n", H, H1);
		H = merge(H, H1);
		// printf("merge done\n");
	}
	while(H && heep[H].dep > depth + k){
		s_left[source]--;
		tot--;
		H = Pop(H);
	}
	// printf("Setting Node %d to total %d\n", R, tot);
	total[R] = tot;
	return tot;
}

void cycleDO(int A, int cycLen){
	int H = 0, H2;
	int tot = 0;
	int L = A;
	int C = nxt[L];
	for(int depth=cycLen*2; depth>0; depth--){
		if (visited[C]){
			if (s_left[C]){
				tot -= s_left[C];
				s_left[C] = 0;
			}
			while(H && heep[H].dep > depth + k){
				if (s_left[heep[H].source]){
					s_left[heep[H].source]--;
					tot--;
				}
				H = Pop(H);
			}
			total[C] += tot + min(k+1, cycLen);
			// printf("Second pass: %d at %d\n", C, total[C]);
			C = nxt[C];
			continue;
		}
		if (rents[C].size() > 1){
			tot += DFS(C, depth, H2, C, L);
			s_left[C]--;
			tot--;
			H = merge(H, H2);
		}
		while(H && heep[H].dep > depth + k){
			if (s_left[heep[H].source]){
				s_left[heep[H].source]--;
				tot--;
			}
			H = Pop(H);
		}
		total[C] = tot;
		// printf("First pass: %d at %d\n", C, total[C]);
		visited[C] = true;
		L = C;
		C = nxt[C];
	}
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; ++i){
		scanf("%d", &nxt[i]);
		rents[nxt[i]].push_back(i);
	}
	for(int i=1; i<=n; ++i){
		if (!visited[i]){
			int A = getCycle(i);
			cycleDO(A, cyc[A]+1-cyc[nxt[A]]);
		}
		printf("%d\n",total[i]);
	}
}

















