def digit_sum_5th_power(n)
  n.to_s.each_char.map {|c| c.to_i**5 }.reduce(:+)
end

i=2
total = 0

while i<1000000 do
	if(i == digit_sum_5th_power(i))
		puts i
		total += i
	end
	i += 1
end

puts "Solution to problem 30: #{total}"
