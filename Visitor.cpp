#include <iostream>

using namespace std;

class Visitor;

class Element {
public:
    virtual void accept(Visitor& visitor) = 0;
};

class ConcreteElementA : public Element {
public:
    void accept(Visitor& visitor) override;

    void operationA() {
        cout << "ConcreteElementA operationA" << endl;
    }
};

class ConcreteElementB : public Element {
public:
    void accept(Visitor& visitor) override;

    void operationB() {
        cout << "ConcreteElementB operationB" << endl;
    }
};

class Visitor {
public:
    virtual void visitConcreteElementA(ConcreteElementA& elementA) = 0;
    virtual void visitConcreteElementB(ConcreteElementB& elementB) = 0;
};

class ConcreteVisitor : public Visitor {
public:
    void visitConcreteElementA(ConcreteElementA& elementA) override {
        elementA.operationA();
    }

    void visitConcreteElementB(ConcreteElementB& elementB) override {
        elementB.operationB();
    }
};

void ConcreteElementA::accept(Visitor& visitor) {
    visitor.visitConcreteElementA(*this);
}

void ConcreteElementB::accept(Visitor& visitor) {
    visitor.visitConcreteElementB(*this);
}

int main() {
    ConcreteElementA elementA;
    ConcreteElementB elementB;

    ConcreteVisitor visitor;

    elementA.accept(visitor);
    elementB.accept(visitor);

    return 0;
}
