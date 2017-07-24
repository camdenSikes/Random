#include <iostream>

class PairHeap{
    //What do we do when it's empty?
    int val;
    //To find all children, go to first child and iterate through siblings until
    //none are left
    PairHeap * firstChild;
public:
    void setVal(int val);

    PairHeap *getFirstChild() const;

    void setFirstChild(PairHeap *firstChild);

    PairHeap *getSibling() const;

    void setSibling(PairHeap *sibling);

    PairHeap *getParent() const;

    void setParent(PairHeap *parent);

private:
    PairHeap * sibling;
    //not sure if I'll use this
    PairHeap * parent;
public:
    explicit PairHeap (int val);
    int getVal();

    void addChild(PairHeap heap);
    void addSibling(PairHeap heap);
};

PairHeap::PairHeap(int val) {
    this->val = val;
    parent = nullptr;
    sibling = nullptr;
    firstChild = nullptr;
}

int PairHeap::getVal(){
    return val;
}

void PairHeap::setVal(int val) {
    PairHeap::val = val;
}

PairHeap *PairHeap::getFirstChild() const {
    return firstChild;
}

void PairHeap::setFirstChild(PairHeap *firstChild) {
    PairHeap::firstChild = firstChild;
}

PairHeap *PairHeap::getSibling() const {
    return sibling;
}

void PairHeap::setSibling(PairHeap *sibling) {
    PairHeap::sibling = sibling;
}

PairHeap *PairHeap::getParent() const {
    return parent;
}

void PairHeap::setParent(PairHeap *parent) {
    PairHeap::parent = parent;
}

//Make your child add a sibling
void PairHeap::addChild(PairHeap heap) {
    heap.setParent(this);
    firstChild == nullptr ? firstChild = &heap : firstChild->addSibling(heap);
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

PairHeap insert(PairHeap heap, int val){
    PairHeap newHeap {val};
    return merge(heap, newHeap);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}