class Integer
  def num_digits
    return self.to_s.length
  end
end

p = 0 #power
i = 1
count = 0
old_count = 0
done = false

while !done
	old_count = count
	p += 1
	i = 1
	
	while (i**p).num_digits < p
		i+=1
	end
	while (i**p).num_digits == p
		#puts "#{i}^#{p} = #{i**p}"
		count += 1
		i += 1
	end
	
	if old_count == count
		done = true
	end
end

puts "There are #{count} n-digit positive integers which are also an nth power"
