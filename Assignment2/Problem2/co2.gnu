f(x)=308.048+0.123225*x
set title 'data.real vs i'
set xlabel 'i'
set ylabel 'data'
set xrange [0:662]
plot f(x) title '308.048 + 0.123225 M', 'hist.dat' using 1:2 with points, 'hist.dat' using 1:3 with points
