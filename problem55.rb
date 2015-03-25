def revAdd(n) 
    return n + n.to_s.reverse.to_i
end
def is_palindrome(n)
	return n.to_s.reverse == n.to_s
end

i = 1
lychrel = 9999

while i < 10000 do
	found = false
	temp = i
	
	j = 0
	while j < 50 && !found do
		temp = revAdd(temp)
		if(is_palindrome(temp))
			#puts "#{i} is Palindromic after #{j+1} itterations"
			lychrel -= 1
			found = true
		end
		j += 1
	end
	
	i += 1
end

puts "Lychrel Numbers Below 10,000: #{lychrel}"
