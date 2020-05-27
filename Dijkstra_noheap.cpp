#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main(){

	int MAX_V = 20;
	int V = 8;
	int INF = numeric_limits<int>::max();

	vector< pair<int, int> > adj[MAX_V];
	adj[0] = { make_pair(1, 5), make_pair(2, 1) };
	adj[1] = { make_pair(0, 5), make_pair(3, 1), make_pair(5, 3), make_pair(6, 3)};
	adj[2] = { make_pair(0, 1), make_pair(3, 2)};
	adj[3] = { make_pair(1, 1), make_pair(2, 2), make_pair(4, 5), make_pair(5, 3)};
	adj[4] = { make_pair(3, 5)};
	adj[5] = { make_pair(1, 3), make_pair(6, 2), make_pair(3, 3)};
	adj[6] = { make_pair(1, 3), make_pair(5, 2)};

	// dist vector size V with value INF
	vector<int> dist(V, INF);
	// visited vector size V with value false
	vector<bool> visited(V, false);

	int src = 0;

	dist[src] = 0;

	while(true){
	
		int distance = INF, here;
		for(int i = 0; i < V; i++){
			if( dist[i] < distance && !visited[i]){
				distance = dist[i];
				here = i;
			}
		}
		visited[here] = true;

		if(distance == INF) break;

		for(int i = 0; i < adj[here].size(); i++){
			int there = adj[here][i].first;
			int nextDist = dist[here] + adj[here][i].second;
			if(nextDist < dist[there]){
				dist[there] = nextDist;
			}
		}

	}

	cout << dist[6] << endl;
	cin.get();

}