=begin

Benjamin Barnett
6/12/15
https://projecteuler.net/problem=59

=end

def sum_of_ascii_valus(message,pass)
	sum = 0
	it = -1
	pass_size = pass.length

	decrypted_message = message.map{|c| c^pass[it = (it+1)%pass_size]}

	decrypted_message.each do |c|
		sum += c
	end

	return sum
end

def decrypt_message(message, pass)
	it = -1
	pass_size = pass.length
	
	decrypted_message = message.map{|c| c^pass[it = (it+1)%pass_size]}
	decrypted_message.each do |c|
		if c < 32 || c > 122
			return false
		end
	end
	
	return decrypted_message.map{|c| c.chr}.join('')
end

cipher_text = File.read("p059_cipher.txt").split(",").map(&:to_i)
decrypted_messages = Hash.new

i = 0
while i < 26
	#puts i
	j = 0
	while j < 26
		k = 0
		while k < 26
			pass = [97+i,97+j,97+k]
			message = decrypt_message(cipher_text,pass)
			if message != false
				decrypted_messages[sum_of_ascii_valus(cipher_text,pass)] = message
			end
			k += 1
		end
		j += 1
	end
	i += 1
end

puts "There are #{decrypted_messages.length} potential messages"

decrypted_messages.each_pair do |key,val|
	if val.count("the") > 1
		puts val
		puts "Sum of ASCII Values: #{key}"
	end
end
