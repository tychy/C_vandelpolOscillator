set terminal png
#set terminal aqua
set output "vector.png"
#set title "(n,2n) reaction"
#set xrange [ 0 : 20 ]
#set yrange [ 0 : 2 ]
#set mxtics 5
#set mytics 5
#set xtics 5
#set ytics 0.5
n=0.025
#plot "output.dat" using 1:2:(n*($3)):(n*($4)) with vectors
plot "output.dat" with vectors
