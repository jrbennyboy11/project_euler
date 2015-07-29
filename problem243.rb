resilience_below = Rational(15499,94744)
current_resilience = Rational(1)
i = 1

while(current_resilience >= resilience_below)
	if i%1000 == 0 then puts "i: #{i}" end

	j = 1
	i += 1
	num_resilient = 0
	
	while(j < i)
		if(Rational(j,i).denominator == i) then num_resilient += 1 end
		j += 1
	end
	
	current_resilience = Rational(num_resilient,i-1)
end

puts "Smallest denominator having R(d) < 15499/94744 = #{i}"
