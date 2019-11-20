//Source of the problem: https://www.infoarena.ro/problema/fact
program Factorial;

var
  p: 0..100000010;
  st, dr, m: longint;
  f, g: text;

function zero(k: longint): longint;
var
  i, s: longint;
begin
  i := 5;
  s := 0;
  while k >= i do
  begin
    s := s + (k div i);
    i := i * 5;
  end;
  zero := s;
end;

begin
  assign(f, 'fact.in'); assign(g, 'fact.out');
  reset(f); rewrite(g);
  readln(f, p);
  if p = 0 then writeln(g, 1)
  else begin
    st := 1;
    dr := p * 5 + 100;
    while(st <= dr) do
    begin
      m := (st + dr) div 2;
      if(zero(m) >= p) then dr := m - 1
      else
        st := m + 1;
    end;
    if zero(st) = p then
      writeln(g, st)
    else
      writeln(g, '-1');
  end;
  close(f); close(g);
end.
