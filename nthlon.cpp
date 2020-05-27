#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

int main(){

	int INF = numeric_limits<int>::max();
	int V = 402;
	vector< pair<int, int> > adj[500];
	// starting point which is node '0', this will start search from the last node (401 in this case)
	const int START = 401;

	const vector<int> a = {10, 63, 16};
	const vector<int> b = {81, 71, 51};

	// clear the adj elements that we are going use (0 ~ V)
	for(int i = 0; i < V; i++){
		adj[i].clear();
	}

	// push pairs into the adj vector 
	for(int i = 0; i < a.size(); i++){
		int delta = a[i] - b[i];
		// push initial edges from the starting node
		adj[START].push_back(make_pair(delta + 200, a[i]));
	}

	// create graph with all possible nodes (-200 ~ 200) 
	for(int delta = -200; delta <= 200; delta++){
		for(int i = 0; i < a.size(); i++){
			int next = delta + a[i] - b[i];
			// skip if node is outside of the range of possible nodes
			if(abs(next) > 200) continue;
			adj[delta + 200].push_back(make_pair(next + 200, a[i]));
		}
	}

	vector<int> dist(V, INF);
	dist[START] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, START));

	while(!pq.empty()){
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		
		if(cost > dist[here]) continue;

		for(int i = 0; i < adj[here].size(); i++){
			int next = cost + adj[here][i].second;
			int there = adj[here][i].first;

			if(next < dist[there]){
				dist[there] = next;
				pq.push(make_pair(-next, there));
			}
		}
	}
	if(dist[0 + 200] != INF)
		cout << dist[0 + 200] << endl;
	else
		cout << "IMPOSSIBLE!" << endl;

	cin.get();

}