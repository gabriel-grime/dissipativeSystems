set terminal png size 1200,1000 enhanced font "Helvetica Bold,30"
set output '../figures/output.png'

set key off

set xrange [1:4]
set yrange [-8:2]

#set xtics 0.2
set mxtics 2

#set ytics 1
set mxtics 2

set lmargin 5.7
set bmargin 3.1
set rmargin 2

set format x '%.1f'
set format y '%.f'

set xlabel "x"
set ylabel "y" rotate by 0 offset 0

plot 'lyapunov.dat' using 1:2 with points pt 7 lc rgb 'black' ps 0.2

