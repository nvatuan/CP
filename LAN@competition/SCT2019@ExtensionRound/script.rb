workingdir = "S:/NF"
Dir.mkdir("#{workingdir}/testcases") unless File.exist?("./testcases")
Dir.chdir("#{workingdir}/testcases")

no = 0

while File.exist?("./testcases/in#{no}"){
	
}