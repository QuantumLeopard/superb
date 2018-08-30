# superb
Superpermutation Generator

The goal of this project is to develop a flexible superpermutation generator that allows for a choice of n at runtime, as well as a choice of algorithm, to explore the runtime and mathematical properties of each.

<h2>What is a Superpermutation</h2>

[Wikipedia Article](https://en.wikipedia.org/wiki/Superpermutation/)

Superpermutations are strings that contain all the permutations of n symbols as substrings.  It was previously conjectured (and verified for n<=5) that the minimum length for a superpermtation of n symbols was described by:
\sum_{i=1}^{n}i!

![img](http://latex.codecogs.com/svg.latex?%5Csum_%7Bi%3D1%7D%5E%7Bn%7Di%21)

A superpermutation of length:

![img](http://latex.codecogs.com/svg.latex?%28%5Csum_%7Bi%3D1%7D%5E%7Bn%7Di%21%29-1) 

for n=6 was discovered in 2014 ([Tackling the Minimal Superpermutation Problem
](https://arxiv.org/abs/1408.5108/)).  This is a counter example to the conjecture of the general case, but a minimum as yet has not been found.

<h2>Challenges and Planned Work</h2>

The contruction of superpermutations is easily described as a [traveling salesman problem](https://en.wikipedia.org/wiki/Travelling_salesman_problem/).  Each permutation is a vertex in a graph.  Edges are directed and weighted, where the tail of the edge comes from the vertex whose permutation appears first in the superpermutation and the head points to the vertex whose permutation appears next in the superpermutation.  Weights are n-o, where o is the number of symbols that the end of the tail vertex could overlap the begin of the head vertex.  For example:
`````
           3
        <-----      
   12345      45123
        ----->
          2
 `````
This is a computationally expensive problem to solve for the shortest path that visits all vertices (by brute force).  Many algorithms do not attempt to find the shorest path, but rather offer a ceiling or average distance that is acceptable for an application, while providing a solution in a reasonable amount of time.
       
<h3>Planned Work</h3>

- [x] Recursive Node Generation

- [ ] Loop Node Generation

- [ ] Greedy Solution

- [ ] Brute Force Exhaustive Soution

- [ ] [Chirstofides Solution](https://en.wikipedia.org/wiki/Christofides_algorithm/)

- [ ] Python/Tkinter gui

- [ ] Julia Benchmark


<h2>Results</h2>

The current test machine is running an AMD Ryzen 3 1200 on a B350 motherboard, with no overclocking, and running Ubuntu 17.10.

**_These are preliminary results to facilitate further development and are not conducted in a rigorous fashion._**

<h3>Recursive Node Generation Time</h3>

| n  |  ms  | ms (dl refactor) |
|----|------|------------------|
|1   |.012  | .018             |
|2   |.027  | .022             |
|3   |.037  | .041             |
|4   |.072  | .076             |
|5   |.219  | .244             |
|6   |1.116 | 1.297            |
|7   |6.29  | 9.417            |
|8   |34.028| 40.64            |
|9   |285.798| 371.041         |
|10  |3244.45| 4034.51         |
