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
#Checked everything under 100000000
#none in 10000000 to 100000000
start_val = 10000
end_val = 10000000#1000000000
prime_family = 8 #the size of the prime family to find
num_threads = 6 #number of threads to use
prime_threads = Array.new(num_threads) 
semaphore = Mutex.new #lock for prime_hash and smallest_prime_hash
file_lock = Mutex.new #lock for prime_file
prime_file = File.new("primes_to_10_billion.txt", "r")
#lower_bound = 10**(start_val.to_s.length-1)
#upper_bound = lower_bound*10
#lower_bound = start_val

puts "Target: #{prime_family} member prime family"
puts "Checking #{end_val - start_val} primes from #{start_val} to #{end_val} with #{num_threads} threads"
#puts "Starting with prime set #{lower_bound} - #{upper_bound}"

prog_start = Time.now

=begin
	Creating num_threads threads to check prime value families
	pf = prime_file - File containing prime numbers - shared amongst the threads	
	sv = starting value - will check first prime greater than this value
	ev = ending value - will not check any primes greater than this value
	ph = prime_hash - Where prime families are stored
	sph = smallest_prime_hash - Where first value in prime family is stored
	pt = prime_threads - array of threads
	ti = thread index in prime_threads array
=end

num_threads.times do |x|
	prime_threads[x] = Thread.new(prime_file, start_val, end_val, prime_hash, smallest_prime_hash, prime_threads, x) do |pf, sv, ev, ph, sph, pt, ti| #lb, ub|
		#log = File.new("Thread#{ti}.txt", "w") if logging
		#counter = 0		
		within_range = true		
		solution_val = 0
		status_update = false
		update_val = ((end_val-start_val)/pt.length)*(ti+1) + sv

		#log.write("#{Time.now}: Thread #{ti} Created. Checking primes between #{sv} and #{ev}\n") if logging
		if ti == prime_threads.length-1
			puts "Thread #{ti}: Created."
			update_val = end_val*10
		else		
			puts "Thread #{ti}: Created. Giving status update after #{update_val} is reached."
		end		
		sleep(1)

		beginning_time = Time.now

		line = ""
		while solution_val==0 && within_range
			file_lock.synchronize{line = pf.gets}
			temp = line.to_i

=begin
			#clear arrays and give update since families have the same number of digits
			if temp > ub
				semaphore.synchronize do
					end_time = Time.now			
					lb *= 10					
					ub *= 10
					ub = ev if ub > ev
					puts "Thread #{ti}: Upper Bound Reached"
					puts "Thread #{ti}: Stats from primes #{lb} - #{ub}:"
					largest_fam = ph.max_by{|k,v| v}
					puts "Thread #{ti}: Total Prime Families: #{sph.length}"
					puts "Thread #{ti}: Largest Family Found: #{sph[largest_fam[0]]} with #{largest_fam[1]} members"
					puts "Thread #{ti}: Time Elapsed: #{pretty_time((end_time - beginning_time).ceil)}"
					puts "Thread #{ti}: Now checking prime set #{lb} - #{ub}"

					ph.clear
					sph.clear

					sleep(5)
				end
			end
=end

			if !status_update && temp > update_val
				end_time = Time.now
				puts "Thread #{ti}: Reached #{update_val}. #{ti+1}/#{pt.length} completed - Time Elapsed: #{pretty_time((end_time - beginning_time).ceil)}"
				#log.write("#{Time.now}: Thread #{ti}: Passed #{update_val}. #{ti+1}/#{pt.length} completed\n") if logging
				#log.write("#{Time.now}: Thread #{ti} - Total Time Elapsed: #{pretty_time((end_time - beginning_time).ceil)}\n") if logging
				status_update = true
			end
=begin
			counter += 1
			if counter > 100000
				counter = 0
				#sleep(1)
				#log.write("#{Time.now}: Thread #{ti} - Currently on: #{temp}\n") if logging
			end
=end
			if temp < sv
				next
			elsif temp >= ev
				within_range = false
			else
				temp = temp.to_s.split("").map(&:to_i)
				i = 0
				while i < temp.length
					j = i+1
					while j < temp.length
						if temp[i] == temp[j]
							p_hash = Array.new(temp)
							p_hash[i] = -1
							p_hash[j] = -1
							#p_int = array_to_int(temp)

							semaphore.synchronize do
								ph[p_hash] += 1

								if ph[p_hash] == 1
									sph[p_hash] = p_hash
								elsif ph[p_hash] >= prime_family
									end_time = Time.now
									solution_val = array_to_int(sph[p_hash])
									puts "Thread #{ti}: Solution found! - Execution time: #{pretty_time((end_time - beginning_time).ceil)}"
									puts "Solution: #{solution_val} => #{p_hash}"
									#log.write("#{Time.now}: Thread #{ti}: Solution found! - Execution time: #{pretty_time((end_time - beginning_time).ceil)}\n") if logging
									#log.write("#{Time.now}: Solution: #{solution_val} => #{p_hash}\n") if logging
									k = 0
									while k < pt.length
										Thread.kill(pt[k]) if k != ti
										k += 1
									end							
								end
							end
						end
						j += 1
					end 
					i += 1
				end 
			end
		end
		puts "Thread #{ti}: No #{prime_family} member prime families found"
	end #end thread function
	sleep(1)
end

prime_threads.each{|t| t.join}
prime_file.close
prog_end = Time.now
largest_fam = prime_hash.max_by{|k,v| v}
puts "Total Prime Families: #{smallest_prime_hash.length}"
puts "Largest Family Found: #{smallest_prime_hash[largest_fam[0]]} with #{largest_fam[1]} members"
puts "Total Elapsed Program Time: #{pretty_time((prog_end - prog_start).ceil)}"
