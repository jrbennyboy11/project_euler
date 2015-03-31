primes = []
prime_file = File.new("primes_0_1000000.txt", "r")
while (line = prime_file.gets)
	tempArray = [line.to_i]
	primes += tempArray
end
prime_file.close

i = 0
k = 0
j = 0
sumMostConsecutive = 953
consecutiveCount = 21

while primes[i]<1000000 do
	j = 0
	if(i%100 == 0)
		puts "i: #{i}"
	end
	while j<i && i-j>consecutiveCount && primes[j]<(primes[i]/2) do
		k = j
		sum = 0
		count = 0
		
		while sum<primes[i] do
			sum += primes[k]
			count += 1
			k+=1
		end
		
		if sum == primes[i] && count > consecutiveCount
			sumMostConsecutive = primes[i]
			consecutiveCount = count
		end
		j+=1
	end
	i+=1
end

puts "Prime under a million that is sum of most consecutive primes: #{sumMostConsecutive}"
