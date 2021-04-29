#!urs/bin/env ruby

text = File.new('./smoothies.txt','r').readline
testd = []

i, j = 1, 0
eratos = Array.new(1000, FALSE)
eratos[1] = true
eratos[0] = true

while i < 1000
	i+=1
	if(!eratos[i])
		j=i
		loop do
			j+=i
			break if j>1000
			eratos[j] = true
		end
	end
end

text.split(" ").each{|si|
	(si.length-1).times do |l|
		n1 = si[0..l].to_i
		n2 = si[l+1..si.length].to_i
		if !eratos[n1] && !eratos[n2]
			testd.push(si)
			break
		end
	end
}

text.split(" ").each {|si|
	$ga = false
	testd.each { |sj|
		if si.to_i == sj.to_i
			$ga = true
			break
		end
	}	
	#print "#{si} " unless $ga
}

text.split(" ").each {|si|
	print "#{si} " unless testd.include? si
}