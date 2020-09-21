#include <cstdio>
#include <vector>
using namespace std;

char reach[51][51] = {{0}};
char inc[51] = {0};
char out[51] = {0};
int T, N;

int main(){
	scanf("%d", &T);
	int t = 1;
	char tmp;
	while(T--){
		scanf("%d", &N);
		for(int i=0; i<N; ++i){
			scanf(" %c", &tmp);
			inc[i] = tmp=='Y';
		}
		for(int i=0; i<N; ++i){
			scanf(" %c", &tmp);
			out[i] = tmp=='Y';
		}
		for(int i=0; i<N; ++i){
			reach[i][i] = 1;
			for(int j=i+1; j<N; ++j){
				reach[i][j] = reach[i][j-1] & out[j-1] & inc[j];
			}
			for(int j=i-1; j>=0; --j){
				reach[i][j] = reach[i][j+1] & out[j+1] & inc[j];
			}
		}
		printf("Case #%d:\n", t++);
		for(int i=0; i<N; ++i){
			for(int j=0; j<N; ++j){
				printf("%c", reach[i][j]?'Y':'N');
			}
			printf("\n");
		}
	}
}