CONST fo='sinhto.out';
VAR i,j,k:longint;
    a,b:array[1..10000]of longint;
    f:text;
    kt:boolean;
begin
 assign(f,fo);rewrite(f);
 k:=0;
 for i:=2 to 99 do
  begin
   kt:=true;
   for j:=2 to  trunc(sqrt(i)) do
    if i mod j =0 then kt:=false;
   if kt=true then
    begin
     inc(k);
     a[k]:=i;
    end;
  end;
 for i:=1 to k do
  for j:=1 to k do
  begin
   if a[j]<10 then  b[a[i]*10+a[j]]:=1
   else b[a[i]*100+a[j]]:=1;
  end;
 for i:=1 to 1001 do
  if b[i]=1 then write(i,' ');
 readln;
end.
