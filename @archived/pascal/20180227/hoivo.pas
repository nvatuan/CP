program hoivo;
const fi_name = 'HOIVO.INP'; fo_name = 'HOIVO.OUT';
	  m = 1000000007;//1007;
var fi, fo :text;
	k, n :longint;
	mul :int64; //use to (and for) remember

BEGIN
	assign(fi, fi_name); reset(fi);
	readln(fi, n, k); close(fi);
	mul := 1;
	// xu ly
	mul := mul * k mod m;
	k := n; 
	while n > 1 do
		begin
			mul := (mul * n) mod m;
			dec(n);
		end;
	//
	assign(fo, fo_name); rewrite(fo);
	write(fo, (mul + k) mod m); close(fo);
	// tao bi gay
END.