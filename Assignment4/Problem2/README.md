# Assignment4

Assignment 4 goes here.  

## Problem2  

In order to compile every .cpp files, make then as:  
```
$make
```
`scattering` would be the one for this problem. Ignore other excecutables.  
In order to remove object files, type:
```
$make clean
```
This will remove all object files as well as datasets inside data directory.  
Trajectory files can be plotted easily by typing:
```
$python plot.py (DATASET_NUMBER)
```
***NOTE:*** Scattering angle is known to reach its maximum at impact parameter b = 1.80, which corresponds to index *DATASET_NUMBER = 10*.  
Similary, differential cross sections are stored in `diff_cross0.data`, `diff_cross1.data`, `diff_cross2.data` which corresponds to E = 0.705, 0.7054, 0.70541 respectively.  
We can also plot this easily by typing:
```
$python plot_Xsec.py (DATASET_NUMBER)
```