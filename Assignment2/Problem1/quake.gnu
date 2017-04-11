f(x)=7.12847+-0.949191*x
set title 'Gutenberg-Richter Law'
set xlabel 'Magnitude M'
set ylabel 'log_10(N) per bin'
set xrange [0:10]
plot f(x) title '7.12847 - 0.949191 M', 'histogram.dat' with points, 'histogram.dat' with impulses lw 2
