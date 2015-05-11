def min(x,y)
	if x < y
		return x.to_i
	else
		return y.to_i
	end
end
 
matrix = Array.new(80)
i = 0

matrixFile = File.open("p081_matrix.csv", "r")
	matrixFile.each_line do |line|
		matrix[i] = Array.new(80)
		temp = line.split(',')
		j = 0
		while j < 80
			matrix[i][j] = temp[j].to_s.chomp.to_i
			j += 1
		end
		i += 1
	end
matrixFile.close()

i = 79 #row
j = 79 #column

while i > 0
	i -= 1
	matrix[i][j] += matrix[i+1][j]
end
i = 79
while j > 0
	j -= 1
	matrix[i][j] += matrix[i][j+1]
end

counter = 78

while counter > 0
	i = counter
	j = counter
	matrix[i][j] += min(matrix[i+1][j],matrix[i][j+1])

	while i > 0
		i -= 1
		matrix[i][j] += min(matrix[i+1][j],matrix[i][j+1])
	end
	i = counter
	while j > 0
		j -= 1
		matrix[i][j] += min(matrix[i+1][j],matrix[i][j+1])
	end
	
	counter -= 1
end

puts "Solution: #{matrix[0][0] + min(matrix[0][1],matrix[1][0])}"
