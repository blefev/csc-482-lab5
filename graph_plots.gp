# gnu plot scriptset
set key autotitle columnhead
set ylabel "Time in nanoseconds"

stats 'FibLoop' using 1:3
set title 'FibLoop X  vs Time (ns)'
set xlabel "X"
n = STATS_max_x
t = STATS_max_y
a = t / (n*log(n))
f(x) = a*x*log(x)
set yrange [:t]
set xrange [:n]
plot 'FibLoop' using 1:3, f(x)


stats 'FibLoop' using 2:3
set title 'FibLoop N vs Time (ns)'
set xlabel "N"
n = STATS_max_x
t = STATS_max_y
a = t / (n*log(n))
f(x) = a*x*log(x)
set yrange [:t]
set xrange [:n]
plot 'FibLoop' using 2:3, f(x)

##################################################

stats 'FibRecurDP' using 1:3
set title 'FibRecurDP X  vs Time (ns)'
set xlabel "X"
n = STATS_max_x
t = STATS_max_y
a = t / (2**n)
f(x) = a*2**n
set yrange [:t]
set xrange [:n]
plot 'FibRecurDP' using 1:3, f(x)


stats 'FibRecurDP' using 2:3
set title 'FibRecurDP N vs Time (ns)'
set xlabel "N"
n = STATS_max_x
t = STATS_max_y
a = t / (2**n)
f(x) = a*2**n
set yrange [:t]
set xrange [:n]
plot 'FibRecurDP' using 2:3, f(x)

######################################################


stats 'FibRecurDP' using 1:3
set title 'FibRecurDP X  vs Time (ns)'
set xlabel "X"
n = STATS_max_x
t = STATS_max_y
a = t / (n*log(n))
f(x) = a*x*log(x)
set yrange [:t]
set xrange [:n]
plot 'FibRecurDP' using 1:3, f(x)


stats 'FibRecurDP' using 2:3
set title 'FibRecurDP N vs Time (ns)'
set xlabel "N"
n = STATS_max_x
t = STATS_max_y
a = t / (n*log(n))
f(x) = a*x*log(x)
set yrange [:t]
set xrange [:n]
plot 'FibRecurDP' using 2:3, f(x)


