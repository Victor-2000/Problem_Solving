//Condition of the problem: https://www.infoarena.ro/problema/ksecv3
Program ksecv3;
var s:int64;
    f,g:text;
    a:array[1..100000] of int64;
    b:array[1..100000] of longint;
    n,k,m,j,i:longint;
 begin
  assign(f,'ksecv3.in');
  assign(g,'ksecv3.out');
  reset(f);
  rewrite(g);
  readln(f,n,k);
  s:=0;
  for i:=1 to n do
   begin
   read(f,a[i]);
   s:=s+a[i];
   end;
  j:=0;
  m:= s div k;
  s:=0;
 for i:=1 to n do
   begin
   s:=s+a[i];
   if s = m then begin
    j:=j+1;
    b[j]:=i;
    s:=0;
   end else if s > m then begin
     writeln(g,-1);
     close(g);
     close(f);
     exit;
    end;
   end;
  for i:=1 to j do write(g,b[i],' ');
  close(f);
  close(g);
end.