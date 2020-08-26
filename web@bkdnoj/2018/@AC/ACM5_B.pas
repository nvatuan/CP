program ACM5_B;
type	properties = record
			w :integer;
			v :integer;
		end;
var n, W, i, j :integer;
	props :array[0..100] of properties;
	DP :array[0..100][0..1000] of properties;

BEGIN
	readln(n, W);
	for i:=1 to n do
		begin readln(props[i].w, props[i].v); end;
	//
	//no optimized
	//
	for i:=1 to 1000 do
		for j:=1 to n do
			begin
				
			end;
END.