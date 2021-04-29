program cf814_A;
var n, k, x :byte;
	a, b, a_ind :array[0..200] of byte;
	i, j :longint;
procedure b_sort;
	begin
		for i:=1 to k-1 do
			for j:=i+1 to k do
				if(b[i]>b[j]) then
					begin x:=b[i]; b[i]:=b[j]; b[j]:=x; end;
	end;
function a_increase():boolean;
	begin
		for i:=1 to n do
			if a[i] <> 0 then
				begin
					x:=a[i];
					break;
				end;
		for j:=i+1 to n do
			if (a[j] <> 0) then
				begin
					if (x < a[j]) then x := a[j]
					else exit(false);
				end;
		exit(true);
	end;
procedure able;
	begin
		write('Yes');
		halt;
	end;
BEGIN
	read(n, k);
	for i:=1 to n do
		begin
			read(a[i]);
			if a[i] = 0 then inc(x)
			else
				begin
					a_ind[i-x] := x;
					x := 0;
				end;
		end;

	for i:=1 to k do read(b[i]);
	//--
	if (a_increase) = false then able;
	//--
	a[0] := 0; i := 0; j := 1;
	b_sort;
	while i < n do
		begin
			inc(i);
			if a[i] = 0 then
				begin
					if (a[i-1] > b[j]) or (b[j + a_ind[i]] > a[i + a_ind[i]]) then able;
					inc(j, a_ind[i]);
					inc(i, a_ind[i]-1);
				end;
		end;
	//-- ELSE
	write('No');
END.
