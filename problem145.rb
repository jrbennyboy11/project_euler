def reverse(n)
	nCpy = n
	nReverse = 0

	while nCpy >= 10
		nReverse *= 10
		nReverse += nCpy%10
		nCpy /= 10
	end
	
	nReverse *= 10
	nReverse += nCpy

	return nReverse
end

def made_of_odds(n)
	nCpy = n

	while nCpy >= 10
		if((nCpy%2) == 0)
			return false
		end
		
		nCpy /= 10
	end

	if((nCpy%2) == 0)
		return false
	end

	return true
end

i = 1
reversibles = 0
CUT_OFF = 10**9
onePercent = CUT_OFF/100

while i < CUT_OFF
	if (i%10) != 0 && made_of_odds(i+reverse(i))
		reversibles += 1
	end

	if i%onePercent == 0
		puts "#{i/onePercent}%"
	end

	i += 1
end

puts "Reversibles below #{i}: #{reversibles}"
