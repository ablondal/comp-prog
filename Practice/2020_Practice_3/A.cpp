#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
	int C[10001][6];

	int i = 1;
	int layer = 0;
	int layersize = 1;
	int layerlim = 2;
	while (i<10001){
		if (i==layerlim) {
			if (layer%2 == 0){
				layersize += 2;
			}else{
				layersize += 4;
			}
			layerlim += layersize;
			layer++;
		}

		C[i][0]

		if ()
	}
}