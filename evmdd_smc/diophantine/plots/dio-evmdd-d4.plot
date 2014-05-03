set term post eps color "Helvetica" 24
#set contour base
set surface
#set hidden3d
set view 135,45,1
set xlabel "#vars"
set ylabel "* monomials"
set xtics (200, 400, 600, 800, 1000)
set ytics (1, 2, 3, 4, 5)
set key left top
 
set output "../plots/dio-evmdd-d4.eps"
splot "../plots/d4.dat" title "Avg runtime (sec), max degree 4" with linespoints
  
