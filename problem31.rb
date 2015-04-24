def count_ways(arr)
	#arrCopy = [arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7]]
	
	if arr[0] > 0 #200p
		sum = 0
	
		arrCopy = [arr[0]-1,arr[1]+2,arr[2],arr[3],arr[4],arr[5],arr[6],arr[7]] #200p into 2 100p
		sum += count_ways(arrCopy)
		arrCopy = [arr[0]-1,arr[1],arr[2]+4,arr[3],arr[4],arr[5],arr[6],arr[7]] #200p into 4 50p
		sum += count_ways(arrCopy)
		arrCopy = [arr[0]-1,arr[1],arr[2],arr[3]+10,arr[4],arr[5],arr[6],arr[7]] #200p into 10 20p
		sum += count_ways(arrCopy)
		arrCopy = [arr[0]-1,arr[1],arr[2],arr[3],arr[4]+20,arr[5],arr[6],arr[7]] #200p into 20 10p
		sum += count_ways(arrCopy)
		arrCopy = [arr[0]-1,arr[1],arr[2],arr[3],arr[4],arr[5]+40,arr[6],arr[7]] #200p into 40 5p
		sum += count_ways(arrCopy)
		arrCopy = [arr[0]-1,arr[1],arr[2],arr[3],arr[4],arr[5],arr[6]+100,arr[7]] #200p into 100 2p
		sum += count_ways(arrCopy)
		arrCopy = [arr[0]-1,arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7]+200] #200p into 200 1p
		sum += count_ways(arrCopy)
		
		return sum + 8
	elsif arr[1] > 0 #100p
		sum = 0
	
		arrCopy = [arr[0],arr[1]-1,arr[2]+2,arr[3],arr[4],arr[5],arr[6],arr[7]]
		sum += count_ways(arrCopy)
		arrCopy = [arr[0],arr[1]-1,arr[2],arr[3]+5,arr[4],arr[5],arr[6],arr[7]]
		sum += count_ways(arrCopy)
		arrCopy = [arr[0],arr[1]-1,arr[2],arr[3],arr[4]+10,arr[5],arr[6],arr[7]]
		sum += count_ways(arrCopy)
		arrCopy = [arr[0],arr[1]-1,arr[2],arr[3],arr[4],arr[5]+20,arr[6],arr[7]]
		sum += count_ways(arrCopy)
		arrCopy = [arr[0],arr[1]-1,arr[2],arr[3],arr[4],arr[5],arr[6]+50,arr[7]]
		sum += count_ways(arrCopy)
		arrCopy = [arr[0],arr[1]-1,arr[2],arr[3],arr[4],arr[5],arr[6],arr[7]+100]
		sum += count_ways(arrCopy)
		
		return sum + 7
	elsif arr[2] > 0 #50p
		sum = 0
		
		arrCopy = [arr[0],arr[1],arr[2]-1,arr[3]+2,arr[4]+1,arr[5],arr[6],arr[7]]
		sum += count_ways(arrCopy)
		arrCopy = [arr[0],arr[1],arr[2]-1,arr[3],arr[4]+5,arr[5],arr[6],arr[7]]
		sum += count_ways(arrCopy)
		arrCopy = [arr[0],arr[1],arr[2]-1,arr[3],arr[4],arr[5]+10,arr[6],arr[7]]
		sum += count_ways(arrCopy)
		arrCopy = [arr[0],arr[1],arr[2]-1,arr[3],arr[4],arr[5],arr[6]+25,arr[7]]
		sum += count_ways(arrCopy)
		arrCopy = [arr[0],arr[1],arr[2]-1,arr[3],arr[4],arr[5],arr[6],arr[7]+50]
		sum += count_ways(arrCopy)
		
		return sum + 6
	elsif arr[3] > 0 #20p
		sum = 0
		
		arrCopy = [arr[0],arr[1],arr[2],arr[3]-1,arr[4]+2,arr[5],arr[6],arr[7]]
		sum += count_ways(arrCopy)
		arrCopy = [arr[0],arr[1],arr[2],arr[3]-1,arr[4],arr[5]+4,arr[6],arr[7]]
		sum += count_ways(arrCopy)
		arrCopy = [arr[0],arr[1],arr[2],arr[3]-1,arr[4],arr[5],arr[6]+10,arr[7]]
		sum += count_ways(arrCopy)
		arrCopy = [arr[0],arr[1],arr[2],arr[3]-1,arr[4],arr[5],arr[6],arr[7]+20]
		sum += count_ways(arrCopy)
		
		return sum + 5
	elsif arr[4] > 0 #10p
		sum = 0
		
		arrCopy = [arr[0],arr[1],arr[2],arr[3],arr[4]-1,arr[5]+2,arr[6],arr[7]]
		sum += count_ways(arrCopy)
		arrCopy = [arr[0],arr[1],arr[2],arr[3],arr[4]-1,arr[5],arr[6]+5,arr[7]]
		sum += count_ways(arrCopy)
		arrCopy = [arr[0],arr[1],arr[2],arr[3],arr[4]-1,arr[5],arr[6],arr[7]+10]
		sum += count_ways(arrCopy)
		
		return sum + 4
	elsif arr[5] > 0 #5p
		sum = 0
		
		arrCopy = [arr[0],arr[1],arr[2],arr[3],arr[4],arr[5]-1,arr[6]+2,arr[7]+1]
		sum += count_ways(arrCopy)
		arrCopy = [arr[0],arr[1],arr[2],arr[3],arr[4],arr[5]-1,arr[6],arr[7]+5]
		sum += count_ways(arrCopy)
		
		return sum + 3
	elsif arr[6] > 0 #2p
		arrCopy = [arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6]-1,arr[7]+2]
		
		return count_ways(arrCopy) + 2
	else #1p
		return 1
	end
end

money = [1,0,0,0,0,0,0,0] #200p, 100p, 50p, 20p, 10p, 5p, 2p, 1p
puts "2 pounds can be made #{count_ways(money,0)} ways"

=begin
	200
		1 x 200
		2 x 100
		4 x 50
		10 x 20
		20 x 10
		40 x 5
		100 x 2
		200 x 1
=end
