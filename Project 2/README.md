Context 
 Given a system with two processors X and Y, n processes and costs
both between the processes themselves and between processes and processors.
The cost between processes running in the same processor is always 0.
Find the lowest possible cost to run all processes by assigning
them to each of the processors;

Exemple
Execution costs of each pi process

i  1 2 3 4
Xi 6 5 10 4
Yi 4 10 3 8

Communication costs cij between two processes (pi,pj)
c 1 2 3 4 i
1 0 5 0 0
2 5 0 6 2
3 0 6 0 1
4 0 2 1 0
j

Solution
AX = {p4}
AY = {p1, p2, p3}

Cost = Σi∈AX Xi +Σi∈AY Yi +Σ(i, j)∈AX×AYcij
= X4 +Y1 +Y2 +Y3 +c24 +c34
= 4+4+10+3+2+1
= 24

Input

•The first line contains two integers: the number n of processes (n ≥ 2); and the number k of
entries other than 0 in the communication cost matrix (k ≥ 0), only diagonally
superior since the matrix is ​​symmetrical;
• n lines with two integers with the execution costs of pi on processor X and Y, respectively;
• k lines containing 3 integers: the identifier i (≤ n) of process pi
 the identifier j (≤ n) of the pj process and the communication cost cij. Since the matrix is ​​symmetric, cij = cji.

Output
 Integer representing the minimun cost

Exemple

input 1
4 4
6 4
5 10
10 3
4 8
1 2 5
2 3 6
2 4 2
3 4 1
output 1
24

Compilation
 g++ -std=c++11 -O3 -Wall file.cpp -lm