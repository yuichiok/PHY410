f(x)=x/((2)*x+1)+0.5
g(x)=x/((5)*x+1)+0.666667
h(x)=x/((2)*x+1)+0.5
set title 'Equivalent resistance vs Resistor'
set xlabel 'Resistance R'
set ylabel 'Equivalent resistance R_eq'
set xrange [0:100]
plot f(x) title 'G1',g(x) title 'G2',h(x) title 'G3'
