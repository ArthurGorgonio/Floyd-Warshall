# Floyd-Warshall
The Floyd-Warshall algorithm to EDA course in PPgSC/UFRN.

## Execute this file
we assume the input file "input.txt" exists.
```SHELL
$gcc floyd-warshall.c -o floyd
$./floyd < input.txt
```
and it has this format
```
5
0 6 999 999 999
999 0 5 8 -4
999 -2 0 999 999
999 999 -3 0 9
2 999 7 999 0
```
when each line and colunm represent a vertex and the cell is the weigth of the edge.

## Questions & Answers
1. The source code is described in this repository;
2. This code campute and storage the all-pairs shortest-paths and write the output in "output.txt" each execution this file is genereted (lines 41-58);
3. After compute the distances and create output file, the algorithm check the main diagonal to check if exists negative cicles (main diagonal < 0) (lines 52-56);
4. For runtime θ(V³), because exists a triple "for" statement. In the lines 43-46 have the follow struct:
```C
for(i = 0; i < v; i++) {
    for(j = 0; j < v; j++) {
        for(k = 0; k < v; k++) {
            ···
```
But if we analyse memory consumption this algorithm has a θ(V²), because the struture than ewe use in this implementation is a matrix (2D-array), then only we need two "for" statement to go through the matrix (lines 80-83).
