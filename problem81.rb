def min(x,y)
	if x == -1
		return y
	elsif y == -1
		return x
	elsif x > y
		return y
	else
		return x
	end
end

#$i = 0

$min_grid = Hash.new
80.times do |i|
	80.times do |j|
		$min_grid[[i,j]] = -1
	end
end

def min_path_sum(matrix, row, column, sum)
	sum += matrix[row,column].to_s.to_i
	
	#$i += 1
	#if $i%100000 == 0
	#	puts "i: #{$i}"
	#end

	minVal = $min_grid.fetch(row,column)
	if minVal != -1 && minVal < sum
		return -1
	else
		$min_grid[[row,column]] = sum
	end

	if row == 79 || column == 79
		79-row.times do |i|
			sum += matrix[row+i,column].to_s.to_i
		end
		79-column.times do |i|
			sum += matrix[row,column+i].to_s.to_i
		end
		return sum
	else
		return min(min_path_sum(matrix, row+1, column, sum) , min_path_sum(matrix, row, column+1, sum))
	end
end

matrix = Array.new(80) { Array.new(80) }
i = 0
j = 0
 
matrixFile = File.open("p081_matrix.csv", "r")
numbers = matrixFile.read
matrixFile.close()
numbersArr = numbers.split(',')

numbersArr.each{|x|
	matrix[i,j] = x
	j = (j+1)%80
	if j==79 then i += 1 end
}

puts "min path sum: #{min_path_sum(matrix,0,0,0)}"
