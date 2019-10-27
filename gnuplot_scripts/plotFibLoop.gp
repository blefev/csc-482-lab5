# gnu plot
set key autotitle columnhead
set ylabel "Time in nanoseconds"

stats '../output/FibLoop' using 2:3
set title 'FibLoop N vs Time (ns)'
set xlabel "N"
n = STATS_max_x
t = STATS_max_y
a = t / (n*log(n))
f(x) = a*x*log(x)
set yrange [0:t]
set xrange [0:n]
plot '../output/FibLoop' using 2:3 lw 3, f(x) lw 3
