

# Count number of bits that is set in the given number
def CountBits(num):
	if num == 0:
		return "please pass the number which is not 0"
	if num < 0:
		return "please pass the positive number"
	counter = 0
	while num != 0:
		if num & 1 == 1:
			counter += 1
		num = num >> 1
	return counter