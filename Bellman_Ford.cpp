#include <vector>
#include <iostream>
#include <limits>

using namespace std;

/*
	This is the code that implements bellman-ford alogrithm to find the shortest path
	and minimum distance

	JaeHun Jung
*/

int main() {

	// V: number of node MAX_V: max number of node supported
	int V = 7;
	int MAX_V = 20;
	int INF = numeric_limits<int>::max();
	// graph made with adjacent vector which contains (destination, distance)
	vector< pair<int, int> > adj[MAX_V];
	// the initial source node for starting the algorithm
	int src = 0;

	// Adjacent vector initialization
	adj[0] = { make_pair(1, 5), make_pair(2, 1) };
	adj[1] = { make_pair(0, 5), make_pair(3, 1), make_pair(5, 3), make_pair(6, 3)};
	adj[2] = { make_pair(0, -2), make_pair(3, 2)};
	adj[3] = { make_pair(1, 1), make_pair(2, 2), make_pair(4, 5), make_pair(5, 3)};
	adj[4] = { make_pair(3, 5)};
	adj[5] = { make_pair(1, 3), make_pair(6, 2), make_pair(3, 3)};
	adj[6] = { make_pair(1, 3), make_pair(5, 2)};

	// initialize upper array with maximum int values
	vector<int> upper(V, INF);
	// flag to check whether the node is relaxed or not
	bool updated;

	upper[src] = 0;

	// go over all the node
	for(int i = 0; i < V; i++){
		// set flag false, nothing is relaxed yet
		updated = false;
		// go over from here = i to end of the node
		for(int here = 0; here < V; here++){
			// go over here's adjacent node
			for(int j = 0; j < adj[here].size(); j++){
				// destination node pulled from the adj[here] vector
				int there = adj[here][j].first;
				// if current upper vector holds value larger than distance here + distance from here to there,
				// update upper vector value
				if(upper[there] > upper[here] + adj[here][j].second){
					upper[there] = upper[here] + adj[here][j].second;
					// set updated flag to true
					updated = true;
				}
			}
		}
		// If updated flag is still false, that means no single node has been relaxed, no need to further execute the loop
		if(!updated) break;
	}

	// if updated flag is still ture, that means there is minus weight in the cycle of the graph
	if(updated){
		cout << "There is a minus weight in the graph cycle" << endl;
		cin.get();
	}
	else{
		cout << upper[6] << endl;
		cin.get();
	}

}