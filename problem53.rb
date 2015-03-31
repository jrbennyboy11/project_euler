class Integer
  def fact
    (1..self).reduce(:*) || 1
  end
end

i = 1
overMil = 0

while i<=100 do
	j = 1
	while j<=i do
		if i.fact/(j.fact*(i-j).fact)>1000000
			overMil += 1
		end
		j+=1
	end
	i+=1
end

puts "Values over a million: #{overMil}"
