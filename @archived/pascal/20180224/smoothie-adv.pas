program mixedsmoothie;
var i, j, s, n :longint;
	isntprime :array[0..10000] of boolean;
	prime :array[0..10000] of longint;
	mul :array[0..10000] of longint;
	smoothie :array[0..10000] of boolean;
	fi, fo :text;
procedure eratosSieve;
	begin
		isntprime[0] := true; isntprime[1] := true;
		for i:=1 to 10000 do
			begin
				if isntprime[i] = false then
					begin
						j := i;
						repeat
							inc(j, i);
							isntprime[j] := true;
						until j>10000;
					end;
			end;
		//
		prime[0] := 0;
		for i:=1 to 10000 do
			if isntprime[i] = false then 
				begin
					inc(prime[0]);
					prime[prime[0]] := i;
				end;
		//generating 10-multiplication
		for i:=1 to prime[0] do
			begin
				s := prime[i];
				mul[i] := 1;
				while s>0 do
					begin
						s:=s div 10;
						mul[i]:=mul[i]*10;
					end;
			end;
	end;

procedure smoothieGen(ss:longint);
	var j :longint;
	begin
		if ss>10000 then exit;
		smoothie[ss] := true;
		for j:=1 to prime[0] do
			smoothieGen(ss*mul[j] + prime[j]);
	end;
begin
	assign(fi, 'MIXEDSMOOTHIE.INP'); reset(fi);
	assign(fo, 'MIXEDSMOOTHIE.OUT'); rewrite(fo);
	//---------------------------------------------
	readln(fi, n); close(fi);
	//
	//fillchar(mul, sizeof(mul), 1);
	eratosSieve;

	for i:=1 to prime[0] do
		for j:=1 to prime[0] do
			begin
				smoothieGen(prime[i]*mul[j] + prime[j]);
			end;
	//
	s := 0;
	for i:=1 to n-1 do if smoothie[i] then inc(s);
	write(fo, s);
	close(fo); 
end.
