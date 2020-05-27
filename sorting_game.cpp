#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

/*
int main() {
  vector<int> input_vec = {1, 2, 3, 4, 8, 7, 6, 5};
  vector<int> sorted_vec = input_vec;
  sort(sorted_vec.begin(), sorted_vec.end());

  map<vector<int>, int> distance;
  queue<vector<int>> q;

  q.push(input_vec);
  distance[input_vec] = 0;

  while(!q.empty()){
    vector<int> here = q.front(); q.pop();

    if(here == sorted_vec){
      cout << distance[here];
      return distance[here];
    }

    for(int i = 0; i < here.size(); i++){
      for(int j = i + 2; j <= here.size(); j++){
        vector<int> there = here;
        reverse(there.begin() + i, there.begin() + i + j);
        //if partial reversed vector there is not found in the distance map
        if(distance.count(there) == 0){
          distance[there] = distance[here] + 1;
          q.push(there);
        }
      }
    }
  }

  return -1;
}
*/