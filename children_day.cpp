#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

/*
int main(){

	string digits = "1";
	int n = 7; int m = 0;
	// Sort digits in ascending order
	sort(digits.begin(), digits.end());
	// parent[i] parent for node i, choice[i] edge number from parent[i] to i
	vector<int> parent(2*n, -1), choice(2*n, -1);
	// queue for storing visiting plan nodes
	queue<int> q;
	q.push(0);
	parent[0] = 0;

	while(!q.empty()){
		// return front as current node and pop to remove from queue
		int here = q.front(); q.pop();

		// search edges in dictionary order
		for(int i = 0; i < digits.size(); i++){
			int next_num = here * 10 + int(digits[i] - '0');
			int there = 0;
			if(next_num >= n)
				there = n + next_num % n;
			else
				there = next_num % n;
			if(parent[there] == -1){
				q.push(there);
				parent[there] = here;
				choice[there] = digits[i] - '0';
			}
		}

	}

	// If the graph never reached the node bigger than n+m, there is no valid answer
	if(parent[n+m] == -1){
		cout << "IMPOSSIBLE" << endl;;
	}
	else{
		// here is the first smallest node that satisfies all the conditions
		int here = n + m;
		string ret;
		while(here != parent[here]){
			ret += char(choice[here] + '0');
			here = parent[here];
		}
		reverse(ret.begin(), ret.end());
		cout << ret << endl;
	}
}
*/