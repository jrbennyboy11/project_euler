i = 1
sum = 0

while i<=1000 do
	sum += i**i
	i += 1
end

puts "Answer: #{sum.to_s[sum.to_s.size()-10...sum.to_s.size()]}"
