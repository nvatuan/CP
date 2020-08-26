program E;
var n, i, j :longint;
	ans :int64;


	a, s :array[0..1000] of int64;

function max(a, b :int64):int64;
	begin
		if(a > b) then exit(a);
		exit(b);
	end;

BEGIN
	readln(n);
	s[0] := 0;
	ans := 0;

	for i:=1 to n do
		begin
			readln(a[i]);
			s[i] := s[i-1] + a[i];
		end;

	

	for i:=1 to n-2 do
		for j:=i+1 to n-1 do
			begin
				if (j = i + 1) then ans := max(ans, s[i-1] + a[i]*a[i+1]*a[i+2] + s[n] - s[i+2] )
				else ans := max(ans, s[i-1] + a[i]*a[i+1] + s[j-1] - s[i+1] + a[j]*a[j+1] + s[n]-s[j+1]);
			end;

	writeln(ans);
END.