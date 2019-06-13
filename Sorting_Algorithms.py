"""" Various Sorting Algorithms will be implemented here in Python """


def insertionsort(numbers):
	"""" Sort passing numbers with insertion sort """
	for number in range(1, len(numbers)):
		key = numbers[number]
		index = number - 1
		while index > 0 and numbers[index] > key:
			numbers[index + 1] = numbers[index]
			index = index - 1;
		numbers[index + 1] = key
	return numbers


test_list = [1, 6, 3, 2, 5, 9]
print(test_list)
insertionsort(test_list)
print(test_list)