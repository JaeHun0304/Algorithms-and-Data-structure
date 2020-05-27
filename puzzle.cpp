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
/*
int main(){
	if (start_state == finish_state){
		cout << "please specify 2 different states!" << endl;
		return 0;
	}

	map<vector<vector<int>>, int> c;
	c[start_state] = 0;
	queue<vector<vector<int>>> q;
	q.push(start_state);

	while(!q.empty()){
		vector<vector<int>> here = q.front(); q.pop();

		int distance = c[here];
		vector<vector<vector<int>>> adj_list = getAdjacent(here);
		for(int i = 0; i < adj_list.size(); i++){
			if(adj_list[i] == finish_state){
				cout << distance + 1 << endl;
				return 0;
			}
			if(c.count(adj_list[i]) == 0){
				q.push(adj_list[i]);
				c[adj_list[i]] = distance + 1;
			}
		}
	}

	cout << "target state not found!" << endl;
	return 0;

}
*/