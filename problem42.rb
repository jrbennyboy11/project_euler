triangle_numbers = []
word_vals = []
max = 0
i = 1
triangle_words = 0
temp = 0

words = File.new("p042_words.txt", "r")
line = words.gets.to_s.gsub("\"","").split(",")
words.close

line.each do |word|
	val = word.each_char.map {|c| c.capitalize.ord-64 }.reduce(:+)
	tempArray = [val]
	word_vals += tempArray
	
	if(val > max)
		max = val
	end
end

while temp<max do
	temp = (i*(i+1))/2
	tempArray = [temp]
	triangle_numbers += tempArray
	i+=1
end

word_vals.each{|wv| if triangle_numbers.index(wv) != nil then triangle_words+=1 end}

puts "File contains #{triangle_words} triangle words"
