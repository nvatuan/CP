#!usr/bin/env ruby

char = (0..25).map {|i| (65+i).chr}.concat((0..25).map {|i| (97+i).chr})

puts <<-HEREDOC
Testing delchar.exe...
Each test consists 2 string with length varies from (1..1500)
Every length will be tested, its content is randomized.
Program will do 5 attempts for each length combination, a test is passed if all 5 attempts are correct.
HEREDOC

c = 0
log = File.new('delchar_inc.txt','w')
(1..1500).step{ |l| 
	ct = 0
	p l
	5.times {
		fi = File.new('delchar.inp','w')
		string = ''
		(rand(l) + 1).times { string.concat(char[rand(char.size)]) }
		## ---
		st1 = string.dup
		st2 = string.dup
		margin = l - string.length
		case rand(2)
		when 0 
			w = margin - 1
			st1.insert(rand(st1.length), '1' * margin)
			string = 'No solution'
		when 1
			margin.times {
				st1.insert(rand(st1.length), '1')
				st2.insert(rand(st2.length), '2')
			}
			w = 1500
		end
		## ---
		fi.syswrite("#{w}\n"); fi.syswrite(st1 + "\n"); fi.syswrite(st2)
		fi.close
		## ---
		`delchar.exe`
		r = File.new('delchar.out','r').read
		if r == string
			ct += 1
		else
			#puts "Incorrected"
			log.syswrite("#{w}\n#{st1}\n#{st2}\n#{string}\n#{r}\n\n")
		end
	}
	c += 1 if ct == 5
}
puts "#{c}/1500 tests corrected."