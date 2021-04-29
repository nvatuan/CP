#!usr/bin/env ruby

## Binary.pas test checker

def try(i)
	fi = File.new('binary.inp','w+') 
	IO.write(fi, i.to_s(2))
	fi.close
	`binary.exe`
	return File.new('binary.out','r').read == (i * 17).to_s(2)
end


cases = 100000
correct = 0
log = File.new('incorrect.txt','w+')

=begin
p "Group test 1: Custom range (1 -> #{cases})"
#cases.times { |i|
(1..cases).step { |i|
	condition = try(i)
	p i
	correct += 1 if condition
	log.syswrite("#{i.to_s(2)}\n") unless condition
	puts i unless condition
}
=end

#p "Result: #{correct}/#{cases}"
p "Group test 2: Random tests vary from (1000001..2**1000)"

cases = 1000
correct = 0
cases.times {
	r = rand(1000001..2**1000)

	condition = try(r)
	correct += 1 if condition
	log.syswrite("#{r.to_s(2)}\n") unless condition
}

p "Result: #{correct}/#{cases}"
gets