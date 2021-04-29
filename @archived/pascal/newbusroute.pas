program NewBusRoute;
var fi, fo :text;
	i, n, quant :longint;
	ans :int64;
	a :array[1..200000] of longint;

procedure qsort(l, r :longint);
	var x, y, i, j :longint;
	begin
		i := l;
		j := r;
		x := a[(l+r) div 2];
		repeat
			while a[i] < x do
				inc(i);
			while x < a[j] do 
				dec(j);
			if not(i>j) then
				begin
					y := a[i];
					a[i] := a[j];
					a[j] := y;
					inc(i);
					dec(j);
				end;
		until i>j;
		if l<j then qsort(l,j);
		if i<r then qsort(i,r);
	end;

BEGIN
	readln(n);
	for i:=1 to n do read(a[i]);
	qsort(1, n);
	ans := round(10e9)*2;
	for i:=n downto 2 do
		if(a[i]-a[i-1] < ans) then
			begin
				ans := a[i]-a[i-1];
				quant := 1;
			end
		else if(ans = a[i]-a[i-1]) then inc(quant);
	write(ans,' ',quant);
END.