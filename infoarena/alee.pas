//Condition of the problem: https://www.infoarena.ro/problema/alee
Program Alee;
type mat= array[1..175,1..175] of integer;
 coordonate = record
  x,y:integer;
 end;
 Coada = ^Celula;
 Celula = record
  inf: coordonate;
  urm: Coada;
  end;
var a:mat;
arr:array[1..4,1..2] of -1..1;
n,m,i,x,y,x2,y2:integer;
U:coada;
f,g:text;
procedure Pop (var P: coada);
begin
P:=p^.urm;
end;
procedure Push (var U,Q: coada;x,y:integer);
begin
new(Q);
Q^.inf.x:=x;
Q^.inf.y:=y;
U^.urm:=Q;
U:=Q;
end;
function Ok (x,y:integer):boolean;
begin
Ok:=true;
if (x>N) or (x < 1) or (y < 1) or (y > N) or (a[x,y] <> 0) then
 OK:= false;
end;
procedure Lee(var a:mat; x,y:integer);
var dir,i,j,iu,ju:integer;
P,R:coada;
begin
new(P);
new(R);
push(U,R,x,y);
P:=R;
while P <> nil do begin
 i:=P^.inf.x;
 j:=P^.inf.y;
 for dir:= 1 to 4 do begin
  iu:=i+arr[dir,1];
  ju:=j+arr[dir,2];
  if Ok(iu,ju) then begin
   if a[i,j] = -2 then
     a[iu,ju] := 1
    else
     a[iu,ju] := a[i,j] + 1;
   push(U,R,iu,ju);
  end;
 end;
 pop(P);
 end;
end;
begin
assign(f,'alee.in');assign(g,'alee.out');
reset(f);rewrite(g);
readln(f,n,m);
new(U);
for i:=1 to m do begin
 readln(f,x,y);
 a[x,y]:= -1;
end;
read(f,x,y,x2,y2);
arr[1,1]:=0;arr[1,2]:=1;
arr[2,1]:=1;arr[2,2]:=0;
arr[3,1]:=-1;arr[3,2]:=0;
arr[4,1]:=0;arr[4,2]:=-1;
a[x,y]:= -2;
Lee(a,x,y);
writeln(g,a[x2,y2]+1);
close(f);
close(g);
end.