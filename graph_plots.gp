# gnu plot scriptset
set key autotitle columnhead
set ylabel "Time in nanoseconds"

stats 'output/FibLoop' using 1:3
set title 'FibLoop X  vs Time (ns)'
set xlabel "X"
n = STATS_max_x
t = STATS_max_y
a = t / (n*log(n))
f(x) = a*x*log(x)
set yrange [0:t]
set xrange [0:n]
plot 'output/FibLoop' using 1:3, f(x)


stats 'output/FibLoop' using 2:3
set title 'FibLoop N vs Time (ns)'
set xlabel "N"
n = STATS_max_x
t = STATS_max_y
a = t / (n*log(n))
f(x) = a*x*log(x)
set yrange [0:t]
set xrange [0:n]
plot 'output/FibLoop' using 2:3, f(x)

##################################################

stats 'output/FibRecur' using 1:3
set title 'FibRecur X  vs Time (ns)'
set xlabel "X"
n = STATS_max_x
t = STATS_max_y
a = t / (2**n)
f(x) = a*2**x
set yrange [0:t]
set xrange [0:n]
plot 'output/FibRecur' using 1:3, f(x)


stats 'output/FibRecur' using 2:3
set title 'FibRecur N vs Time (ns)'
set xlabel "N"
n = STATS_max_x
t = STATS_max_y
a = t / (2**n)
f(x) = a*2**x
set yrange [0:t]
set xrange [0:n]
plot 'output/FibRecur' using 2:3, f(x)

######################################################


stats 'output/FibRecurDP' using 1:3
set title 'FibRecurDP X  vs Time (ns)'
set xlabel "X"
n = STATS_max_x
t = STATS_max_y
a = t / (n**2)
f(x) = a*x**2
set yrange [0:t]
set xrange [0:n]
plot 'output/FibRecurDP' using 1:3, f(x)


stats 'output/FibRecurDP' using 2:3
set title 'FibRecurDP N vs Time (ns)'
set xlabel "N"
n = STATS_max_x
t = STATS_max_y
a = t / (n**2)
f(x) = a*x**2
set yrange [0:t]
set xrange [0:n]
plot 'output/FibRecurDP' using 2:3 lw 4, f(x) with lines lw 4


######################################################

stats 'output/FibMatrix' using 1:3
set title 'FibMatrix X  vs Time (ns)'
set xlabel "X"
n = STATS_max_x
t = STATS_max_y
a = t / (n*log(n))
f(x) = a*x*log(x)
set yrange [0:t]
set xrange [0:n]
plot 'output/FibMatrix' using 1:3 with points lw 3, f(x)


stats 'output/FibMatrix' using 2:3
set title 'FibMatrix N vs Time (ns)'
set xlabel "N"
n = STATS_max_x
t = STATS_max_y
a = t / (n*log(n))
f(x) = a*x*log(x)
set yrange [0:t]
set xrange [0:n]
plot 'output/FibMatrix' using 2:3 with points lw 3, f(x)

######################################################