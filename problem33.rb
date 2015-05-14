def reduce(numerator,denominator)
	n = numerator.to_i
	d = denominator.to_i
	if d==0 || n==0 then return "#{n}/#{d}" end
	if n > d then max = n else max = d end
	largest_common = largest_common_denom(n,d)
	return "#{n/largest_common}/#{d/largest_common}"
end

def largest_common_denom(x,y)
	largest = 1
	if x > y then max = y else max = x end
	
	for i in 2..max
		if x%i == 0 && y%i == 0
			largest = i
		end
	end
	
	return largest
end

i = 10
j = 10

#given 49/98
num = 49
denom = 98

while i < 100 #denominator
	j = 10 #numerator
	while j < i
		if i != j && ((i/10 == j%10) || (j/10 == i%10))
			largest = largest_common_denom(i,j)
			reduced = reduce(j,i)
			n = reduced[0..reduced.index('/')].to_i
			d = reduced[reduced.index('/')+1..reduced.length].to_i
			
			if j/10 == n && i%10 == d && largest != j%10
				num *= n
				denom *= d
				puts "#{j}/#{i} = #{reduce(j,i)} | largest common: #{largest_common_denom(i,j)}"
			elsif j%10 == n && i/10 == d && largest != j/10
				num *= n
				denom *= d
				puts "#{j}/#{i} = #{reduce(j,i)} | largest common: #{largest_common_denom(i,j)}"
			end
		end
		j += 1
	end
	i += 1
end

reduced = reduce(num,denom)
puts "Solution: #{reduced[reduced.index('/')+1..reduced.length]}"
