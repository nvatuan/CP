program Binary;
const fi_name = 'long_input.txt'; fo_name = 'compare.txt';
var fi, fo :text;
	t, i, len :longint;
	output, result :ansistring;

function compare(out, res):boolean;
	var i, len :longint;
	begin
		if length(out) <> length(res) then exit(false); 
		// Test automatically fails if there is different in length of output and res
		len := length(out);
		for i:=1 to len do
			if out[i] <> res[i] then exit(false);
		// Different characters => Test fails
		exit(true);
	end;

BEGIN
	assign(fi, fi_name); reset(fi); //This file contains tests
	assign(fo, fo_name); reset(fo); //This file contains result of the corresponding test
	readln(fi, t); // Read the amount of tests, (currently 1000 tests)
	for i:=1 to t do


END.