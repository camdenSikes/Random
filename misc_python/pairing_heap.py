"""
An implementation of a pairing heap, because I was curious
"""
class Pairing_heap:
    # If want decrease-key functionality, could add parent
    def __init__(self, value = None, children = None, parent = None):
        """
        :param value: The value of the root of the heap
        :param children: A list of pairing heaps representing the children of the root
        :param parent: The parent of the heap
        """
        self.value = value
        self.children = []
        if(children != None):
            self.add_children(children)
        self.parent = parent

    def copy(self):
        return pairing_heap(self.value, self.children,self.parent)

    def add_children(self, children):
        for child in children:
            child.set_parent(self)
        self.children.extend(children)

    def add_parent(self, parent):
        """
        Sets heap to be the parent of the heap
        """
        self.parent = parent

    def find_min(self):
        """
        :return: The minimum value in the heap
        """
        return self.value

    def merge(self,heap):
        """
        merges the provided heap into the current heap
        """
        if heap.value == None:
            return
        elif self.value == None:
            self.value = heap.value
            self.children = heap.children
            return
        elif self.value >= heap.value:
            self.children.append(heap)
            heap.add_parent(self)
        else:
            oldroot = self.copy()
            heap.children.append(oldroot)
            oldroot.add_parent(heap)
            self.value = heap.value
            self.children = []
            self.add_children(heap.children)

    def insert(self, value):
        """
        Adds value to the heap
        """
        self.merge(Pairing_heap(value))

    def delete_min(self):
        """
        Removes the minimum value from the heap
        """
        if(self.value == None):
            raise KeyError('Heap is empty')
        children = self.children.copy()
        self.value = children[0].value
        self.children = []
        self.add_children(children[0].children)
        self.merge_pairs(children[1:])

    def merge_pairs(self, heaps):
        if len(heaps) == 0:
            return
        else:
            self.merge(heaps[0])
            self.merge_pairs(heaps[1:])

    def decrease_key(self,curval,newval):
        """
        decrease an instance of curval with newval
        """
        assert curval > newval
        # find it
        # move it to new heap (make its parent forget)
        # adjust value
        # merge