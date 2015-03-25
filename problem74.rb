class Integer
  def fact
    (1..self).reduce(:*) || 1
  end
end

def digit_factorial_sum(n)
  n.to_s.each_char.map {|c| c.to_i.fact }.reduce(:+)
end

i = 2
total = 0

while i<1000000 do
	chainPiece = i
	chain = Hash.new
	chain[i] = true
	
	repeat = false
	
	while !repeat && chain.size()<=60 do
		chainPiece = digit_factorial_sum(chainPiece)
		
		if(chain[chainPiece])
			repeat = true
		else
			chain[chainPiece] = true
		end
	end 
	
	if(chain.size() == 60)
		total += 1
	end
	
	i += 1
end 

puts "Chains under a million containing exactly 60 non-repeating terms: #{total}"
