program DivideByThree;
var i, n :longint;
	s :ansistring;
	d :array[1..100000] of byte;
begin
	readln(s);
	n := length(s);
	for i:=1 to n do d[i] := s[i];
	
end.