
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <tuple>

void BFS(std::vector<std::vector<int>> &adjlist, std::vector<std::vector<int>> &vertex, int n, int source);

int main(void){

	std::vector<std::vector<int>> adjList = {
    {1},
    {0, 4, 5},
    {3, 4, 5},
    {2, 6},
    {1, 2},
    {1, 2, 6},
    {3, 5},
    {}
    };

    std::vector<std::vector<int>> vertex;
    int source = 3;

    for(int i = 0; i < 8; i++){
	if(source == i){
		vertex[i][0] = 0;
		vertex[i][1] = 1000;
		vertex[i][2] = source;
	}
	else{
		vertex[i][0] = 1000;
		vertex[i][1] = 1000;
		vertex[i][2] = i;
	}
}

	for(int k1 = 0; k1 < 8; k1++){
    	for(int k2 = 0; k2 < 3; k2++){
    		std::cout << vertex[k1][k2] << " ";
    	}
    	std::cout << "\n";
    }

    BFS(adjList, vertex, 8, 3);

    for(int k1 = 0; k1 < 8; k1++){
    	for(int k2 = 0; k2 < 3; k2++){
    		std::cout << vertex[k1][k2] << " ";
    	}
    	std::cout << "\n";
    }
    
	return 0;
}




void BFS(std::vector<std::vector<int>> &adjlist, std::vector<std::vector<int>> &vertex, int n, int source){

	std::queue<std::tuple<int, int, int>> queue; //if argument is more than 2, use std::tuple for generalized version of the std::pair

	queue.push(std::make_tuple(vertex[source][0], vertex[source][1], vertex[source][2]));

	while(queue.size() != 0){
		std::tuple<int, int, int> temp = queue.front();
		queue.pop();

		for(int j = 0; j < n; j++){
			for(int l = 0; l < adjlist[std::get<2>(temp)].size(); l++){
				if( j == adjlist[std::get<2>(temp)][l] && vertex[j][0] == 1000){
					vertex[j][0] = std::get<0>(temp) + 1;
					vertex[j][1] = std::get<2>(temp);
					queue.push(std::make_tuple(vertex[j][0], vertex[j][1], vertex[j][2]));
				}
			}
		}
	}

}