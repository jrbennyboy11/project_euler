threads = (0..6).map do |i|
  Thread.new(i) do |i|
	answer = 0
	blue = 0
	red = 0
	total = 1000000000000.0
	i.times{total *= 5}
	endpoint = total*5

	while answer == 0 && total < endpoint
		total += 1
		blue = (total*0.5).ceil

		chance = (blue/total)*(blue-1/total-1)
		while chance < 0.5
			blue += 1
			chance = (blue/total)*(blue-1/total-1)
		end
		if chance == 0.5
			answer = blue 
		end
	end
	if answer > 0
		puts "Answer: #{answer}"
	end
  end
end
threads.each {|t| t.join}
