require 'benchmark'

#function for converting integer arrays back to ints
def array_to_int(arr)
	arr_int = 0
	i = 1
	
	arr.reverse.each do |d|
		arr_int += d*i
		i *= 10
	end
	
	return arr_int
end

primes = Array.new
prime_vals = Array.new

#generating primes - array of prime numbers as integer arrays
#generating prime_vals - array of prime numbers as integers
prime_file = File.new("primes_0_1000000.txt", "r")
while (line = prime_file.gets)
	temp = line.to_i
	prime_vals.push(temp)
	primes.push(temp.to_s.split("").map(&:to_i))
end
prime_file.close

percent_done = 1
one_percent = prime_vals.length/100
onep_progress = one_percent

beginning_time = Time.now
onep_start = Time.now

primes.each do |prime| #itterate through each prime. primes are in array form
	i = 0
	while i < prime.length-1 #first digit index
		j = i+1
		while j < prime.length #2nd digit index
			family_size = 0
			
			10.times do |d| #digit to be substituted in
				temp = Array.new(prime)
				temp[i] = d
				temp[j] = d
				replaced_number = array_to_int(temp)
				
				family_size += 1 if prime_vals.index(replaced_number) != nil 
			end
			
			#if 8 prime family is found
			if family_size == 8 
				end_time = Time.now
				puts "By replacing digit #{i} and #{j} of #{array_to_int(prime)}, you get an 8 prime value family"
				puts "Execution time: #{(end_time - beginning_time).ceil} seconds"
				exit
			end
			
			j += 1 #2nd digit index + 1
		end
		i += 1 #1st digit index + 1
	end
	
	#Progress monitor - Prints time elapsed for every 10% of primes checked
	onep_progress -= 1
	if onep_progress == 0
		onep_end = Time.now
		puts "Checked #{percent_done}% of primes. Time elapsed: #{(onep_end - onep_start).ceil} seconds"
		onep_progress = one_percent
		percent_done += 1
	end
end

end_time = Time.now
puts "No 8-prime family found. Execution time: #{(end_time - beginning_time).ceil} seconds"
