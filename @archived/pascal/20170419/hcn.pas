program HCN;
const fi_name = 'HCN.inp'; fo_name = 'HCN.out';
type coordinate = record
		x1, x2, y1, y2 :longint;
	 end;
	 rectangle = record
	 	id, area :longint;
	 end;

var fi, fo :text;
	n, i, j :longint;
	rec :array[1..100] of coordinate;
	//--------------------------------------------
	data :array[1..100] of rectangle;
	bounding_lv :array[1..100] of byte;
procedure readfile;
	begin
		assign(fi, fi_name);
		reset(fi);
		readln(fi, n);
		for i:=1 to n do
			begin
				readln(fi, rec[i].x1, rec[i].y1, rec[i].x2, rec[i].y2);
			end;
		close(fi);
	end;
procedure writefile;
	var ans :longint;
	begin
		assign(fo, fo_name);
		rewrite(fo);

		ans := bounding_lv[1];
		for i:=2 to n do
			if ans < bounding_lv[i] then ans := bounding_lv[i];

		writeln(fo, ans);

		close(fo);
	end;
procedure sort_by_area;
	var s :longint;
	begin
		//-- Get area
		for i:=1 to n do
			begin
				s := abs(rec[i].x2 - rec[i].x1) * abs(rec[i].y2 - rec[i].y1);
				data[i].area := s;
				data[i].id := i;
			end;
		//-- Sort
		for i:=1 to n-1 do
			for j:=i+1 to n do
				if( data[i].area > data[j].area ) then
					begin
						s := data[i].area;
						data[i].area := data[j].area;
						data[j].area := s;

						s := data[i].id;
						data[i].id := data[j].id;
						data[j].id := s;
					end;
		//------------------
	end;
function bounded(u, v :longint):boolean;
	begin
		if (rec[u].x1 <= rec[v].x1) and (rec[u].y1 <= rec[v].y1) and
			(rec[u].x2 >= rec[v].x2) and (rec[u].y2 >= rec[v].y2) then
				exit(true);
		exit(false);
	end;
procedure bounding;
	begin
		fillchar(bounding_lv, sizeof(bounding_lv), 1);
		//
		for i:=2 to n do
			for j:=i-1 downto 1 do
				begin
					if (bounding_lv[i] < bounding_lv[j] + 1) and bounded( data[i].id, data[j].id ) then
						bounding_lv[i] := bounding_lv[j] + 1;
				end;
	end;
BEGIN
	readfile;
	sort_by_area;
	bounding;
	writefile;
END.
