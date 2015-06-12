=begin

Benjamin Barnett
6/12/15
https://projecteuler.net/problem=56

=end


def digit_sum(num)
	sum = 0
	num.to_s.split('').each{|d| sum+=d.to_i}
	return sum
end

max = 0
i = 1
max_i = 0
max_j = 0

while i < 100
	j = 1
	while j < 100
		ds = digit_sum(i**j)
		if ds > max
			max = ds
			max_i = i
			max_j = j
		end
		j += 1
	end
	i += 1
end

puts "#{max_i}^#{max_j} has a digit sum of #{max}"


