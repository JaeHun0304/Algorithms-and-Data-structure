""" check if the given string has correct pair of parentheses. That is, open "(" should be closed with ")"
	and there should be no other open parentheses with closing before that. For instance, "({)" is not correct one"""

def wellMatched(formula):
	opening = "({["
	closing = ")}]"
	openStack = []
	for i in range(len(formula)):
		if opening.find(formula[i]) != -1:
			openStack.append(formula[i])
		if closing.find(formula[i]) != -1:
			if len(openStack) == 0:
				return False
			if opening.find(openStack[-1]) != closing.find(formula[i]):
				return False
			if opening.find(openStack[-1]) == closing.find(formula[i]):
				openStack.pop()
	return len(openStack) == 0


print(wellMatched("()()"))
print(wellMatched("{){}"))

""" find all partial lists in the whole list that summed to pre-defined number K """

def simple(whole_list, k):
	"""" basic brute force search method, find every possible partial sum and check
		 the sums O(nk)"""

	ret = 0
	for head in range(len(whole_list)):
		partial_sum = 0
		for tail in range(head, len(whole_list)):
			partial_sum += whole_list[tail]
			if partial_sum == k:
				ret += 1
			if partial_sum >= k:
				break
	return ret


def simple2(whole_list, k):
	""" more efficient version by not caclulting every partial sum but append new range 
		(from tail+1) to minimize computation ~ O(n) """

	ret, tail, rangeSum = 0, 0, whole_list[0]
	
	for head in range(len(whole_list)):
		while rangeSum < k and tail+1 < len(whole_list):
			rangeSum += whole_list[tail+1]
			tail += 1
		if rangeSum == k:
			ret += 1
		rangeSum -= whole_list[head]

	return ret

sample_list = [1, 2, 3, 4, 5]
print(simple(sample_list, 5))
print(simple2(sample_list, 5))