#!/bin/csh

rm -rf ../plots/dio-evmdd-d*.eps

echo "Collecting data..."

./collect

foreach d (1 2 3 4 5)
   set filename = '../plots/dio-evmdd-d'$d'.plot'
   rm -f $filename
   echo 'set term post eps color "Helvetica" 24' >> $filename
   echo '#set contour base' >> $filename
   echo 'set surface' >> $filename
   echo '#set hidden3d' >> $filename
   echo 'set view 135,45,1' >> $filename
   echo 'set xlabel "#vars"' >> $filename
   echo 'set ylabel "* monomials"' >> $filename
   echo 'set xtics (200, 400, 600, 800, 1000)' >> $filename
   echo 'set ytics (1, 2, 3, 4, 5)' >> $filename
   echo 'set key left top' >> $filename
#   echo 'set ztics (0.1, 1, 15, 180, 1800)' >> $filename
#   echo 'set ztics (0, "5" 300, "10" 600, "15" 900, "20" 1200, "25" 1500, "30" 1800)' >> $filename
#   echo 'set zrange [0.1:1800]' >> $filename
#   echo 'set log z' >> $filename
   echo ' ' >> $filename

   echo "Plotting graphs for degre "$d" ..."
   echo 'set output "../plots/dio-evmdd-d'$d'.eps"' >> $filename
   echo 'splot "../plots/d'$d'.dat" title "Avg runtime (sec), max degree '$d'" with linespoints' >> $filename
   echo '  ' >> $filename

   gnuplot $filename
end


   set filename = '../plots/dio-evmdd.plot'
   rm -f $filename
   echo 'set term post eps color "Helvetica" 24' >> $filename
   echo '#set contour base' >> $filename
   echo 'set surface' >> $filename
   echo '#set hidden3d' >> $filename
   echo 'set view 135,45,1' >> $filename
   echo 'set xlabel "#vars"' >> $filename
   echo 'set ylabel "* monomials"' >> $filename
   echo 'set xtics (200, 400, 600, 800, 1000)' >> $filename
   echo 'set ytics (1, 2, 3, 4, 5)' >> $filename
   echo 'set key left top' >> $filename
#   echo 'set ztics (0.1, 1, 15, 180, 1800)' >> $filename
#   echo 'set ztics (0, "5" 300, "10" 600, "15" 900, "20" 1200, "25" 1500, "30" 1800)' >> $filename
#   echo 'set zrange [0.1:1800]' >> $filename
#   echo 'set log z' >> $filename
   echo ' ' >> $filename

   echo "Plotting unified graph ..."
   echo 'set output "../plots/dio-evmdd.eps"' >> $filename
   echo 'splot "../plots/d1.dat" title "Avg runtime (sec), max degree 1" with linespoints, \' >> $filename
   echo '      "../plots/d2.dat" title "Avg runtime (sec), max degree 2" with linespoints, \' >> $filename
   echo '      "../plots/d3.dat" title "Avg runtime (sec), max degree 3" with linespoints' >> $filename
   echo '  ' >> $filename

   gnuplot $filename



if ($#argv > 0) then
   cd ../plots
   foreach f (*.eps)
   echo "Converting "$f" to PDF format ..."
   epstopdf $f
   end
   cd ..
endif

#   pdflatex evmdd-plots.tex
#   rm -f evmdd-plots.{log,aux}

