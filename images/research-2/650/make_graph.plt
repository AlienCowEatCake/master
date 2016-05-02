#! /usr/bin/gnuplot -persist
set terminal postscript eps color enhanced size 3.3in,1.8in adobeglyphnames font ",16"
set termoption enhanced
save_encoding = GPVAL_ENCODING
set encoding utf8
set grid
set nokey
set style line 1 lt -1 pt 0 lw 3 lc rgb "#ff0000"
#set style line 2 lt -1 pt 0 lw 1
#set grid xtics ytics ls 2, ls 2
set grid ytics lt 1 lw 2 lc rgb "#cccccc"
set grid xtics lt 1 lw 2 lc rgb "#cccccc"

set xlabel '{/=18z, m}'
set xrange [-0.005:0.005]
#set xtics (-0.005,-0.0025,0,0.0025,0.005)

set ylabel '{/=18{/:Bold E}@^{/=16Re}_{/=16x} ,  V/m}' offset 2.07,0,0
set format y "%.3t×10^{%+02T}";
set yrange [1.997e-10:2.000e-10]
set ytics (1.997e-10,1.998e-10,1.999e-10,2.0e-10)
set output "ExR.eps"
plot "650_3.txt" using 1:2 with linespoints linestyle 1

set ylabel '{/=18{/:Bold E}@^{/=16Re}_{/=16y} ,  V/m}' offset 2.07,0,0
set format y "%.4t×10^{%+02T}";
set yrange [-7.542e-9:-7.541e-9]
set ytics (-7.542e-9,-7.54125e-9,-7.54150e-9,-7.54175e-9,-7.541e-9)
set output "EyR.eps"
plot "650_3.txt" using 1:4 title "650 EyR" with linespoints linestyle 1

set ylabel '{/=18{/:Bold E}@^{/=16Re}_{/=16z} ,  V/m}' offset 2.07,0,0
set format y "%.1t×10^{%+02T}";
set yrange [-2.5e-10:1.3e-9]
#set ytics (-2.5e-10,0,2.5e-10,5e-10,7.5e-10,1e-9,1.25e-9)
set ytics (0,3e-10,6e-10,9e-10,1.2e-9)
set output "EzR.eps"
plot "650_3.txt" using 1:6 title "650 EzR" with linespoints linestyle 1

set ylabel '{/=18{/:Bold E}@^{/=16Im}_{/=16x} ,  V/m}' offset 2.07,0,0
set format y "%.4t×10^{%+02T}";
set yrange [-1.0481e-10:-1.0471e-10]
set ytics (-1.0479e-10,-1.0476e-10,-1.0473e-10)
set output "ExI.eps"
plot "650_3.txt" using 1:3 title "650 ExI" with linespoints linestyle 1

set ylabel '{/=18{/:Bold E}@^{/=16Im}_{/=16y} ,  V/m}' offset 2.07,0,0
set format y "%.3t×10^{%+02T}";
set yrange [-6.591e-10:-6.583e-10]
set ytics (-6.590e-10,-6.588e-10,-6.586e-10,-6.584e-10)
set output "EyI.eps"
plot "650_3.txt" using 1:5 title "650 EyI" with linespoints linestyle 1

set ylabel '{/=18{/:Bold E}@^{/=16Im}_{/=16z} ,  V/m}' offset 2.07,0,0
set format y "%.1t×10^{%+02T}";
set yrange [-2e-10:1.6e-9]
set ytics (0,5e-10,1.0e-9,1.5e-9)
set output "EzI.eps"
plot "650_3.txt" using 1:7 title "650 EzI" with linespoints linestyle 1
