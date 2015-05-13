#73682

def num_ways(money, ival)
	money_copy = Array.new(8)
	money_copy = money
	i = ival
	count = 1
	
	while i<7
		while money_copy[i] > 0
			print money_copy
			puts ""
			if i == 0
				money_copy[0] -= 1
				money_copy[1] += 2
				count += num_ways(money_copy,1)
			end
			if i == 1
				money_copy[1] -= 1
				money_copy[2] += 2
				count += num_ways(money_copy,2)
			end
			if i == 2
				money_copy[2] -= 1
				money_copy[3] += 2
				money_copy[4] += 1
				count += num_ways(money_copy,3)
			end
			if i == 3
				money_copy[3] -= 1
				money_copy[4] += 2
				count += num_ways(money_copy,4)
			end
			if i == 4
				money_copy[4] -= 1
				money_copy[5] += 2
				count += num_ways(money_copy,5)
			end
			if i == 5
				money_copy[5] -= 1
				money_copy[6] += 2
				money_copy[7] += 1
				count += num_ways(money_copy,6)
			end
			if i == 6
				money_copy[6] -= 1
				money_copy[7] += 2
				count += 1
			end
		end
		
		i += 1 
	end
	
	return count
end

money = [1,0,0,0,0,0,0,0] #200p, 100p, 50p, 20p, 10p, 5p, 2p, 1p
puts "Num ways: #{num_ways(money,0)}"
