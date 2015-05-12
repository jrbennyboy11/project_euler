def decimal_val(numerator,denominator,num_places)
	n = numerator
	d = denominator
	dp = 0
	retString = "0"

	if n == d
		return 1
	elsif n>d
		retString = (d/n).to_s
		n = d%n
	end
	
	retString += "."
	
	while dp < num_places
		if d > n
			n *= 10
		end
		
		retString += (n/d).floor.to_s
		n = n%d
		
		if n == 0
			while retString.length < num_places+2
				retString += "0"
			end
			
			return retString
		end
			
		dp += 1
	end
	
	return retString
end

below = decimal_val(15499,94744,50)

n = 2 #numerator
d = 10000 #denominator
res = 0 #how many resiliants
res_val = "0.9999" #resiliance value
i = 0

while below < res_val
	d += 1
	n = 2
	res = 0
	while n < d-1
		if d%n != 0
			res += 1
		end
		n += 1	
	end
	
	res_val = decimal_val(res,d-1,50)
	if i == 999
		puts "Below:  #{below}"
		puts "Resval: #{res_val}\n"
	end
	i = i+1%1000
end

puts "Solution: #{d}"
