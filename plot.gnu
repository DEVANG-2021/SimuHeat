set terminal png size 600,600
set output 'heatmap.png'
set view map
unset key
set xrange [0:50]
set yrange [0:50]
set cbrange [25:100]
set palette defined (0 "blue", 1 "cyan", 2 "green", 3 "yellow", 4 "red")
splot 'output/heat_500.dat' using 1:2:3 with image
