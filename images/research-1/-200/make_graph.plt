#! /usr/bin/gnuplot -persist
set terminal postscript eps color enhanced size 8.2cm,6cm adobeglyphnames font ",17"
set termoption enhanced
save_encoding = GPVAL_ENCODING
set encoding utf8

set xlabel "x, m"
set ylabel "EyR, V/m" offset 1,0

set grid
set key top right
set style line 6 lt 6 pt 0 lw 5
set style line 7 lt 7 pt 0 lw 5
set output "EyR_-700.eps"
plot "std/z=-700.dat" using 1:3 title "EyR, with air" with linespoints linestyle 6, \
     "noair/z=-700.dat" using 1:3 title "EyR, without air" with linespoints linestyle 7
