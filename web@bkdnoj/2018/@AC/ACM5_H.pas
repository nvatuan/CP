program ACM5_H;
var n, k :longint;

procedure generate(len, knary :longint);
	var i :longint;
	begin
		if len = 0 then writeln(knary)
		else for i:=1 to k do generate(len - 1, knary*10 + i);
	end;
function exp(t :longint):longint;
	begin
		if t = 1 then exit(k);
		exit(exp(t-1)*k);
	end;

begin
	readln(k, n);
	writeln(exp(n));
	generate(n, 0);
end.