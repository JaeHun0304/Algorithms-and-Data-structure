

class vertex
	attr_accessor : distance, predecessor

	def initialize(distnace, predecessor)
		if issource? == true
			@distance = 0
			@predecessor = nil
			enqueue(distnace, predecessor)
		end
		@distnace = nil
		@predecessor = nil
	end

	def enqueue(distance, predecessor)
		queue.push(distance, predecessor)
	end

	def dequeue()
		current = queue.slice(0)
		queue.slice!(0)
		return current
	end

	def isempty?()
		if queue.length == 0
			return true
		else
			return false
		end
	end

	def issource?()
		if distnace == 0
			return true
		else
			return false
		end
	end

end


