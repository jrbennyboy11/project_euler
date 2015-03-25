distinct_terms = Hash.new
i = 2
total = 0

while i<= 100 do
	j = 2
	while j<= 100 do
		distinct_terms[i**j] = 1
		j += 1
	end
	i += 1
end

puts "Total distinct terms: #{distinct_terms.size()}"
