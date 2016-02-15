=begin
	Program by Ben Barnett
	2/14/16
	https://projecteuler.net/problem=51
=end

require 'thread'
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

#function for formatting time to look pretty
def pretty_time(num_seconds)
	temp = num_seconds	

	hours = temp/3600
	temp = temp%3600

	minutes = temp/60
	temp = temp%60

	if hours > 0
		return "#{hours} Hours, #{minutes} Minutes, and #{temp} Seconds"
	elsif minutes > 0
		return "#{minutes} Minutes and #{temp} Seconds"
	else
		return "#{temp} Seconds"
	end
end

prime_hash = Hash.new(0)
smallest_prime_hash = Hash.new
#actual_family = Hash.new([])
range_start = 100000000
range_end = 10000000000
prime_family = 8 #the size of the prime family to find
num_threads = 10
prime_threads = Array.new(num_threads)
increment = (range_end-range_start)/num_threads
start_val = range_start
end_val = 0
semaphore = Mutex.new

=begin
	Creating num_threads threads to check prime value families
	threads check range of 1/num_threads prime numbers each
	sv = starting value
	ev = ending value
	ph = prime_hash - Where prime families are stored
	sph = smallest_prime_hash - Where first value in prime family is stored
	pt = prime_threads - array of threads
	ti = thread index in prime_threads array
=end

num_threads.times do |x|
	
	start_val += increment if x > 0
	
	if x == num_threads-1
		end_val = range_end
	else
		end_val = start_val + increment
	end

	prime_threads[x] = Thread.new(start_val, end_val, prime_hash, smallest_prime_hash, prime_threads, x) do |sv, ev, ph, sph, pt, ti|
		
		prime_file = File.new("primes_to_10_billion.txt", "r")
		within_range = true
		halfway = false
		solution_val = 0

		puts "Thread #{ti} Created. Checking primes between #{sv} and #{ev}"
		sleep(5)

		beginning_time = Time.now

		while (line = prime_file.gets) && solution_val==0 && within_range
			temp = line.to_i
			if temp < sv
				next
			elsif temp >= ev
				within_range = false
			else
				#check if thread is more than half way through its range
				if !halfway && temp > ev/2
					halfway = true
					end_time = Time.now
					puts "Thread #{ti} 50% done - Execution time: #{pretty_time((end_time - beginning_time).ceil)}"
				end

				temp = temp.to_s.split("").map(&:to_i)
				i = 0
				while i < temp.length
					j = i+1
					while j < temp.length
						if temp[i] == temp[j]
							p_hash = Array.new(temp)
							p_hash[i] = -1
							p_hash[j] = -1

							semaphore.synchronize do
								ph[p_hash] += 1
								p_int = array_to_int(temp)
								#af[p_hash] = af[p_hash] + [p_int]

								if ph[p_hash] == 1
									sph[p_hash] = temp									
								end
							end
							
							if ph[p_hash] == prime_family
								end_time = Time.now
								solution_val = array_to_int(sph[p_hash])
								puts "Thread #{ti}: Solution found! - Execution time: #{pretty_time((end_time - beginning_time).ceil)}"
								puts "Solution: #{solution_val} => #{p_hash}"
								#puts "Family: #{p_hash} => #{actual_family[p_hash]}"
								k = 0
								while k < pt.length
									Thread.kill(pt[k]) if k != ti
									k += 1
								end
							end
						end
						j += 1
					end 
					i += 1
				end 
			end
		end

		if solution_val == 0
			end_time = Time.now
			puts "Thread #{ti}: No #{prime_family} prime family found. - Execution time: #{pretty_time((end_time - beginning_time).ceil)}"		
		end
		prime_file.close
	end
	sleep(1)
end

prime_threads.each{|t| t.join}
