def decimal_val(numerator,denominator,num_places)
	n = numerator
	d = denominator
	dp = 0
	retString = "0"
	nVals = [n]

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
		
		index = nVals.index(n)
		if  index == nil
			nVals += [n]
		else
			retString = retString[0...index+1] + "(" + retString[index+1...retString.length] + ")"
			return retString
		end
		
		retString += (n/d).floor.to_s
		n = n%d
		
		if n == 0
			return retString
		end
			
		dp += 1
	end
	
	return retString
end

def cycle_length(num)
	numS = num.to_s
	index = numS.index('(')
	cl = 0
	
	if index != nil
		cl = numS.length - index - 2
	end
	
	return cl
end

i = 2
longest = 0
solution = ""

while i < 1000
	temp = cycle_length(decimal_val(1,i,10000))
	if temp > longest
		longest = temp
		solution = "1/#{i} has a cycle length of: #{temp}"
	end

	i += 1
end

puts solution
