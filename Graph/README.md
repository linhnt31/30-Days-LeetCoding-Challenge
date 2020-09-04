# Graph
___
### 1. Overview
![](https://www.geeksforgeeks.org/wp-content/uploads/undirectedgraph.png) 

\- G=<V,E>
+ V is a collection of vertices V = {1,2,3,...n}
+ E is a collection of edge

### 2. Features2
Graphs are commonly represented in 2 ways:
#### 2.1. Adjacency matrix
> An adjacency matrix is a 2D array of VxV vertices. Each row and column represent a vertex.
It is  an undirected graph so elements of this matrix are symmetric about the diagonal.

![](https://cdn.programiz.com/sites/tutorial2program/files/adjacency-matrix_0.png)
###### a. Pros
\- Edge lookup is extremely fast by comparing G[u][v] to 0 or 1.

\- Removing an edge takes O(1) time.
###### b. Cons
\- Because we have to reserve space for every possible link between all vertices (VxV) ---> it requires more space O(V^2)
Adding a vertex is O(V^2) time.

\- We can't implement it with a great number of vertices 

#### 2.2. Adjacency List
> An adjacency list represents a graph as an array of linked lists.

###### a. Pros
\- Saves space O(|v| + |E|)

\- Adding a vertex is easier
###### b. Cons
\- Queries like whether there is an edge from vertex u to vertex v are not efficient (O(V))

###### c. Applications
\- Creating routing table in networks
![](https://cdn.programiz.com/sites/tutorial2program/files/adjacency-list.png)

#### 2.3. Graph operations
\- Check if the element is present in the graph

\- Traversing graph

\- Add elements(vertices, edges) to graph

\- Finding the path from one vertex to another.

### References
+ https://www.programiz.com/dsa/graph
