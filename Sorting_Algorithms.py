"""" Various Sorting Algorithms will be implemented here in Python """
import pdb

def insertionsort(numbers):
	"""" Sort passing numbers with insertion sort with non decreasing order """
	for number in range(1, len(numbers)):
		key = numbers[number]
		index = number - 1
		while index >= 0 and numbers[index] > key:
			numbers[index + 1] = numbers[index]
			index = index - 1
		numbers[index + 1] = key
	return numbers

def reverse_insertionsort(numbers):
	""" Sort passing number lists with insertion sort and non increasing order """
	for number in range(1, len(numbers)):
		key = numbers[number]
		index = number - 1
		while index >= 0 and numbers[index] < key:
			numbers[index + 1] = numbers[index]
			index = index - 1
		numbers[index + 1] = key
	return numbers

def linear_search(numbers, target):
	""" search matching data linearly """
	for number in numbers:
		if number == target:
			message = "Matching data found!, which is " + str(number)
			return message
	message = "Matching data not found!, which is " + str(target)
	return message

def mergesort(numbers):
	""" Sort passing list with ascending order with mergesort, one of divide and conquer approach"""
	

test_list = [1, 6, 3, 2, 5, 9]
print(test_list)

insertionsort(test_list)
print(test_list)

reverse_insertionsort(test_list)
print(test_list)

print(linear_search(test_list, 5))
print(linear_search(test_list, 11))
