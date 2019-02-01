# Digital-Lab

Assume that you work for the Digital Processing Lab. They ask you to write a program with an input binary matrix A, which contains the pattern to search on other binary matrix B. The input file include the size and elements for both A and B. The recognition process consists in scanning row by row (horizontal scanning) the matrix B, when a pattern is located on B you must mark this pattern. To mark a located pattern change 1 to 2 and 0 to * on B. The output file of your program will be the matrix B with the located patterns marked.

	Input

The first line of the input contains the size of A, next lines contains the matrix A
row by row, next line contains the size of B and next lines contains the matrix B
row by row.

	Output

The output is the matrix B with the located patterns marked.

INPUT FILE

2 2

1 0

1 1

5 5

1 1 0 0 0

0 1 1 0 0

1 0 0 1 0

1 1 1 1 0

0 0 1 1 1

Note: The input file contains the size of the matrix A, the matrix A, the size of the
matrix B and the matrix B.

OUTPUT FILE

1 2 * 0 0

0 2 2 0 0

2 * 0 1 0

2 2 1 2 *

0 0 1 2 2

INPUT FILE

1 1

1

5 5

1 1 0 0 0

0 1 1 0 0

1 0 0 1 0

1 1 1 1 0

0 0 1 1 1

OUTPUT FILE

2 2 0 0 0

0 2 2 0 0

2 0 0 2 0

2 2 2 2 0

0 0 2 2 2
