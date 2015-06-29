set title "Maxwell distribution"
v2m = 1.0
KbT = 0.5*v2m
Pv(x) =1.0/KbT*x*x*exp(-0.5*x*x/KbT)
Pvx(x) =exp(-0.5*x*x/KbT)
U(x) = 4.0*(1.0/(x*x*x*x*x*x*x*x*x*x*x*x)-1/(x*x*x*x*x*x))
set auto x
# set style data histogram
# set style histogram cluster gap 1
set style fill solid border -1
set boxwidth 0.10
# set xtic rotate by -45 scale 0
#set bmargin 10
set multiplot
set size 1,0.3
set origin 0.0, 0.6
set xrange [0:3.0]
plot Pv(x) title "Theoretical", 'hist_v.dat' w boxes title "Simulated"
set boxwidth 0.20
set origin 0.0, 0.3
set xrange [-3.0:3.0]
plot Pvx(x) title "Theoretical", 'hist_vx.dat' w boxes title "Simulated"
set origin 0.0, 0.0
set xrange [0.001:0.02]
plot U(x) title "Lennard-Jones potential"
unset multiplot
# pause -1
