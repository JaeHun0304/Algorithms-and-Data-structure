#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;


int main(){


	int INF = numeric_limits<int>::max();
	int MAX_V = 20;
	int V = 8;
	vector< pair<int, int> > adj[MAX_V];
	adj[0] = { make_pair(1, 3), make_pair(5, 9)};
	adj[1] = { make_pair(0, 3), make_pair(7, 3), make_pair(2, 6)};
	adj[2] = { make_pair(1, 6), make_pair(3, 4), make_pair(4, 2)};
	adj[3] = { make_pair(2, 4), make_pair(4, 7)};
	adj[4] = { make_pair(2, 2), make_pair(3, 7), make_pair(6, 1)};
	adj[5] = { make_pair(0, 9), make_pair(4, 5), make_pair(6, 3), make_pair(7, 5)};
	adj[6] = { make_pair(4, 1), make_pair(5, 3), make_pair(7, 3)};
	adj[7] = { make_pair(1, 3), make_pair(5, 5), make_pair(6, 3)};

	// make additional line that has 0 weight between nodes of fire stations
	adj[3].push_back(make_pair(5, 0));
	adj[5].push_back(make_pair(3, 0));

	int src = 3;
	vector<int> dist(V, INF);
	priority_queue< pair<int, int> > pq;
	pq.push(make_pair(0, src));
	dist[src] = 0;

	while(!pq.empty()){
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if(dist[here] < cost) continue;

		for(int i = 0; i < adj[here].size(); i++){
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;

			if(nextDist < dist[there]){
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}

	}

	cout << dist[1] + dist[2] + dist[4] << endl;
	cin.get();

}