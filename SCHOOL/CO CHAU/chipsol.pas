program chip_linh_kien;
const fi='chip1.inp';
        fo='chip1.out';
var
   M,n,k:byte;
   a,dx,dy,sol:array[1..100] of byte;
   c:array[1..100,1..100] of byte;
//=================
procedure doc;
var f:text;
   i,j,x,t:byte;
begin
  assign(F,fi); reset(f);
  readln(f,m,n,k);
  fillchar(c,sizeof(c),0);
  fillchar(dx,sizeof(dx),0);
  fillchar(dy,sizeof(dy),0);
  for i:=1 to n do
  begin
    read(f,x);
    for t:=1 to x do
     begin
       read(f,j);
       c[i,j]:=1;
       inc(dx[i]);
       inc(dy[j]);
     end;
    //readln(f);
  end;
  fillchar(a,sizeof(a),0);
  for i:=1 to k do
   begin
     read(f,j); a[j]:=1;
   end;
  close(f);
end;
//==================
procedure nosolution;
var f:text;
begin
 assign(f,fo); rewrite(f);
 write(f,'NO');
 close(f);
 halt;
end;
//=====================
procedure prepare;
var i,j:byte;
begin
  for i:=1 to n do
    for j:=1 to M do
     if (c[i,j]=1) and (a[j]=0) then
      begin
        c[i,j]:=0;
        dec(Dx[i]);
        dec(dy[j]);
      end;
end;
//===================
function minx:byte;
var i,j:byte;
begin
  j:=0;
  for i:=1 to N do
   if dx[i]>0 then
    if (j=0) or (dx[i]<dx[j]) then j:=i;
  Minx:=j;
end;
//================
function miny(x:byte):byte;
var i,j:byte;
begin
  j:=0;
  for i:=1 to M do
   if c[x,i]=1 then
    if (j=0) or (dy[i]<dy[j]) then j:=i;
  Miny:=j;
end;
//======================
procedure del(x,y:byte);
var i:byte;
begin
 for i:=1 to M do
  if c[x,i]=1 then
    begin
      c[x,i]:=0;
      dec(dy[i]);
    end;
 for i:=1 to n do
  if c[i,y]=1 then
  begin
    c[i,y]:=0;
    dec(dx[i]);
  end;
 dx[x]:=0;
 dy[y]:=0;
end;
//=======================
procedure xuli;
var i,x,y:byte;
begin
  prepare;
  fillchar(sol,sizeof(sol),0);
  for i:=1 to n do
   begin
     x:=minX;
     if x=0 then nosolution;
     y:=minY(x);
     if y=0 then nosolution;
     sol[x]:=y;
     del(x,y);
   end;
end;
//==================
procedure ghi;
var f:text;
   i:byte;
begin
  assign(F,fo); rewrite(f);
  writeln(f,'YES');
  FOR i:=1 to N do write(f,sol[i],' ');
  close(f);
end;
//================
BEGIN
  doc;
  xuli;
  ghi;
END.