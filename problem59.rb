# Benjamin Barnett
# 6/12/15
# https://projecteuler.net/problem=59

#message is an array of numbers, each representing an ASCII value
#returns the sum of all the ASCII values in message
def sum_of_ascii_values(message)
	return message.map{|c| c.to_i}.reduce(:+)
end

#message is an array of numbers, each representing an ASCII value
#returns whether or not the ASCII values in message fall within the range of normal text characters
def is_valid_text(message)
	return message.min >= 32 && message.max <= 122
end

#message is an array of numbers, each representing an ASCII value
#returns string version of message with ASCII values as characters
def message_to_string(message)
	return message.map{|c| c.chr}.join('')
end

#message is an array of numbers, each representing an encrypted ASCII value
#pass is an array of numbers, each representing an ASCII value, that will be cycled through and used as the decryption XOR for the encrypted values in message
#returns an array of numbers, each representing an unencrypted ASCII value
def decrypt_message(message, pass)
	it = -1
	return message.map{|c| c^pass[it = (it+1)%pass.length]}
end

#messages is a hash table of decrypted messages as strings
#returns the key of the message containing the most "the"s and "and"s
def most_thes_ands(messages)
	most = 0
	most_key = 0

	messages.each_pair do |key,val|
		count = val.count(" the ") + val.count(" and ")
		if count > most
			most = count
			most_key = key
		end
	end

	return most_key
end

cipher_text = File.read("p059_cipher.txt").split(",").map(&:to_i)
decrypted_messages = Hash.new

26.times do |i|
	26.times do |j|
		26.times do |k|
			pass = [97+i,97+j,97+k]
			message = decrypt_message(cipher_text,pass)
			if is_valid_text(message)
				decrypted_messages[sum_of_ascii_values(message)] = message_to_string(message)
			end
		end
	end
end

real_message_key = most_thes_ands(decrypted_messages)

puts "\nDecrypted Message: \n\n*------------------*"
puts "#{decrypted_messages[real_message_key]}\n*------------------*\n\n"
puts "Sum of ASCII Values: #{real_message_key}\n\n"
