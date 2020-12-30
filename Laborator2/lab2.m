x = 1:0.1:50;

O1 = x.^3;
T1 = x.^3;
On = x.^3 .+ (x.^2).*log2(x);
Tn = 4*(x.^3)./(x.+3);

s = T1 ./ Tn;
e = T1 ./ (x.*Tn);
r = On ./ O1;
u = On ./ (x.*Tn);
q = (T1.^3) ./ (x.*Tn.^2.*On)

accelerare = plot(x, s);
hold on;
[ax, accelerare, eficienta] = plotyy(x, s, x, e);
hold on;
redundanta = plot(x, r);
hold on;
[ax, accelerare, utilizare] = plotyy(x, s, x, u);
hold on;
calitate = plot(x, q);

title('Performanta');
legend([accelerare; eficienta; redundanta; utilizare; calitate],
  ["Accelerarea"; "Eficienta"; "Redundanta"; "Utilizarea"; "Calitatea"]);
