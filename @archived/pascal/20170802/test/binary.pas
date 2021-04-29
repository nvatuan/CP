const
  fi='binary.inp';
  fo='binary.out';

var
  f1,f2:text;
  st,st2,st3:ansistring;

procedure sum(x,y:ansistring);
  var
    i,z,s:longint;
    kt:string;
  begin
    st3:='';
    kt:='';
    z:=0;
    for i:=length(x) downto 1 do
      begin
        if (x[i]='1') and (y[i]='1') then
          begin
            s:=0+z;
            z:=1;
          end;
        if ((x[i]='1') and (y[i]='0')) or ((x[i]='0') and (y[i]='1')) then
          if z=0 then
            s:=1
          else
            begin
              s:=0;
              z:=1;
            end;
        if (x[i]='0') and (y[i]='0') then
          if z=0 then
            s:=0
          else
            begin
              s:=1;
              z:=0;
            end;
        str(s,kt);
        st3:=kt+st3;
      end;
    if z=1 then
      st3:='1'+st3;
  end;


begin
  assign(f1,fi);
  assign(f2,fo);
  reset(f1);
  rewrite(f2);
  readln(f1,st);
  while length(st) mod 4 <> 0 do
    st:='0'+st;
  st2:=st;
  insert('0000',st,length(st)+1);
  insert('0000',st2,1);
  sum(st,st2);
  while st3[1]='0' do
   delete(st3,1,1);
  write(f2,st3);
  close(f1);
  close(f2);
end.
