
adj = [[0] * 26] * 26 # Store adjacent matrix graph in 26x26 list

# makeGraph will find arbitrary dictionary order from the given string list
# For instance, order(make -> cake) in the strings, 'm' should come first than 'c'
def makeGraph(words):

	for i in range(1, len(words)):
		j = i-1 # compare words[i] and words[j]
		min_len = min(len(words[i]), len(words[j])) # return min search length
		for k in range(min_len):
			if words[i][k] != words[j][k]:
				a = ord(words[i][k]) - ord('a') #ord will return the int value of ASCII character
				b = ord(words[i][k]) - ord('a')
				adj[a][b] = 1	# If a -> b is order, convert matrix value to one


# create examples string list and empty set
examples = ["microsoft", "apple", "google"]
makeGraph(examples)
answers = set()	
	
for i in range(len(adj)):
	for j in range(len(adj[i])):
		if adj[i][j] == 1:
			answers.add(str(chr(i + 97))) #add ASCII converted character to the answers set
# print result
print(answers)