Given a DAG, returns the longest path and the minimum amount of vertices to reach all elements in the given graph

Input

The input file is defined as follows:

 The first line contains two integers: the number n of vertices(n ≥ 2), and the number
of dependencies m to indicate (m ≥ 0);

 A list where each row i contains two integers x and y indicating that there is an edge from x to y.

Any integers on a line are separated by at most one white space, not
containing any character other than the end of line.

Output
 <min> <longest> where <min> corresponds to the minimum amount of vertices to reach all elements and  <longest> corresponds to the longest path.

Exemple
Input
7 8
3 4
3 2
4 6
4 5
6 2
6 5
5 7
2 7
Output
2 5

Compilation
 g++ -std=c++11 -O3 -Wall file.cpp -lm
