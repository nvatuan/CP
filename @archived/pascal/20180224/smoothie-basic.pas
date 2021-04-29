program smoothienumb;
var i, j, s :longint;
	isntprime, smoothie :array[0..1001] of boolean;
	prime :array[0..1000] of longint;
	mul :array[0..1000] of longint;
	fo :text;
procedure eratosSieve;
	begin
		isntprime[0] := true; isntprime[1] := true;
		for i:=1 to 1001 do
			begin
				if isntprime[i] = false then
					begin
						j := i;
						repeat
							inc(j, i);
							isntprime[j] := true;
						until j>1001;
					end;
			end;
		//
		prime[0] := 0;
		for i:=1 to 1001 do
			if isntprime[i] = false then 
				begin
					inc(prime[0]);
					prime[prime[0]] := i;
				end;
	end;
begin
	eratosSieve;
	fillchar(smoothie, sizeof(smoothie), FALSE);
	//
	for i:=1 to prime[0] do
		begin
			if prime[i]>99 then mul[i] := 1000
			else if prime[i]>9 then mul[i] := 100
				 else mul[i]:=10;
		end;
	//
	for i:=1 to prime[0] do
		for j:=1 to prime[0] do
			begin 
				s:=prime[i] * mul[j] + prime[j];
				if s<1002 then smoothie[s] := true;
			end;
	//
	assign(fo, 'smoothies.txt');
	rewrite(fo);

	for i:=1 to 1001 do
		if smoothie[i] then write(fo,i,' ');
	close(fo);
	
end.