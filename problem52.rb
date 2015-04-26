class Fixnum
  def num_digits
    Math.log10(self).to_i + 1
  end
end

def digits_in(num)
	numCpy = num
	digits = [false, false, false, false, false, false, false, false, false, false]

	while numCpy >= 10
		digits[numCpy%10] = true
		numCpy /= 10
	end
	digits[numCpy] = true

	return digits
end

answer = 0
i = 0

while answer == 0
	i += 1

	times2 = i*2
	if times2.num_digits == i.num_digits
		times3 = i*3
		if times3.num_digits == i.num_digits
			times4 = i*4
			if times4.num_digits == i.num_digits
				times5 = i*5
				if times5.num_digits == i.num_digits	
					times6 = i*6
					if times6.num_digits == i.num_digits
						if digits_in(i) == digits_in(times2)
							if digits_in(times2) == digits_in(times3)
								if digits_in(times3) == digits_in(times4)
									if digits_in(times4) == digits_in(times5)
										if digits_in(times5) == digits_in(times6)
											answer = i
										end
									end
								end
							end
						end
					end
				end
			end
		end
	end
end

puts "Answer: #{answer}"
