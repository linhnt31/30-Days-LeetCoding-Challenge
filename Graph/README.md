### Graph
___
Graphs are commonly represented in 2 ways:
#### 1. Adjacency matrix
> An adjacency matrix is a 2D array of VxV vertices. Each row and column represent a vertex.
It is  an undirected graph so elements of this matrix are symmetric about the diagonal.

![](https://cdn.programiz.com/sites/tutorial2program/files/adjacency-matrix_0.png)
##### 1.1. Pros
Edge lookup is extremely fast.
Removing an edge takes O(1) time.
##### 1.2. Cons
Because we have to reserve space for every possible link between all vertices (VxV) ---> it requires more space O(V^2)
Adding a vertex is O(V^2) time

#### 2. Adjacency List
> An adjacency list represents a graph as an array of linked lists.

##### 1.1. Pros
Saves space O(|v| + |E|)
Adding a vertex is easier
##### 1.2. Cons
Queries like whether there is an edge from vertex u to vertex v are not efficient (O(V))
##### 1.3. Applications
- Creating routing table in networks
![](https://cdn.programiz.com/sites/tutorial2program/files/adjacency-list.png)

#### 3. Graph operations
- Check if the element is present in the graph
- Traversing graph
- Add elements(vertices, edges) to graph
- Finding the path from one vertex to another.

### References
https://www.programiz.com/dsa/graph
