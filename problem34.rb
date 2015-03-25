class Integer
  def fact
    (1..self).reduce(:*) || 1
  end
end

def digit_factorial_sum(n)
  n.to_s.each_char.map {|c| c.to_i.fact }.reduce(:+)
end

i = 3
sum = 0

while i < 100000 do
	if(i == digit_factorial_sum(i))
		puts i
		sum += i
	end
	i += 1
end

puts "Sum: #{sum}"
