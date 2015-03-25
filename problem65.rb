def digit_sum(n)
  n.to_s.each_char.map {|c| c.to_i }.reduce(:+)
end

i = 2
d = 1
n = 2

while i <= 100 do

	temp = d
	c = (i%3==0)?2*(i/3):1
	d = n
	n = c*d+temp
	i += 1

end

puts digit_sum(n)
