#!usr/bin/env ruby

## Binary.pas test checker

p "Group test 1: Custom range (1..10e8)"
p "------------------------------------"

def try(i)
	fi = File.new('binary.inp','w+') 
	IO.write(fi, i.to_s(2))
	fi.close
	`binary.exe`
	return File.new('binary.out','r').read == (i * 17).to_s(2)
end

cases = 1000
correct = 0

p "Group test 1: Custom range (1 -> #{cases})"
cases.times { |i|
	correct += 1 if try(i)
}

p "Result: #{correct}/#{cases}"
p "Group test 2: Random tests vary from (1000001..2**1000)"

cases = 1000
correct = 0
log = File.new('incorrect.txt','w+')
cases.times {
	r = rand(1000001..2**1000)
	correct += 1 if try(r)
	log.syswrite("#{r.to_s(2)}\n")
}

p "Result: #{correct}/#{cases}"
gets
gets