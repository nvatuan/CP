program next_m;
const fi_name = 'next_m.inp'; fo_name = 'next_m.out';
	  errorMsg = 'No solution';
var fi, fo :text;
	n, i, j, L, len :longint;
	rawtext :ansistring;
	digit :array[1..100000] of longint;

procedure readfile;
	begin
		assign(fi, fi_name);
		reset(fi);
		readln(fi, rawtext);
		close(fi);
	end;
procedure writefile;
	begin
		assign(fo, fo_name);
		rewrite(fo);
		close(fo);
	end;
procedure collecc;
	var d :longint;
	begin
		i := 1;
		while ord(rawtext[i]) <> 61 do // '='
			begin
				n := n*10 + ord(rawtext[i]) - 48;
				inc(i);
			end;
		write(n);

		j:=i; L:=0; len:=length(rawtext);

		while i < len do
		begin
			d:=0; 
			while not( (47 < ord(rawtext[j])) and (ord(rawtext[j]) < 58) ) do inc(j); // while not number
			while i < j do
				begin
					d := d*10 + (ord(rawtext[i]) - 48);
					inc(i);
				end;
			inc(L);
			digit[L] := d;
			inc(i);
		end; 

		for i :=1 to L do 
			write(digit[i],' ')
	end;
BEGIN
	readfile;
	collecc;
	readln;
	for i := 1 to j do
		write(fo, digit[i]);
	writefile;
END.