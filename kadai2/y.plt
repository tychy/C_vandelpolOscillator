set terminal png
set output "y.png"
#set title "(n,2n) reaction"
#set xrange [ 0 : 20 ]
#set yrange [ 0 : 2 ]
#set mxtics 5
#set mytics 5
#set xtics 5
#set ytics 0.5
plot "output.dat" using 1:3 w l
