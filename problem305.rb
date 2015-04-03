require 'thread'

def starting_position(n)
	iString = "1"
	endLoc = 1
	currNum = 1
	numOccurances = 0
	max = 100
	
	while numOccurances != n
		currNum += 1
		iString += currNum.to_s
		endLoc += currNum.to_s.length()
		
		if(currNum.to_s.length() >= max/2)
			max *= 10
		end
		
		if(iString.length() > max)
			iString = iString[max/10..iString.length()]
		end
		
		if  iString.index(n.to_s) != nil
			numOccurances += 1
			if numOccurances != n
				iString = iString[iString.index(n.to_s)+1..iString.length()]
			end
		end
		
	end
	
	return endLoc - (iString.length() - iString.index(n.to_s)) + 1
end

=begin
sum += 37 #f(3^1) = 37
sum += 169 #f(3^2) = 169
sum += 2208 #f(3^3) = 2208
sum += 4725 #f(3^4) = 4725
sum += 161013 #f(3^5) = 161013
sum += 926669 #f(3^6) = 926669
sum += 14199388 #f(3^7) = 14199388
sum += 52481605 #f(3^8) = 52481605
sum += 1660424581 #f(3^9) = 1660424581
sum += 7904203384 #f(3^10) = 7904203384
=end

sum = 0
threadArr = []

13.times do |i|
	threadArr[i] = Thread.new{
		num = i+1
		answer = starting_position(3**num)
		Thread.current["answer"] = answer
		puts "f(3^#{num}) = #{answer}"
	}
	sleep(1)
end

threadArr.each {|t| t.join; sum+=t["answer"] }
puts "sum: #{sum}"
