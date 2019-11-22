adj = [[1, 9], [2, 5, 7], [1, 3, 4, 5], [2], [2], [1, 2, 6], [5], [1, 8, 9], [7], [7, 0]]
visited = []

def dfs(here):
	print("DFS visits " + str(here))
	visited[here] = True
	# search all the adjacent edge from here
	for i in range(len(adj[here])):
		there = adj[here][i]
		# if there is not visited yet go there
		if visited[there] == False:
			print("from " + str(here) + " to " + str(there))
			dfs(there)

	print(here)	


def dfsAll(adj):
	# visited is the global list
	global visited
	visited = [False] * len(adj)
	# if node is not visited, visit that node
	for i in range(len(adj)):
		if visited[i] == False:
			dfs(i)

dfsAll(adj)