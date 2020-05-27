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
	//store adjacent list, (node, weight) info
	vector< pair<int, int> > adj[MAX_V];
	adj[0] = { make_pair(1, 5), make_pair(2, 1) };
	adj[1] = { make_pair(0, 5), make_pair(3, 1), make_pair(5, 3), make_pair(6, 3)};
	adj[2] = { make_pair(0, 1), make_pair(3, 2)};
	adj[3] = { make_pair(1, 1), make_pair(2, 2), make_pair(4, 5), make_pair(5, 3)};
	adj[4] = { make_pair(3, 5)};
	adj[5] = { make_pair(1, 3), make_pair(6, 2), make_pair(3, 3)};
	adj[6] = { make_pair(1, 3), make_pair(5, 2)};

	int src = 0;
	vector<int> dist(V, INF);
	dist[src] = 0;
	priority_queue< pair<int, int> > pq;
	pq.push(make_pair(0, src));

	while(!pq.empty()){
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		//disregard cost if dist[here] is already shorter than that
		if(dist[here] < cost) continue;

		for(int i = 0; i < adj[here].size(); i++){
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			if(dist[there] > nextDist){
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}

	cout << dist[6] << endl;
	cout << "End!" << endl;
	cin.get();
}