#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

vector<vector<int>> start_state = {
									{1, 2, 3, 4},
									{-1, 5, 6, 7},
									{9, 10, 11, 8},
									{13, 14, 15, 12}
								   };
vector<vector<int>> finish_state = {
									{1, 2, 3, 4},
									{5, 6, 7, 8},
									{9, 10, 11, 12},
									{13, 14, 15, -1}
								   };
int best;

vector<vector<vector<int>>> getAdjacent(vector<vector<int>>& state){
	vector<vector<int>> state_left = state, state_right = state, state_up = state, state_down = state;
	int row, col;
	for(int i = 0; i < state.size(); i++){
		for(int j = 0; j < state[0].size(); j++){
			if(state[i][j] == -1){
				row = i;
				col = j;
			}
		}
	}

	vector<vector<vector<int>>> return_vec;
	if(row != 3 && row != 0 && col != 3 && col != 0){
		swap(state_left[row][col], state_left[row][col-1]);
		swap(state_right[row][col], state_right[row][col+1]);
		swap(state_up[row][col], state_up[row-1][col]);
		swap(state_down[row][col], state_down[row+1][col]);
		return_vec = {state_left, state_right, state_up, state_down};
	}
	else if(row != 3 && row != 0 && col != 3 && col == 0){
		swap(state_right[row][col], state_right[row][col+1]);
		swap(state_up[row][col], state_up[row-1][col]);
		swap(state_down[row][col], state_down[row+1][col]);
		return_vec = {state_right, state_up, state_down};
	}
	else if(row != 3 && row != 0 && col == 3 && col != 0){
		swap(state_left[row][col], state_left[row][col-1]);
		swap(state_up[row][col], state_up[row-1][col]);
		swap(state_down[row][col], state_down[row+1][col]);
		return_vec = {state_left, state_up, state_down};
	}
	else if(row != 3 && row == 0 && col != 3 && col != 0){
		swap(state_left[row][col], state_left[row][col-1]);
		swap(state_right[row][col], state_right[row][col+1]);
		swap(state_down[row][col], state_down[row+1][col]);
		return_vec = {state_left, state_right, state_down};
	}
	else if(row == 3 && row != 0 && col != 3 && col != 0){
		swap(state_left[row][col], state_left[row][col-1]);
		swap(state_right[row][col], state_right[row][col+1]);
		swap(state_up[row][col], state_up[row-1][col]);
		return_vec = {state_left, state_right, state_up};
	}
	else if(row == 3 && row != 0 && col == 3 && col != 0){
		swap(state_left[row][col], state_left[row][col-1]);
		swap(state_up[row][col], state_up[row-1][col]);
		return_vec = {state_left, state_up};
	}
	else if(row != 3 && row == 0 && col != 3 && col == 0){
		swap(state_right[row][col], state_right[row][col+1]);
		swap(state_down[row][col], state_down[row+1][col]);
		return_vec = {state_down, state_right};
	}
	else if(row != 3 && row == 0 && col == 3 && col != 0){
		swap(state_left[row][col], state_left[row][col-1]);
		swap(state_down[row][col], state_down[row+1][col]);
		return_vec = {state_down, state_left};
	}
	else if(row == 3 && row != 0 && col != 3 && col == 0){
		swap(state_up[row][col], state_up[row-1][col]);
		swap(state_right[row][col], state_right[row][col+1]);
		return_vec = {state_up, state_right};
	}
	else{
		swap(state_left[row][col], state_left[row][col-1]);
		swap(state_right[row][col], state_right[row][col+1]);
		swap(state_up[row][col], state_up[row-1][col]);
		swap(state_down[row][col], state_down[row+1][col]);
		return_vec = {state_left, state_right, state_up, state_down};	
	}

	return return_vec;
}

int estimate(vector<vector<int>>& here, vector<vector<int>>& finish){
	int row_start, col_start, row_end, col_end;

	for(int i = 0; i < here.size(); i++){
		for(int j = 0; j < here[0].size(); j++){
			if(here[i][j] == -1){
				row_start = i; 
				col_start = j;
			}
			if(finish[i][j] == -1){
				row_end = i; 
				col_end = j;
			}
		}
	}

	return abs(row_start - row_end) + abs(col_start - col_end);
}

void dfs(vector<vector<int>>& here, vector<vector<int>>& finish, int steps){

	//if steps bigger than current best case, discard it
	if(steps >= best) return;
	//if found the answer node, set best as current steps
	if(here == finish) { best = steps; return;}

	auto adjacent = getAdjacent(here);
	for(int i = 0; i < adjacent.size(); i++){
		//implement dfs by recursive function which starts from adjacent node
		dfs(adjacent[i], finish, steps+1);
	}

}

//we can use manhattan distance to make further optimization

void dfs2(vector<vector<int>>& here, vector<vector<int>>& finish, int steps){

	//if steps bigger than current best case, discard it
	//method estimate returns manhattan distance to finish
	if(steps + estimate(here, finish) >= best) return;
	//if found the answer node, set best as current steps
	if(here == finish) { best = steps; return;}

	auto adjacent = getAdjacent(here);
	for(int i = 0; i < adjacent.size(); i++){
		//implement dfs by recursive function which starts from adjacent node
		dfs(adjacent[i], finish, steps+1);
	}

}

int main(){

	int growthStep = 1;

	// if nothing in the middle in for loop, do until return
	for(int limit = 4; ; limit += growthStep){
		//set best as 1 + current limit
		best = limit + 1;
		// start dfs search from distance 0 from start_state to end_state
		dfs2(start_state, finish_state, 0);
		// if best becomes smaller than limit, min distance found!
		if(best <= limit) {
			cout << best << endl;
			return 0;
		}
	}

	return -1;
}
