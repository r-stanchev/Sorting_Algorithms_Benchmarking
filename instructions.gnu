set title "ALGORITHMS"
set ylabel "Microseconds"
set xlabel "Algorithms"
set grid
set style fill transparent solid 0.5 border -1
set boxwidth 0.70 relative
plot for [COL=2:2] "times_data.dat" using COL:xticlabels(1) w boxes lc rgb"blues" notitle
