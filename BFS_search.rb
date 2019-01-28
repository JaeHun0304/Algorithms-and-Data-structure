def enqueue queue, distance, predecessor, id
	queue.push(distance, predecessor, id)
end

def dequeue queue
	current = queue.slice(0)
	queue.slice!(0)
	return current
end


adj_list = [[1], [0,4,5], [3,4,5], [2,6], [1,2], [1,2,6], [3,5], []]
ver_list = [[nil,nil,0], [nil,nil,1], [nil,nil,2], [0,nil,3], [nil,nil,4], [nil,nil,5], [nil,nil,6], [nil,nil,7]]
queue = []

enqueue(queue, ver_list[3][0], ver_list[3][1], ver_list[3][2])

	while queue.empty? == false
		temp = dequeue(queue)
			for i in 0..adj_list.length
				if (temp[2] == i)
					for j in 0..adj_list[i].length
					if ver_list[adj_list[i][j]][0] == nil
						ver_list[adj_list[i][j]][0] = temp[0] + 1
						ver_list[adj_list[i][j]][1] = temp[1]
						enqueue(queue, ver_list[adj_list[i][j]][0], ver_list[adj_list[i][j]][1], ver_list[adj_list[i][j]][2])
					end
					end	
				end
			end
	end

print ver_list