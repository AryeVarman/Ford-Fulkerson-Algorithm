# Ford-Fulkerson-Algorithm
Solution to the max flow problem using Ford Fulkerson algorithm, Path search algorithms are BFS and greedy path search (dijkstra version).
coded by myself for Algorithms course.


HOW TO RUN:
===========
This is a program that finds maximal flow from node s to node t in a graph.
the graph definition given via text file and the text file name is given as a parameter to the main function.
the text file format should be as followed:
1) the text file should contain only digits, white spaces (spaces Tabs and 'Enters')
and a decimals point, the decimals point are allowed only as part of a real number.
2) real number is in the formt of x.y or x when x and y is natural numbers.
3) negative are not allowed.
4) for as long as the program concern the file ends either if it has no more data in it or if the program read the data it needed
(e.g. the number of edges the file sais it has) if the file has more data the program disregard it.
5) every data can be seperated with as much white spaces as wanted and as long as it seperated with at least one space, Tab or 'Enter'
7) first in the file should be a nutural number that represent the number of nodes in the graph (called N).
8) second in the file should be a natural number that represent the number of edges that are given in the file (called M).
9) third in the file should be a natural number that represent the source in the graph.
10) fourth in the file should be a natural number that represent the sink in the graph.
11) now, the file should have M trios that represent the edges as followed:
11.1) each trio is in the order of: source, destenation, weight.
11.2) source and destenation are natural number limited by N.
11.3) weight is a positive real number.
11.4) edge data can be seperated with as much white spaces as wanted as long as is sepereted with at least one
white space (space Tab or 'Enter').
11.5) parallel edges are not allowed and fail the program
11.6) loop edges are not allowed and fail the program.

*** AN EXAMPLE FOR A LEGAL INPUT FILE IS: "input1.txt" ***
