biggest_line = 0
current_line = 0
biggest_number = 0
current_number = 0

p099_file = File.new("p099_base_exp.txt", "r")
	p099_file.each_line do |line|
		temp = line.split(',')

		current_number = (temp[0].to_i)**(temp[1].to_i)
		if current_number > biggest_number
			biggest_line = current_line
			biggest_number = current_number
			puts "Line #{current_line} has the new biggst number"
		end

		current_number += 1
	end
p099_file.close()

puts "Line #{biggest_line} has the largest number"
