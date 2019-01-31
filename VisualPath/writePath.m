% t = [-60:0.2:60];
% 
% x = [-60:0.2:60];
% y = x;
% ct = size(t);
% for i = 1: ct(2)
%     if (t(i) <= -45)
%         y(i) = -5.625;
%         x(i) = t(i);
%     else
%         if (t(i) > -45 && t(i) <= -35)
%         y(i) = 1.875 * sin(t(i)) - 3.75;
%         x(i) = t(i);
%         else
%             if (t(i) > -7.5 && t)
% end
pi = 3.1415926
t=0.3;
x = [];
y = [];
linex = [-60:t:-45];
liney = linex * 0 -5.625;
x = [x, linex];
y = [y, liney];
sinx = [-45:t:-35];
siny = 1.875 * sin(pi * sinx /10) - 3.75;
x = [x, sinx];
y = [y, siny];
linex = [-35:t:-7.5];
liney = linex * 0 - 1.875;
x = [x, linex];
y = [y, liney];
theta = [-pi/2:t/9.375:0];
circlex = 9.375 * cos(theta) - 7.5;
circley = 9.375 * sin(theta) + 7.5;
x = [x, circlex];
y = [y, circley];
liney = [7.5 : t : 50];
linex = 0 * liney + 1.875;
x = [x, linex];
y = [y, liney];
% y = 0 * x  -5.625;%2 * sin(0.2 * x) - 3.5;
ct = size(x);
f = fopen('path1.txt', 'w');
fprintf(f, 'timescale 0.5\n');
for i = 1: ct(2)
    fprintf(f, '%.4f %.4f\n', x(i), y(i));
end
fclose(f);

t2 = 0.1
% y = [30:-0.1:-30];
% x = 2 * sin(0.2 * y) - 3.5;
x = [];
y = [];
liney = [30:-t2:7.5];
linex = liney * 0 - 5.625;
x = [x, linex];
y = [y, liney];

theta = [0:-t2/1.875:-pi/2];
circlex = 1.875 * cos(theta) - 7.5;
circley = 1.875 * sin(theta) + 7.5;
x = [x, circlex];
y = [y, circley];
linex = [-7.5:-t2:-80];
liney = linex * 0 + 5.625;
x = [x, linex];
y = [y, liney];

f = fopen('path2.txt', 'w');
fprintf(f, 'timescale 0.5\n');
ct = size(x);
for i = 1: ct(2)
    fprintf(f, '%.4f %.4f\n', x(i), y(i));
end
fclose(f);

