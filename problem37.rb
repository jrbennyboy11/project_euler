primes = Hash.new(0)
prime_file = File.new("primes_0_1000000.txt", "r")
while (line = prime_file.gets)
	temp = line.to_i
	primes[temp] = 1
end
prime_file.close

sum = 0

primes.keys.each do |prime|
	if prime > 10
		valid = true
		
		#left to right
		primeCpy = prime.to_s
		while primeCpy.length > 1 && valid
			primeCpy = primeCpy[1..primeCpy.length]
			if primes[primeCpy.to_i] == 0 then valid = false end
		end
	
		#right to left
		primeCpy = prime.to_s
		while primeCpy.length > 1 && valid
			primeCpy = primeCpy[0..primeCpy.length-2]
			if primes[primeCpy.to_i] == 0 then valid = false end
		end
		
		if valid
			sum += prime
			puts prime
		end
	end
end

puts "\nSolution: #{sum}"

=begin
left = true
right = false
direction = left
temp = "3797"

while temp.length > 1
	if direction == left
		temp = temp[1..temp.length]
		direction = right
	else
		temp = temp[0..temp.length-2]
		direction = left
	end
	puts temp
end
puts "----------------"
direction = right
temp = "3797"

while temp.length > 1
	if direction == left
		temp = temp[1..temp.length]
		direction = right
	else
		temp = temp[0..temp.length-2]
		direction = left
	end
	puts temp
end
=end
