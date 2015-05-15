primes = Hash.new(0)
prime_file = File.new("primes_0_1000000.txt", "r")
while (line = prime_file.gets)
	temp = line.to_i
	primes[temp] = 1
end
prime_file.close

masterHash = Hash.new(0)

primes.keys.each do |prime|
	if prime >= 1000 && prime <= 9999
		currPrime = prime.to_s.split('')
		tempHash = Hash.new(0)
		
		currPrime.permutation.to_a.each do |p|
			if p[0].to_i != 0
				val = p[0].to_i*1000+p[1].to_i*100+p[2].to_i*10+p[3].to_i
				if primes[val] == 1 then tempHash[val]=1 end
			end
		end
		
		if tempHash.keys.length >= 3
			masterHash[tempHash.keys.sort] = 1
		end
	end
end

masterHash.keys.each do |set|
	#print set
	#puts ""
	
	dif = Hash.new(Array.new)
	i = 0
	while i < set.length
		j = i+1
		while j < set.length
			difference = set[j].to_i-set[i].to_i
			dif[difference] += [set[i].to_i,set[j].to_i]
			j += 1
		end
		i += 1
	end
	
	dif.each_value do |x|
		if x.length != x.uniq.length
			print x.uniq
			print " | "
			print dif.key(x)
			puts "\n"
		end
	end
end
