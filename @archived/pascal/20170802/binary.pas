program binary;
const fi_name = 'binary.inp'; fo_name = 'binary.out';
var fi, fo :text;
	binstr :array[1..1000] of boolean;
	answer :array[0..1004] of boolean;
	i, len :longint;

procedure readfile;
	var bstr :ansistring;
	begin
		// Storing an array of boolean so the processing should be easier
		assign(fi, fi_name);
		reset(fi);
		//fillchar(binstr, sizeof(binstr), '0')
		readln(fi, bstr);
		len := length(bstr);
		for i:=1 to len do
			binstr[1000 - len + i] := bstr[i] = '1';
		close(fi);
	end;

procedure addDupBinstr();
	var borrow :boolean;
	begin
		borrow := false;
		for i:=1 to 1000 do answer[i] := binstr[i];
		for i:=1004 downto 5 do
			begin //boolean adding
				if borrow = true then
					if answer[i] = true then 
						begin
							answer[i] := false;
							borrow := true;
						end
					else 
						begin
							answer[i] := true;
							borrow := false;
						end;
				if binstr[i-4] and answer[i] then
					begin
						answer[i] := false;
						borrow := true;
					end
				else if binstr[i-4] or answer[i] then answer[i] := true;
			end;

		while borrow do //check borrow
			begin
				dec(i);
				if borrow = true then
					if answer[i] = true then 
						begin
							answer[i] := false;
							borrow := true;
						end
					else 
						begin
							answer[i] := true;
							borrow := false;
						end;
			end;
	end;

procedure writefile;
	begin
		assign(fo, fo_name);
		rewrite(fo);
		for i:=0 to 1004 do
			if answer[i] = true then break;
		for i:=i to 1004 do
			if answer[i] then write(fo,'1')
			else write(fo,'0');
		close(fo)
	end;

BEGIN
	readfile;
	addDupBinstr;
	writefile;
END.