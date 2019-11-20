//Source of the problem: https://www.infoarena.ro/problema/lacate
program Lacate;

type
  vect = array[1..256, 0..512] of integer;

var
  C, L, N, i, j: integer;
  sol: vect;
  f, g: text;

procedure Generare(var sol: vect);
var
  i, j: integer;
  enum: boolean;
begin
  for i := 1 to n do
  begin
    enum := false;
    for j := 1 to c do
      if i = 1 then
        sol[i, j] := j
      else
      if j < i then
        sol[i, j] := sol[j, i - 1]
      else
      if enum = false then begin
        sol[i, j] := sol[i, j - 1] + n + 1 - i;
        enum := true;
      end
      else
        sol[i, j] := sol[i, j - 1] + 1;
  end;
end;

begin
  assign(f, 'lacate.in'); assign(g, 'lacate.out');
  reset(f); rewrite(g);
  readln(f, n);
  c := n - 1;
  l := c * n div 2;
  Generare(sol);
  writeln(g, l, ' ', c);
  for i := 1 to n do
  begin
    for j := 1 to c do
      write(g, sol[i, j], ' ');
    writeln(g);
  end;
  close(f); close(g);
end.