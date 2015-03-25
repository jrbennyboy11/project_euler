def is_palindrome(n)
	return n.to_s.reverse == n.to_s
end

i = 1
sum = 0

while i<1000000 do
	if(is_palindrome(i))
		if(is_palindrome(i.to_s(2)))
			sum += i
		end
	end
	i += 1
end

puts "Sum: #{sum}"
