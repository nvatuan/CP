program delchar;
const fi_name = 'delchar.inp'; fo_name = 'delchar.out';
type tk65_legacy = record //algorithm stolen from tk65
		val, direction :longint;
	end;
var fi, fo :text;
	i, j, w :longint;
	s1, s2 :ansistring;
	//-- Methods variable
	len1, len2, len_a :longint;
	L :array[0..1500, 0..1500] of tk65_legacy;
	ans :array[1..1500] of char;

procedure readfile;
	begin
		assign(fi, fi_name);
		reset(fi);
		readln(fi, w);
		readln(fi, s1);
		readln(fi, s2);
		close(fi);
	end;

procedure writefile_n; // Do this when things go wrong
	begin
		assign(fo, fo_name);
		rewrite(fo);
		write(fo, 'No solution');
		close(fo);
		halt;
	end;

procedure markUp(); // DP, map out. 
	begin
		len1 := length(s1); len2 := length(s2); 
		for i := 1 to len1 do
			L[i][0].direction := 3;
		for j := 1 to len2 do
			L[0][j].direction := 2;
		//
		for i := 1 to len1 do
			for j := 1 to len2 do
				begin
					if s1[i] = s2[j] then
						begin 
							L[i][j].val := L[i-1][j-1].val + 1;
							L[i][j].direction := 1;
						end
					else if L[i-1][j].val > L[i][j-1].val then
						begin 
							L[i][j].val := L[i-1][j].val;
						    L[i][j].direction := 3;
						end 
					else 
						begin 
							L[i][j].val := L[i][j-1].val;
							L[i][j].direction := 2;
						end;
				end;
	end;

function trace():boolean; // Rollbacc log to extract answer, also's tk65 legacy
	var wi, wj :longint;
	begin
		i:=len1; j:=len2; len_a := 0;
		wi := 0; wj := 0;
		while (i + j <> 0) do //check if either of them is zero
			begin
				if (wi > w) or (wj > w) then exit(false);
				case L[i][j].direction of // Legacy
				1:	begin // Diagonal
						inc(len_a); ans[len_a] := s1[i]; 
						dec(i); dec(j);
						wi := 0; wj := 0;
				  	end;
				2:  begin // Horizontal
						dec(j);
						inc(wj);
					end;
				3:  begin // Vertical
						dec(i);
						inc(wi);
					end;
				end;
			end;
		if (wi > w) or (wj > w) then exit(false); //clunky
		exit(true);
	end;

procedure writefile;
	begin
		assign(fo, fo_name);
		rewrite(fo);
		for i := len_a downto 1 do write(fo, ans[i]);
		close(fo);
	end;

BEGIN
	readfile;
	markUp;
	if not(trace) then writefile_n;
	if len_a = 0 then writefile_n;
	writefile;
END.