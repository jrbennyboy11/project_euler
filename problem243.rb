=begin
	Program by Ben Barnett
	1/24/16
	https://projecteuler.net/problem=243
=end

require 'benchmark'
require 'rational'

resilience_below = Rational(15499,94744)
current_resilience = Rational(1)
denominator = 12

tenk_start = Time.now
tenk_end = Time.now
beginning_time = Time.now

while current_resilience >= resilience_below
	i = 1
	denominator += 1
	num_resiliant = 0
	
	while i < denominator
		if Rational(i,denominator).denominator == denominator
			num_resiliant += 1
		end
		i += 1
	end

	current_resilience = Rational(num_resiliant, denominator-1)

	if(denominator%10000 == 0)
		tenk_end = Time.now
		puts "Denominator: #{denominator}"
		puts "#{denominator-10000} - #{denominator} time: About #{(tenk_end - tenk_start).ceil} seconds"
		tenk_start = Time.now
	end
end

end_time = Time.now

puts "R(#{denominator}) < 15499/94744"
puts "Program Run Time: About #{(end_time - beginning_time).ceil} seconds"
