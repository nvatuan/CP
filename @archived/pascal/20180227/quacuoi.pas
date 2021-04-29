program quacuoi;
//uses math; //math.pp increase runtime by ~6.4 seconds..
type bignum = array[0..100] of longint;
const fi_name = 'QUACUOI.INP'; fo_name = 'QUACUOI.OUT';
	  SIZE = 5; //digits of one bignum's cell, outside [0..9] range will raise exception
var fi, fo :text;
	i, n :longint;
	bigstring :string;
	sum, holder :bignum;

function max(a, b :longint):longint;
	begin
		if a>b then exit(a);
		exit(b);
	end;

function power(base, exp :longint):longint; 
	begin
		if exp = 0 then exit(1);
		if exp = 1 then exit(base);
		if exp mod 2 = 0 then exit(power(base*base, exp div 2))
		else exit(power(base*base, exp div 2)*base);
	end;

procedure where_the_zeroes;
	var zeeroea :longint;
	begin
		//02bestgril
		write(fo, sum[100 - sum[0] + 1]);
		for i:=sum[0]-1 downto 1 do
			begin
				zeeroea := power(10, SIZE-1);
				while zeeroea>0 do
					begin
						if zeeroea > sum[100 - i + 1] then
							begin write(fo, 0); zeeroea:=zeeroea div 10; end
						else begin write(fo, sum[100 - i + 1]); break; end;
					end;
			end;
	end;

procedure split_to_holder;
	var l, i, s, holdercell :longint;
		d :byte;
	begin
		l := length(bigstring);
		s := 0;
		holdercell := 0;
		fillchar(holder, sizeof(holder), 0); //holder[0] := 0;
		//
		for i:=l downto 1 do
			begin
				d := ord(bigstring[i]) - 48;
				holdercell := d * power(10, s){(10**s)} + holdercell;
				inc(s);
				if s = SIZE then
					begin 
						holder[100 - holder[0]] := holdercell;
						inc(holder[0]); 
						holdercell := 0; s := 0;
					end;
			end;

		if (s <> 0) then
			begin
				holder[100 - holder[0]] := holdercell;
				inc(holder[0]); 
			end;
	end;

procedure adding;
	var i :longint;
		borrow :longint;
	begin
		borrow := 0; // collect digits exceeding SIZE digits
		sum[0] := max(holder[0], sum[0]); // ensure runs all digits
		//
		for i:=1 to sum[0] do
			begin
				sum[100-i+1] := sum[100-i+1] + holder[100-i+1] + borrow;
				borrow := sum[100-i+1] div power(10, SIZE); //(10**SIZE);
				sum[100-i+1] := sum[100-i+1] mod power(10, SIZE); //(10**SIZE);
			end;
		if borrow <> 0 then //emptying borrow
			begin
				inc(sum[0]);
				sum[100-sum[0]+1] := borrow;
			end;
	end;

BEGIN
	assign(fi, fi_name); reset(fi);
	//main
	readln(fi, n); 
	for i:=1 to n do 
		begin
			readln(fi, bigstring);
			//
			split_to_holder;
			adding;
		end;
	close(fi);
	//
	assign(fo, fo_name); rewrite(fo);
	where_the_zeroes;
	close(fo);
END.