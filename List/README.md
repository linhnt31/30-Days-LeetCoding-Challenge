## Linked List
___
> **Linekd list** is a list which consist of a sequence of accessible nodes. It used to implement queues, stacks, lists,...

![](https://nguyenvanhieu.vn/wp-content/uploads/2018/12/data-node-danh-sach-lien-ket.png)

***Why would we not use an array instead of linked list ?***
##### 1. Pros
+ **A array** has a fixed size and must be alocated for the specified size. Meanwhile, **linked list** is a dynamic data strcuture, it allocate memory at runtime.
+ Appending a new item and inserting a new at a specifed position is expensive tasks for **array**

##### 2. Cons
+ If searching for an item, we cannot access elements by indexs like **array**. We must iterate through the entire list.
+ The use of pointers increases the use of memory usage.
+ Traversing lists ***in a reverse order*** can be more difficult than **traversing arrays**. This issue is relived by using **a doublely linked list** --> but the additional memory is required.

##### My issue
![](https://www.geeksforgeeks.org/wp-content/uploads/gq/2013/03/Linkedlist.png)

![]()

> When we declare a `Node *head` meaning head is a pointer that have **Node** type, point to the first Node and can access data and pointer next of the first Node.
## References
[Overview](https://medium.com/@hitherejoe/data-structures-linked-list-e518261e7fe9)
