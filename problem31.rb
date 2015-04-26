num_ways = 1
money = [0,0,0,0,0,0,0,200] #200p, 100p, 50p, 20p, 10p, 5p, 2p, 1p
i = 0

while(money[0] == 0)
	puts "[#{money[0]}, #{money[1]}, #{money[2]}, #{money[3]}, #{money[4]}, #{money[5]}, #{money[6]}, #{money[7]}, ]"

	if(money[1] >= 2) #100p
		money[0] += 1
		money[1] -= 2
	elsif(money[2] >= 2) #50p
		money[1] += 1
		money[2] -= 2
	elsif(money[3] >= 2 && money[4] >= 1) #20p
		money[2] += 1
		money[3] -= 2
		money[4] -= 1
	elsif(money[4] >= 2) #10p
		money[3] += 1
		money[4] -= 2
	elsif(money[5] >= 2) #5p
		money[4] += 1
		money[5] -= 2
	elsif(money[6] >= 2 && money[7] >= 1) #2p
		money[5] += 1
		money[6] -= 2
		money[7] -= 1
	else #1p
		money[6] += 1
		money[7] -= 2
	end

	num_ways += 1 
end

puts "[#{money[0]}, #{money[1]}, #{money[2]}, #{money[3]}, #{money[4]}, #{money[5]}, #{money[6]}, #{money[7]}, ]"

puts "2 pounds can be made #{num_ways} different ways"
