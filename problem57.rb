=begin
	Program by Ben Barnett
	2/1/16
	https://projecteuler.net/problem=57
	
	I solved this one by taking the information they gave me about the first 8 numerators and denominators and comparing them side by side in excel. I noticed that the numerator was going up by 2 times the denominator, and the denominator was going up by 1 tims the numerator, each time. This made writing a program extremely easy. 
=end

require 'benchmark'

numerator = 3
denominator = 2
num_md_denom = 0 #numerator has more digits than denominator

beginning_time = Time.now

1000.times do |x|
	temp = numerator
	numerator += 2*denominator
	denominator += temp
	
	num_md_denom += 1 if numerator.to_s.length > denominator.to_s.length
end

end_time = Time.now

puts "Solution: #{num_md_denom} fractions of the first 1000 expansions"
puts "Execution Time: #{(end_time - beginning_time).ceil} seconds"
