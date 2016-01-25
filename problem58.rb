=begin
	Program by Ben Barnett
	1/24/16
	https://projecteuler.net/problem=58
=end
require 'prime'
require 'benchmark'

i = 1.0
j = 2.0
squaresize = 1
num_diagonal_nums = 1
ratio = 1.0
num_primes = 0.0

beginning_time = Time.now

while ratio >= 0.1
	num_diagonal_nums += 4
	squaresize += 2

	4.times do
		i += j
		if Prime.prime?(i)
			num_primes += 1.0
		end
	end

	#puts "There are #{num_primes} primes along the diagonals of a #{squaresize}x#{squaresize} spiral square"
	ratio = num_primes/num_diagonal_nums
	j += 2.0
end

end_time = Time.now

puts "A #{squaresize}x#{squaresize} spiral has a prime ratio on the diagonals of #{ratio}"
puts "Program Run Time: About #{(end_time - beginning_time).ceil} seconds"
