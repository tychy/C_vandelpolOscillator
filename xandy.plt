set terminal png
set output "xandy.png"
#set title "(n,2n) reaction"
#set xrange [ 0 : 20 ]
#set yrange [ 0 : 2 ]
#set mxtics 5
#set mytics 5
#set xtics 5
#set ytics 0.5
plot "output.dat" using 2:4 w l,\
     "output.dat" using 3:5 w l
