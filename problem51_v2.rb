=begin
	Program by Ben Barnett
	2/1/16
	https://projecteuler.net/problem=51
=end

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

primes = Array.new #array of prime numbers as integer arrays
prime_vals = Array.new #array of prime numbers as integers

beginning_time = Time.now #benchmark time to make arrays

#populating primes and prime_vals
#prime_file = File.new("primes_0_1000000.txt", "r")
prime_file = File.new("/media/ben/2TB Seagate/primes_to_10_billion.txt", "r")
while (line = prime_file.gets)
	temp = line.to_i
	prime_vals.push(temp)
	primes.push(temp.to_s.split("").map(&:to_i))
end
prime_file.close

end_time = Time.now #benchmark time to make arrays
puts "Finished populating arrays - Time Taken: #{(end_time - beginning_time).ceil} seconds"

starting_number = 900000 #number for threads to start on
start_index = 0 #index for thread to start on
start_index += 1 while prime_vals[start_index] < starting_number
num_threads = 12 #number of threads to use
primes_each = (prime_vals.length-start_index)/num_threads
primes_range = Array.new
prime_threads = Array.new

(num_threads-1).times do |x|
	primes_range[x] = start_index+(x+1)*primes_each
end
primes_range[num_threads-1] = prime_vals.length

num_threads.times do |x|
	prime_threads[x] = Thread.new(x,primes[start_index..primes_range[x]], prime_vals, *prime_threads){
		|thread_num,my_primes,primeList|

		puts "Thread #{thread_num} - Checking primes: #{my_primes[0]} to #{my_primes[my_primes.length-1]}"
		percent_done = 1
		one_percent = my_primes.length/100
		onep_progress = one_percent
		beginning_time = Time.now
		onep_start = Time.now
		
		my_primes.each do |prime| #itterate through each prime. primes are in array form
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
			
						family_size += 1 if primeList.index(replaced_number) != nil 
					end
			
					#if 8 prime family is found
					if family_size == 8 
						end_time = Time.now
						
						i = 0
						prime_threads.each do |t|
							Thread.kill(t) if i != 6
							i += 1
						end
						sleep(5)

						puts "\n\nBy replacing digit #{i} and #{j} of #{array_to_int(prime)}, you get an 8 prime value family"
						puts "Execution time: #{(end_time - beginning_time).ceil} seconds"
						sleep(5)	
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
				puts "Thread #{thread_num}: Checked #{percent_done}% of primes. Time elapsed: #{(onep_end - onep_start).ceil} seconds"
				onep_progress = one_percent
				percent_done += 1
			end
		end
		
		#If no 8 prime family is found
		end_time = Time.now
		puts "Thread #{thread_num}: No 8 prime family found. - Execution time: #{(end_time - beginning_time).ceil} seconds"
	}
	start_index = primes_range[x]
	sleep(1)
end

prime_threads.each{|t| t.join}
