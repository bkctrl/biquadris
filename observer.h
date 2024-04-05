#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
public:
    virtual void notify(Cell& c) = 0; // Pass the Cell that is calling the update
    virtual ~Observer() = default; // Destructor will change based on the derived class
};

#endif // OBSERVER_H
