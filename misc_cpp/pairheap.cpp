#include <iostream>

class PairHeap{
    //What do we do when it's empty?
    int val;
    //To find all children, go to first child and iterate through siblings until
    //none are left
    PairHeap * firstChild;
    PairHeap * sibling;
    //not sure if I'll use this
    PairHeap * parent;
public:
    int getVal();
    void addChild(PairHeap heap);
    void addSibling(PairHeap heap);
};

int PairHeap::getVal(){
    return val;
}

//Make your child add a sibling
void PairHeap::addChild(PairHeap heap) {
    firstChild->addSibling(heap);
}

//If you don't point to a sibling, add this
//otherwise make your sibling do it.
void PairHeap::addSibling(PairHeap heap) {
    sibling == nullptr ? sibling = &heap : sibling->addSibling(heap);
}

int findMin(PairHeap heap){
    return heap.getVal();
}

PairHeap merge(PairHeap h1, PairHeap h2){
    //TODO: deal with one being empty
    (h1.getVal() > h2.getVal()) ? h1.addChild(h2) : h2.addChild(h1);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}