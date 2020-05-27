#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

/*
int main(){

  vector<int> in_vec = {1, 3, 2, 6, 8, 4, 15};
  int n = in_vec.size();
  vector<int> perm(n);
  for(int i = 0; i < n; i++) perm[i] = i;
  map<vector<int>, int> to_sort;
  queue<vector<int>> q;

  to_sort[perm] = 0;
  q.push(perm);

  while(!q.empty()){
    vector<int> here = q.front(); q.pop();

    int cost = to_sort[here];
    for(int i = 0; i < n; i++){
      for(int j = i + 2; j <= n; j++){
        reverse(here.begin() + i, here.begin() + j);
        if(to_sort.count(here) == 0){
          q.push(here);
          to_sort[here] = cost + 1;
        }
        reverse(here.begin() + i, here.begin() + j);
      }
    }
  }

  vector<int> fixed(n);
  for(int i = 0; i < n; i++){
    int ref = in_vec[i];
    int counter = 0;
    for(int j = 0; j < n; j++){
      if(ref > in_vec[j])
        counter++;
    }
    fixed[i] = counter;
  }

  for(vector<int>::iterator iter = fixed.begin(); iter != fixed.end(); iter++)
    cout << *iter << " ";

  cout << to_sort[fixed];
}
*/