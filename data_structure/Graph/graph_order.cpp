#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <iterator>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;

void makeGraph(const vector<string>& words){
	adj = vector<vector<int>>(26, vector<int>(26, 0));
	for(int j=1; j < words.size(); ++j){
		int i = j-1; int len = min(words[i].size(), words[j].size());

		for(int k=0; k < len; ++k){
			if(words[i][k] != words[j][k]){
			int a = char(words[i][k]) - 'a';
			int b = char(words[j][k]) - 'a';
			adj[a][b] = 1;
			break;
			}
		}
	}
}

int main(){

	unordered_set<char> answer;
	vector<string> words = {"google", "apple", "microsoft"};
	makeGraph(words);

	for(int i=0; adj.size(); ++i){
		for(int j=0; adj[i].size(); ++j){
			if(adj[i][j] == 1)
				answer.insert(char(i + 97));
		}
	}

	for(unordered_set<char>::const_iterator it = answer.cbegin(); it != answer.cend(); ++it){
		cout << *it << " ";
	} cout << endl;

	return 0;
}