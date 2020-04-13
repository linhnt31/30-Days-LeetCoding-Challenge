# Ref: https://www.tutorialspoint.com/python_data_structure/python_linked_lists.htm

"""Linked-list
 - are not stored at a contiguous location != array
 - contains a lot of nodes
 - Each node stores : 'data' + 'link (pointer)'

 + Advantages over arrays
 . Dynamic size
 . Ease of insetion/deletion

 + Drawbacks
 . Random access is not allowed
 . Extra memory space

"""

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None 
        self.leng = 0

    def leng(self):
        pass

    def traverse(self):
        tmp = self.head
        if self.head == None:
            print("List is empty")
        while(tmp != None):
            print(tmp.data)
            tmp = tmp.next


    # Insert a new Node at beginning
    def insert_beggin(self, new_data):
        self.leng += 1
        newNode = Node(new_data)
        newNode.next = self.head
        self.head = newNode

    # Insert a new node at the end
    def insert_end(self, new_data):
        self.leng += 1
        newNode = Node(new_data)
        tmp = self.head 
        while(tmp.next != None):
            tmp = tmp.next 
        tmp.next = newNode
        newNode.next = None

    # Insert between 2 data nodes
    def insert_middle(self, middle_data, new_data):
        tmp = self.head
        newNode = Node(new_data)
        while tmp != None:
            if tmp.data == middle_data:
                break 
            else:
                tmp = tmp.next 
            if tmp == Node:
                print("This nodes doesn't exist")
                return 
        newNode.next = tmp.next 
        tmp.next = newNode

node1 = LinkedList()
node1.head = Node("Mon")

node2 = Node("Tue")
node3 = Node("Wed")
node4 = Node("Fri")
node1.head.next = node2
node2.next = node3
node3.next = node4
#print(node3.data)
#node1.traverse()

#node1.insert_beggin("Sun")
#print("New node data: {} and second node data: {}".format(node1.head.data, node1.head.next.data))

#node1.insert_end("Fri")

node1.insert_middle("Wed", "New Day")
node1.traverse()