#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int board[5][5];

void movedown(){
	for (int x=0; x<4; ++x){
		vi nums;
		for(int y=3;y>=0;--y){
			if(board[x][y]){
				nums.push_back(board[x][y]);
			}
		}
		for(int i=0; i+1<nums.size(); ++i){
			if (nums[i]==nums[i+1]){
				nums[i]*=2;
				nums.erase(nums.begin()+i+1);
			}
		}
		for(int y=3;y>=0;--y){
			if(nums.size()){
				board[x][y]=nums[0];
				nums.erase(nums.begin());
			}else{
				board[x][y]=0;
			}
		}
	}
}

void moveup(){
	for (int x=0; x<4; ++x){
		vi nums;
		for(int y=0;y<4;++y){
			if(board[x][y]){
				nums.push_back(board[x][y]);
			}
		}
		for(int i=0; i+1<nums.size(); ++i){
			if (nums[i]==nums[i+1]){
				nums[i]*=2;
				nums.erase(nums.begin()+i+1);
			}
		}
		for(int y=0;y<4;++y){
			if(nums.size()){
				board[x][y]=nums[0];
				nums.erase(nums.begin());
			}else{
				board[x][y]=0;
			}
		}
	}
}

void moveleft(){
	for (int y=0; y<4; ++y){
		vi nums;
		for(int x=3;x>=0;--x){
			if(board[x][y]){
				nums.push_back(board[x][y]);
			}
		}
		for(int i=0; i+1<nums.size(); ++i){
			if (nums[i]==nums[i+1]){
				nums[i]*=2;
				nums.erase(nums.begin()+i+1);
			}
		}
		for(int x=3;x>=0;--x){
			if(nums.size()){
				board[x][y]=nums[0];
				nums.erase(nums.begin());
			}else{
				board[x][y]=0;
			}
		}
	}
}

void moveright(){
	for (int y=0; y<4; ++y){
		vi nums;
		for(int x=0; x<4; ++x){
			if(board[x][y]){
				nums.push_back(board[x][y]);
			}
		}
		for(int i=0; i+1<nums.size(); ++i){
			if (nums[i]==nums[i+1]){
				nums[i]*=2;
				nums.erase(nums.begin()+i+1);
			}
		}
		for(int x=0; x<4; ++x){
			if(nums.size()){
				board[x][y]=nums[0];
				nums.erase(nums.begin());
			}else{
				board[x][y]=0;
			}
		}
	}
}

int main() {
	rep(i,0,16){
		scanf("%d", &board[i%4][i/4]);
	}
	int action = 0;
	scanf("%d", &action);
	switch(action){
		case 0:
			moveright();
			break;
		case 1:
			moveup();
			break;
		case 2:
			moveleft();
			break;
		case 3:
			movedown();
			break;
	}
	rep(i,0,4){
		printf("%d %d %d %d\n", board[0][i], board[1][i], board[2][i], board[3][i]);
	}
}










