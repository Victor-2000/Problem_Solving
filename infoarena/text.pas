//Condition of the problem: https://www.infoarena.ro/problema/text
program ttext;

type
  cuv = set of char;

var
  c: cuv;
  i: char;
  str: boolean;
  nrl, nrc, s: longint;
  f, g: text;

begin
  assign(f, 'text.in');
  assign(g, 'text.out');
  reset(f); rewrite(g);
  for i := 'A' to 'Z' do
  begin
    c := c + [i];
  end;
  for i := 'a' to 'z' do
  begin
    c := c + [i];
  end;
  str := false;
  while not eof(f) do
  begin
    read(f, i);
    if i in c then begin
      nrl := nrl + 1;
      if str = false then
        nrc := nrc + 1;
      str := true;
    end else
      str := false;
  end;
  s := nrl div nrc;
  writeln(g, s);
  close(f); close(g);
end.