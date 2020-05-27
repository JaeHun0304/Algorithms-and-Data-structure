#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

vector<vector<int>> adj = {
                           {1, 3, 4, 7},
                           {0, 3, 2},
                           {1, 5, 6},
                           {0, 1, 6},
                           {0, 5},
                           {2, 4},
                           {2, 3, 8},
                           {0},
                           {6}
                          };
vector<int> parent(adj.size(), -1);
vector<int> dist(adj.size(), -1);

vector<int> bfs(int start){
  vector<bool> discovered(adj.size(), false);
  queue<int> visit_list;
  vector<int> visit;

  discovered[start] = true;
  visit_list.push(start);

  while(!visit_list.empty()){
    int here = visit_list.front();
    visit_list.pop();

    visit.push_back(here);

    for(int i = 0; i < adj[here].size(); i++){
      int there = adj[here][i];

      if(!discovered[there]){
        visit_list.push(there);
        discovered[there] = true;
      }     
    }
  }
  return visit;
}

/*
int main(){

  queue<int> q;
  parent[0] = 0;
  dist[0] = 0;
  q.push(0);

  while(!q.empty()){
    int here = q.front();
    q.pop();

    for(int i = 0; i < adj[here][i]; i++){
      int there = adj[here][i];
      if(dist[there] == -1){
        dist[there] = dist[here] + 1;
        parent[there] = here;
        q.push(there);
      }
    }
  }

  vector<int> path(1, 8);
  int v = 8;
  while(parent[v] != v){
    v = parent[v];
    path.push_back(v);
  }
  reverse(path.begin(), path.end());
  for(vector<int>::iterator iter = path.begin(); iter != path.end(); ++iter)
    cout << *iter << " ";

}
*/