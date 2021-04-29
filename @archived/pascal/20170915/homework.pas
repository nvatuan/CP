program homework;
const fi_name = 'homework.inp'; fo_name = 'homework.out';
var fi, fo :text;
	i, m, n, x1, x2 :longint;
	Time, Req :array[1..100] of longint;
	totalTime, leave :longint;
procedure readfile;
	begin
		assign(fi, fi_name);
		reset(fi);
		readln(fi, n, m);
		for i:=1 to n do
			begin
				read(fi, Time[i]);
				inc(totalTime, Time[i]);
			end;
		readln(fi);

		for i:=1 to m do
			begin   
				readln(fi, x1, x2);
				inc(Req[x1]);
			end;

		close(fi);
	end;
procedure writefile;
	begin
		assign(fo, fo_name);
		rewrite(fo);
		write(fo, totalTime - leave);
		close(fo);
	end;
function min(a, b :longint):longint;
	begin
		if a > b then exit(b)
		else exit(a)
	end;

BEGIN
	readfile;
	leave := 1001;

	for i:=1 to n do
		if Req[i] = 0 then
			leave := min(leave, Time[i]);

	writefile;
END.