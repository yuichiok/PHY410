f(x)=308.048+0.123225*x
set title 'CO2 vs time'
set xlabel 'time'
set ylabel 'CO2[ppm]'
set xrange [0:662]
plot f(x) title '308.048 + 0.123225 M', 'hist.dat' using 1:2 with points, 'hist.dat' using 1:3 with points
set output "quake.png"