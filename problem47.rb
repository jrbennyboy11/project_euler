primes = []
prime_file = File.new("primes_0_1000000.txt", "r")
while (line = prime_file.gets)
	temp = line.to_i
	primes += [temp]
end
prime_file.close

num_consec = 0
answer = 0
found = false
i = 644

while !found
	num_facts = 0
	j = 0
	while primes[j] <= i
		if i%primes[j]==0 then num_facts+=1 end
		j += 1
	end
	
	if num_facts == 4
		num_consec += 1
		if num_consec==1 then answer = i end
	else
		num_consec = 0
	end
	
	if num_consec == 4 then found=true end
	i += 1
end

puts "Solution: #{answer}"
