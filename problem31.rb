a = 200 #200
b = 0 #100
c = 0 #50
d = 0 #20
e = 0 #10
f = 0 #5
g = 0 #2

count = 0

while a >= 0
	b = a
	a -= 200
	while b >= 0
		c = b
		b -= 100
		while c >= 0
			d = c
			c -= 50
			while d >= 0
				e = d
				d -= 20
				while e >= 0
					f = e
					e -= 10
					while f >= 0
						g = f
						f -= 5
						while g >= 0
							g -= 2
							count += 1
						end
					end
				end
			end
		end
	end
end

puts "Solution: #{count}"
