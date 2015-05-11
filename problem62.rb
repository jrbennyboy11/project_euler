def get_digit_array(num)
	arr = [0,0,0,0,0,0,0,0,0,0]
	num.to_s.each_char{|c| arr[c.to_i]+=1}
	return arr
end

beginning_time = Time.now

num_times = Hash.new(0)
lowest_val = Hash.new(0)
found = false
i = 0

while(!found)
	i += 1
	currArr = get_digit_array(i**3)
	
	num_times[currArr] += 1
	
	if lowest_val[currArr] == 0
		lowest_val[currArr] = i**3
	elsif num_times[currArr] == 5
		found = true
		puts "Solution: #{lowest_val[currArr]}"
	end
end

end_time = Time.now
puts "Time elapsed #{(end_time - beginning_time)*1000} milliseconds"
