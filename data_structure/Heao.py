
def push_heap(heap, insert_number):
	heap.append(insert_number)
	index = len(heap) - 1

	while((index > 0 ) and (heap[(index-1)//2] < heap[index])):
		heap[index], heap[(index-1)//2] = heap[(index-1)//2], heap[index]
		index = (index-1)//2

def pop_heap(heap):
	ret = heap[0]
	heap[0] = heap.pop()
	index = 0
	while(True):
		if 2*index+1 >= len(heap):
			break
		if heap[2*index+1] > heap[2*index+2]:
			heap[index], heap[2*index+1] = heap[2*index+1], heap[index]
			index = 2*index+1
		else:
			heap[index], heap[2*index+2] = heap[2*index+2], heap[index]
			index = 2*index+2
	return ret

def change_heap(heap, pos, increment):
	heap[pos] += increment
	index = pos
	while(True):
		if heap[pos] < heap[(pos-1)//2] or pos==0:
			break
		else:
			heap[pos], heap[(pos-1)//2] = heap[(pos-1)//2], heap[pos]
			pos = (pos-1)//2

heap = [6, 5, 4, 3, 2]
push_heap(heap, 7)
print(heap)
print(pop_heap(heap))
print(heap)
change_heap(heap, 1, 3)
print(heap)