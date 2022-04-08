
set format y '%.1f'
set format x '%.1f'

#set xtics 1
set mxtics 2
#set ytics 0.5

#set xtics add ("1.6" 1.6, 0)
a=3.3
f(x) = a*x*(1-x)
f2(x) = 4*a*x*(1-x)*(1-a*x*(1-x))
g(x)=x
set xzeroaxis linetype 1 lc rgb "black" lw 1

set yzeroaxis linetype 1 lc rgb "black" linewidth 1

set key off

set xrange [-1:10]
set yrange [-1:5]

plot f(x) with lines lc rgb 'blue' lw 2, g(x) with lines lc rgb 'black' lw 1,\
'cobweb.dat' using 1:2 with lines lc rgb 'red' lw 1
