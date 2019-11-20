//Source of the problem: https://www.infoarena.ro/problema/energii
program Energii;

type
  nmax = 0..100000;
  gener = record
    e, c: nmax;
  end;
  vect = array[nmax] of gener;

var
  a: vect;
  b: array[nmax] of longint;
  i, j, n: nmax;
  w: longint;
  f, g: text;

function min(a, b: longint): longint;
begin
  if a > b then
    min := b
  else min := a;
end;

begin
  assign(f, 'energii.in');
  assign(g, 'energii.out');
  reset(f);
  rewrite(g);
  readln(f, n, w);
  for i := 1 to n do
  begin
    readln(f, a[i].e, a[i].c);
  end;
  for i := 1 to w do
    b[i] := 100000;
  for i := 1 to n do
  begin
    for j := w downto 1 do
    begin
      if j <= a[i].e then b[j] := min(b[j], a[i].c)
      else b[j] := min(b[j], b[j - a[i].e] + a[i].c);
    end;
  end;
  if b[w] = 100000 then write(g, '-1')
  else write(g, b[w]);
  close(f);
  close(g);
end.