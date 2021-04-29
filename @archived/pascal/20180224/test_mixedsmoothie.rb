#!usr/bin/env ruby

Dir.chdir("./mixedsmoothie/")

Dir.entries('.').collect{|f| f if f[-4..-1]==".exe"}.compact.each{ |f|
	bad = 0
	badans = ""
	subans = ""
	answer = ""
	50.times do
		i = rand(10000)

		File.open("../MIXEDSMOOTHIE.INP", 'w') {|f| f.write(i) }
		File.open("MIXEDSMOOTHIE.INP", 'w') {|f| f.write(i) }

		system("../smoothie-adv.exe")
		File.open("../MIXEDSMOOTHIE.OUT", 'r') {|f| answer = f.read}
		##
		system("#{f}")
		File.open("MIXEDSMOOTHIE.OUT", 'r') {|f| subans = f.read}
		if subans != answer
			badans << i.to_s << "\n"
			bad += 1
		end
	end
	File.write("badans_#{f}.txt", badans)
	print "[#{f}] scores: #{50 - bad}/50"
}