program kinhdoanh;
const fi_name = 'KINHDOANH.INP';
	  fo_name = 'KINHDOANH.OUT';
var fi, fo :text;
	n, m, i, greed1, greed2 :longint;
	port :array[1..10000, 0..10000] of longint;
	//----------- Program varibles -----------//
	visited :array[1..10000] of boolean;
	clusts :array[0..10000] of longint;
procedure readfile;
	var x, y, dummy :longint;
	begin
		assign(fi, fi_name);
		reset(fi);
		readln(fi, n, m);
		for i:=1 to m do
			begin
				readln(fi, x, y);
				if x>y then
					begin
						dummy := x;
						x := y;
						y := dummy;
					end;
				{
				connect[x, y] := true;
				connect[y, x] := true;
				}
				inc(port[x, 0]);
				port[x, port[x,0] ] := y;
			end;
		close(fi);
	end;
procedure writefile;
	begin
		assign(fo, fo_name);
		rewrite(fo);
		write(fo, greed1 + greed2);
		close(fo);
	end;
function craw(ville :longint):longint;
	var i :longint;
	begin
		craw := 1;
		visited[ville] := true;
		for i:=1 to port[ville, 0] do
			if visited[ port[ville, i] ] = false then
				inc(craw, craw(port[ville, i] ));
	end;

BEGIN
	readfile;
	for i:=1 to n do
		begin
			if visited[i] = false then
				begin
					inc(clusts[0]);
                    clusts[ clusts[0] ] := craw(i);
				end;
		end;
	
	greed1 := clusts[1];
	greed2 := 0;
	for i:=2 to clusts[0] do
		if greed1 < clusts[i] then
			begin
				greed2 := greed1;
				greed1 := clusts[i];
			end
		else if greed2 < clusts[i] then
			greed2 := clusts[i];
	// ima hope that it'll be correct.

	writefile;
END.
