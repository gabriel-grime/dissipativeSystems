set term epslatex standalone color colortex 12 clip 'cmr' size 5cm, 6cm

set output 'fig.tex'

set format y '%.1f'
set format x '%.2f'

set xtics 0.01
set mxtics 5
set ytics 0.2
set mytics 2

set xlabel '\Large{$a$}' offset 0,0.4
set ylabel '\Large{$x$}' offset 1.8,0 rotate by 0

set lmargin 5.2
set tmargin 0.5
set rmargin 2.5
set bmargin 2.5

set key off

set xrange [3.83:3.844]
set yrange [0.12:0.98]

f(x) = 0.5

plot 'bif1.dat' using 1:2 with points pt 7 lc rgb 'black' ps 0.1

