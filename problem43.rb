pandigital = [0,1,2,3,4,5,6,7,8,9]
pandigitals = pandigital.permutation.to_a
sum = 0

pandigitals.each do |p|
	if p[0] != 0
		num1 = p[1]*100+p[2]*10+p[3]
		num2 = p[2]*100+p[3]*10+p[4]
		num3 = p[3]*100+p[4]*10+p[5]
		num4 = p[4]*100+p[5]*10+p[6]
		num5 = p[5]*100+p[6]*10+p[7]
		num6 = p[6]*100+p[7]*10+p[8]
		num7 = p[7]*100+p[8]*10+p[9]
	
		if num1%2==0 && num2%3==0 && num3%5==0 && num4%7==0 && num5%11==0 && num6%13==0 && num7%17==0
			temp = 0
			i = 9
			
			while i >= 0
				temp += p[9-i]*10**i
				i -= 1
			end
			
			puts temp
			sum += temp
		end
	end
end

puts "Solution: #{sum}"
