set terminal epslatex size 12cm,8cm
set output "fibonacci_num-time.tex"

set xl 'argument: $n\in\mathds{N}$'
set yl 'time: $t\in\mathds{R}^+, [t]=s$'

plot [0:15] 'fibonacci_num-data.txt' u 1:3 w lp title 'recursive',\
  '' u 1:5 w lp title 'linear',\
  '' u 1:7 w lp title 'constant'