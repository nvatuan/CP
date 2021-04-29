program LienThong;
uses math;
const fi_name = 'lienthong.inp';
	  fo_name = 'lienthong.out';
type data = record
		tag :longint;
                v :char;
	 end;
var fi, fo :text;
	ans, n, m, i, j, n_tag, sans :longint;
	Binboard :array[0..10001,0..10001] of data;
	SpTag :array[1..10000] of longint;
	Assotag :array[1..10000,0..10000] of shortint;

procedure readfile;
	begin
		assign(fi, fi_name);
		reset(fi);
		readln(fi, m, n);
		for i:=1 to m do
			begin
				for j:=1 to n do
					read(fi, Binboard[i, j].v);
				readln(fi);
			end;
		close(fi);
	end;
procedure writefile;
	begin
		assign(fo, fo_name);
		rewrite(fo);
		write(fo, ans);
		close(fo);
	end;
procedure sweep;
	var x, y, cur_tag
        :longint;
	begin
		for x:=1 to m do
			for y:=1 to n do
			if(Binboard[x, y].v = '1') then
			begin
				if(Binboard[x, y].tag = 0) then
					begin
						Binboard[x, y].tag := n_tag;
                        inc(SpTag[n_tag]);
						inc(n_tag);
					end
				else inc( SpTag[Binboard[x, y].tag] );
				///----
				for i:=0 to 1 do
					for j:=0 to 1 do
					if(abs(i+j) = 1) then //check horizon and vertical
						if(Binboard[x-i, y-j].v = '1') and
							(Binboard[x-i, y-j].tag <> Binboard[x, y].tag) then
							begin
								cur_tag := min(Binboard[x-i ,y-j].tag, Binboard[x, y].tag);

								inc(Assotag[cur_tag, 0]);
								//increase associate index
								Assotag[cur_tag, Assotag[cur_tag, 0]] :=  Binboard[x-i, y-j].tag;
								//set associated space
								//increase '1' space by Tag
							end;
				///----
			for i:=-1 to 0 do
					for j:=-1 to 0 do
					if(abs(i+j)=1) then
						if(Binboard[x-i, y-j].v = '1') then
						begin
							Binboard[x-i, y-j].tag := Binboard[x, y].tag;
						end;
			end;
	end;
procedure get_ans;
	begin
		if n_tag > 10000 then
			begin
				ans := 1;
				exit;
			end;
		for i:=1 to n_tag do
			begin
				sans := SpTag[i];
				for j:=1 to Assotag[i, 0] do
					sans := sans + SpTag[ Assotag[i, j] ];
				ans := max(sans, ans);
			end;
	end;
BEGIN
	readfile;
	n_tag := 1;
	sweep;
	get_ans;
	writefile;
END.
