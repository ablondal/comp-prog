#include <cstdio>
using namespace std;

char word[57];
int n;
int i = 0;

int main(){
	scanf("%d", &n);
	// Use n to count newlines
	scanf("%c", &word[0]); // Flush the newline after n
	while(n>0){
		scanf("%c", &word[i]);
		if (word[i] == '\n') n--;
		if (word[i] == '\n' || word[i] == ' '){
			for(int j=i-1; j>=0; --j){
				printf("%c", word[j]);
			}
			printf("%c", word[i]);
			i = 0;
		}else{
			i++;
		}
	}
}