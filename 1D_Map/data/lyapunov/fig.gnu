set term epslatex standalone color colortex 12 clip 'cmr' size 8cm, 6cm

set output 'fig.tex'

set xrange [3.82:3.86]
set yrange [-2:1]

set format y '%.1f'
set format x '%.2f'

set xtics 0.02
set mxtics 2
set ytics 1
set mytics 2

set xlabel '\Large{$a$}' offset 0,0.4
set ylabel '\Large{$\lambda$}' offset 2,0 rotate by 0

set lmargin 6
set tmargin 0.5
set rmargin 2.5
set bmargin 2.5

set key off

f(x) = 0

plot 'lyapunov2.dat' using 1:2 with lines lc rgb 'black' lw 1.5,\
f(x) with lines lc rgb 'black'

