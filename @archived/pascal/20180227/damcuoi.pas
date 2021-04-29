program damcuoi;
const fi_name = 'DAMCUOI.INP'; fo_name = 'DAMCUOI.OUT';
var fi, fo :text;
	k, i, j, y, ans :longint;
	i1, i2, i3 :longint;
	eratos :array[1..1000] of boolean;
	prime :array[0..200] of longint;

function max(a, b :longint):longint;
	begin
		if a>b then exit(a)
		else exit(b);
	end;

procedure eratosSieve;
	var i, j :longint;
	begin
		prime[0] := 0;
		eratos[1] := true;
		for i:=2 to 1000 do
			begin
				if eratos[i] = false then
					begin
						j := i;	// sieve algo
						repeat
							inc(j, i);
							if j > 1000 then break;
							eratos[j] := true;
						until false;
						//
						inc(prime[0]);
						prime[prime[0]] := i; //add to prime array
					end;
			end;
	end;

BEGIN
	assign(fi, fi_name); reset(fi);
	read(fi, k); close(fi);
	//
	eratosSieve;
	ans := 0;
	for i:=1 to prime[0]-2 do
		for j:=i+1 to prime[0]-1 do
			for y:=j+1 to prime[0] do
				begin
					if prime[i] + prime[j] + prime[y] >= k then break;
					if ans < prime[i] + prime[j] + prime[y] then
						begin
						ans := prime[i] + prime[j] + prime[y];
						//i1:=prime[i]; i2:=prime[j]; i3:=prime[y];
						end;
				end;
	//
	assign(fo, fo_name); rewrite(fo);
	writeln(fo, ans); //write(fo, i1,' ', i2,' ', i3);
	close(fo);
END.