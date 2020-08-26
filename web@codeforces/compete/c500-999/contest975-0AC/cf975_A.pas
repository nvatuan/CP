program cf975_A;
var n, i, j, objects :longint;
	st :string;
	obj :array[1..26] of boolean;
begin
	readln(n);
	for i:=1 to n do
		begin
			readln(st);
			for j:=1 to length(st) do
				begin
					//if obj[ord(st[j]) - 96] = false then inc(objects); //dont count different letters
					//im lazy
					//
					obj[ord(st[j]) - 96] := true;
				end;
		end;
	//
	writeln(objects);
	//TEST FAILED: a abc ab
	//should be 3, but output is 2
end.