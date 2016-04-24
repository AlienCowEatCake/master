#! /usr/bin/gnuplot -persist
set terminal postscript eps color enhanced size 12cm,7cm adobeglyphnames font ",18"
set termoption enhanced
save_encoding = GPVAL_ENCODING
set encoding utf8

set xlabel "h, m"
set ylabel "diff" offset 2,0

set grid
set nokey
set style line 10 lt 7 pt 4 lw 7
set output "presentation.eps"
plot "data.txt" using 1:2 with linespoints linestyle 10
