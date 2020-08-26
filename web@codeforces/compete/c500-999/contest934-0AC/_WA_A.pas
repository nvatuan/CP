program	a_compatible_pair;
var max, maxindexa, prevmax, i, j, m, n, k :longint;
	a, b :array[1..50] of longint;

begin
	readln(n, m);
	for i:= 1 to n do read(a[i]);
	for i:= 1 to m do read(b[i]);
	//
	max := a[1] * b[1];
	maxindexa := 1;
//	prevmax := a[2] * b[1];
//	if prevmax > max then begin k:=prevmax; prevmax:=max; max:=k; end;

	for i:=1 to n do
		for j:=1 to m do
			if a[i]*b[j] > max then 
				begin
					max := a[i]*b[j]; 
					maxindexa := i;
				end;
			
	for i:= 1 to n do 
		if i <> maxindexa then max := a[i] * b[1];

	for i:= 1 to n do
		for j:= 1 to m do
			if i <> maxindexa then
				if a[i] * b[j] > max then max := a[i] * b[j];

	writeln(max);
end.