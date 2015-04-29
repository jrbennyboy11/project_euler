threads = (0..4).map do |i|
  Thread.new(i) do |i|
	answer = 0
	t = 1000000000000.0	
	i.times{t += 1000000000000.0}
	endpoint = t+1000000000000.0

	while answer == 0 #1000000000000.0	
		t += 1
		b = 0.7*t
		temp = t*(t-1)
	
		while 2*b*(b-1) < temp
			b += 1
		end
		if 2*b*(b-1) == temp
			answer = b
		end
	end

	if answer > 0
		puts "Number of blue discs: #{answer}"
	else
		puts "Answer is not between #{t} & #{endpoint}"
  	end
end
threads.each {|t| t.join}

#2b*(b-1) = t*(t-1)
