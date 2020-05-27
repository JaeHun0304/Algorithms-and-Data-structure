#include <iostream>
#include <queue>
#include <cstring>
#include <array>
#include <algorithm>

using namespace std;

const int MAX_DISCS = 5;
int c[1<<(MAX_DISCS * 2)];

int sgn(int x){
	return x > 0 ? 1 : -1;
}

int incr(int x){
	return x > 0 ? (x + 1) : (x - 1);
}
//bitmask makes us use single int variable as array!
int get(int state, int index){
	return ((state >> (index * 2)) & 3);
}

int set(int state, int index, int value){
	return ((state & ~(3 << (index * 2))) | (value << (index * 2)));
}

int main(){

	fill_n(c, 1<<(MAX_DISCS * 2), 0);

	int begin = 0b1010011100;
	int end = 0b1111111111;

	if(begin == end) return 0;
	queue<int> q;
	c[begin] = 1;
	c[end] = -1;
	q.push(end);
	q.push(begin);

	while(!q.empty()){
		int here = q.front(); q.pop();

		//same as int top[4] = {-1, -1, -1, -1}
		array<int, 4> top = {-1, -1, -1, -1};
		for(int i = MAX_DISCS - 1; i >= 0; i--){
			top[get(here, i)] = i;
		}

		for(int i = 0; i < 4; i++){
			if(top[i] != -1){
				for(int j = 0; j < 4; j++){
					if( (i != j) && (top[j] == -1 || (top[i] < top[j])) ){
						int there = set(here, top[i], j);
						//continue if c[there] is already visited
						if(c[there] == 0){
							c[there] = incr(c[here]);
							q.push(there);
						}
						else if( sgn(c[there]) != sgn(c[here]) ){
							cout << "found!" << endl;
							//start points were 1 and -1 (-2) and if sgn different, that means right before the target(+1)
							cout << abs(c[here]) + abs(c[there]) - 1 << endl;
							cin.get();
							return 0;
						}
					}
				}
			}
		}
	}

	return -1;
}