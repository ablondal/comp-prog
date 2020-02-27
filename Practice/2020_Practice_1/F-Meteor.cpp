#include <iostream>
#include <queue>
using namespace std;

// This works perfectly

int main(){
	priority_queue <int> NotBlownUp;

	int N, shots=0;
	int last_t = 0;
	int t, d, curr_shield = 0;
	
	cin >> N;

	for(int i=0; i<N; ++i){
		cin >> t >> d;
		curr_shield += t-last_t;
		curr_shield -= d;
		last_t = t;
		NotBlownUp.push(d);

		while(curr_shield<0){
			if (NotBlownUp.empty()) {
				break;
			}
			
			curr_shield += NotBlownUp.top();
			shots++;
			NotBlownUp.pop();
		}
	}

	cout << shots << endl;

}