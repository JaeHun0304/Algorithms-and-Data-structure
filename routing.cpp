#include <iostream>
#include <vector>
#include <limits>
#include <utility>
#include <tuple>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

int main(){

	int coms = 7;
	int circuits = 14;
	int INF = numeric_limits<int>::max();

	vector< tuple<int, int, float> > inputs = { make_tuple(0, 1, 1.3),
								  make_tuple(0, 2, 1.1),
								  make_tuple(0, 3, 1.24),
								  make_tuple(3, 4, 1.17),
								  make_tuple(3, 5, 1.24),
								  make_tuple(3, 1, 2.),
								  make_tuple(1, 2, 1.31),
								  make_tuple(1, 2, 1.26),
								  make_tuple(1, 4, 1.11),
								  make_tuple(1, 5, 1.37),
								  make_tuple(5, 4, 1.24),
								  make_tuple(4, 6, 1.77),
								  make_tuple(5, 6, 1.11),
								  make_tuple(2, 6, 1.2)
											};
	vector< pair<int, float> > adj[coms];

	cout << get<2>(inputs[0]);

	for(int i = 0; i < circuits; i++){
		adj[get<0>(inputs[i])].push_back( make_pair( get<1>(inputs[i]), get<2>(inputs[i]) ) );
	}

	int src = 0;
	vector<int> dist(coms, INF);
	priority_queue< pair<int, int> > pq;
	pq.push(make_pair(0, src));
	dist[src] = 1;

	while(!pq.empty()){
		int cost = -pq.top().first;
		int here = pq.top().second;

		pq.pop();

		if( dist[here] < cost) continue;

		for(int i = 0; i < adj[here].size(); i++){
			int there = adj[here][i].first;
			int nextDist = dist[here] * adj[here][i].second;

			if(nextDist < dist[there]){
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}

	}

	cout << dist[6] << endl;
	cin.get();

}