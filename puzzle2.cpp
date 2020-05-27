#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <stdint.h>

using namespace std;

uint64_t get(uint64_t state, uint64_t index){
	return (state >> (index * 4)) & 15;
}

uint64_t set(uint64_t state, uint64_t index, uint64_t value){
	return (uint64_t(state & ~(uint64_t(15) << uint64_t(index * 4)) | uint64_t(value << uint64_t(index * 4))));
}

vector<uint64_t> getAdjacent(uint64_t state){
	uint64_t state_left = state, state_right = state, state_up = state, state_down = state;

	vector<uint64_t> return_vec;
	uint64_t index;
	for(int i = 0; i < 16; i++){
		if(get(state, i) == 0){
			index = i;
			break;
		}
	}

	uint64_t right = get(state, index + 1);
	uint64_t left = get(state, index - 1);
	uint64_t up = get(state, index - 4);
	uint64_t down = get(state, index + 4);

	if(index == 0){
		state_right = set(state, index, right);
		state_right = set(state_right, index + 1, 0);
		state_down = set(state, index, down);
		state_down = set(state_down, index + 4, 0);
		return_vec = {state_right, state_down};
	}
	else if(index == 3){
		state_left = set(state, index, left);
		state_left = set(state_left, index - 1, 0);
		state_down = set(state, index, down);
		state_down = set(state_down, index + 4, 0);
		return_vec = {state_left, state_down};
	}
	else if(index == 12){
		state_up = set(state, index, up);
		state_up = set(state_up, index - 4, 0);
		state_right = set(state, index, right);
		state_right = set(state_right, index + 1, 0);
		return_vec = {state_up, state_right};
	}
	else if(index == 15){
		state_left = set(state, index, left);
		state_left = set(state_left, index - 1, 0);
		state_up = set(state, index, up);
		state_up = set(state_up, index - 4, 0);
		return_vec = {state_left, state_up};
	}
	else if(index == 1 || index == 2){
		state_down = set(state, index, down);
		state_down = set(state_down, index + 4, 0);
		state_left = set(state, index, left);
		state_left = set(state_left, index - 1, 0);
		state_right = set(state, index, right);
		state_right = set(state_right, index + 1, 0);
		return_vec = {state_down, state_left, state_right};
	}
	else if(index == 4 || index == 8){
		state_right = set(state_right, index, right);
		state_right = set(state_right, (index + 1), 0);
		state_up = set(state_up, index, up);
		state_up = set(state_up, (index - 4), 0);
		state_down = set(state_down, index, down);
		cout << hex << state_down << endl;
		state_down = set(state_down, (index + 4), 0);
		cout << hex << state_down << endl;
		return_vec = {state_right, state_up, state_down};
	}
	else if(index == 7 || index == 11){
		state_left = set(state, index, left);
		state_left = set(state_left, index - 1, 0);
		state_up = set(state, index, up);
		state_up = set(state_up, index - 4, 0);
		state_down = set(state, index, down);
		state_down = set(state_down, index + 4, 0);
		return_vec = {state_left, state_up, state_down};
	}
	else if(index == 13 || index == 14){
		state_left = set(state, index, left);
		state_left = set(state_left, index - 1, 0);
		state_right = set(state, index, right);
		state_right = set(state_right, index + 1, 0);
		state_up = set(state, index, up);
		state_up = set(state_up, index - 4, 0);
		return_vec = {state_left, state_right, state_up};
	}
	else{
		state_down = set(state, index, down);
		state_down = set(state_down, index + 4, 0);
		state_left = set(state, index, left);
		state_left = set(state_left, index - 1, 0);
		state_right = set(state, index, right);
		state_right = set(state_right, index + 1, 0);
		state_up = set(state, index, up);
		state_up = set(state_up, index - 4, 0);
		return_vec = {state_up, state_down, state_left, state_right};
	}

	return return_vec;
}


int main(){
	uint64_t start = 0xCFED8BA976504321;
	uint64_t end = 0x0FEDCBA987654321;

	map<uint64_t, int> c1;
	queue<uint64_t> q;

	if(start == end) return 0;

	c1[start] = 0;
	q.push(start);

	int distance;
	while(!q.empty()){
		uint64_t here = q.front(); q.pop();

		distance = c1[here];
		vector<uint64_t> adj_list = getAdjacent(here);

		for(int i = 0; i < adj_list.size(); i++){
			if(adj_list[i] == end){
				cout << "found!" << endl;
				cout << distance + 1 << endl;
				cin.get();
				return 0;
			}
			if(c1.count(adj_list[i]) == 0){
				c1[adj_list[i]] = distance + 1;
				q.push(adj_list[i]);
			}
		}

	}

	cin.get();
}