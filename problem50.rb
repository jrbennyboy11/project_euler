primes = Hash.new(0)
prime_file = File.new("primes_0_1000000.txt", "r")
while (line = prime_file.gets)
	temp = line.to_i
	primes[temp] = 1
end
prime_file.close

sumMostConsecutive = 953
consecutiveCount = 21
i = 0
j = 0
k = 0

pkeys = primes.keys

while i < pkeys.length
	j = i+1
	currSum = pkeys[i]
	currCount = 1
	
	while j < pkeys.length && currSum < 1000000
		currSum += pkeys[j]
		currCount += 1
		if primes[currSum] == 1 && currCount > consecutiveCount
			sumMostConsecutive = currSum
			consecutiveCount = currCount
		end
		j += 1
	end
	 
	i += 1
end


puts "#{sumMostConsecutive} is the sum of #{consecutiveCount} consecutive primes"
