program PALINN;
uses math;
const fi_name = 'PALINN.INP'; fo_name = 'PALINN.OUT';
var fi, fo :text;
	//bnum :array[0..40] of char; //
	num, ceil :int64;
	i, j, m, n, k :longint;	
//--
	ans :longint; 
	nans :int64;

procedure readfile;
	begin
		assign(fi, fi_name);
		reset(fi);
		readln(fi, n, m);
		read(fi, k);
		close(fi);
	end;
procedure writefile;
	begin
		assign(fo, fo_name);
		rewrite(fo);
		writeln(fo, ans);
		writeln(fo, nans);
		close(fo);
	end;
procedure floordown;
	var times :longint;
	begin
		times := floor(log10(m) * n); // m ** times should has around n-digits
		// Checking...
		num := m ** times;
		{
		repeat
			if floor(log10(num * m)) < n then 
				begin num := num * m; continue; end;
			if floor(log10(num div m)) >= n then
				begin num := num div m; continue; end;
			break;
		until false;
		}
		// the number is thy lowest
			ceil := 10**(n-1);
			repeat
				if num + m < ceil then 
					begin num := num + m; continue; end;
				if num - m >= ceil then
					begin num := num - m; continue; end;
				break;
			until false;
			num := num + m;
		// hope so.
	end;

function palind():boolean;
	var st :string;
		len :longint;
	begin
		str(num, st);
		len := length(st);

		i := 1;
		while i < len do
			begin
				if st[i]<>st[len] then exit(false);
				inc(i); dec(len);
			end;
		exit(true);
	end;

BEGIN
	readfile;
	if m = 0 then halt;
	//
	floordown; //#=> num
	ceil := 10**n-1;
	while num <= ceil do
		begin 
			if palind() then 
				begin 
					inc(ans); 
					if k > 1 then dec(k);
					if k = 1 then nans:= num;
				end;
			num := num + m;
		end;
	//
	writefile;
END.