program CountingoutRhyme;
type link = record
		prev, next:longint;
	end;
var	n, k, i, leader, num, kick :longint;
	a :array[1..100] of link;
	ka :array[1..99] of longint;

procedure update(i :longint);
	begin
		a[a[i].prev].next := a[i].next;
		a[a[i].next].prev := a[i].prev;
	end;
function get_next(i, s :longint):longint;
	begin
		if(s = 0) then exit(i)
		else exit(get_next(a[i].next, s-1));
	end;

BEGIN
	readln(n, k);
	for i:=1 to k do read(ka[i]);
	for i:=1 to n do
		begin
			a[i].prev := i-1;
			a[i].next := i+1;
		end;
	a[1].prev := n;
	a[n].next := 1;

	leader := 1;
	num := n;
	for i:=1 to k do
		begin
			kick := get_next(leader, ka[i] mod num);
			write(kick,' ');
			update(kick);
			leader := a[kick].next;
			dec(num);
		end;
END.
