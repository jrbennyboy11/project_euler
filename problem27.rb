primes = Hash.new(0)
prime_file = File.new("primes_0_1000000.txt", "r")
while (line = prime_file.gets)
	temp = line.to_i
	primes[temp] = 1
end
prime_file.close

a = -999
b = -999
n = 0

longest_chain = 0
best_a = 0
best_b = 0
a = -999
b = -999	

while a < 1000
	b = -999
	
		while b < 1000
			current_chain = 0
			n = 0
			
			while n < 1000 && primes[n**2+a*n+b] == 1
				n += 1
			end
			
			if n > longest_chain
				longest_chain = n
				best_a = a
				best_b = b
			end
		
		b += 1
	end
	a += 1
end

puts "Longest Chain: #{longest_chain}\nBest a: #{best_a}\nBest b: #{best_b}\nProduct: #{best_a*best_b}"
