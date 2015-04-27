n1 = 5
d1 = 7
n2 = 7
d2 = 10

mult = 3

while d1*mult < 1000000000000.0	
	t1 = n1+n2
	t2 = d1+d2
	
	n2 = t1 #12
	d2 = t2 #17
	n1 = t2 #17
	d1 = t1*2
	mult += 2
	
	#puts "#{n1*mult}/#{d1*mult} , #{n2*mult}/#{d2*mult}"
end

puts "Number of blue discs: #{n1*mult}"

#2b*(b-1) = t*(t-1)
