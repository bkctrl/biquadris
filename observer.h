#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;  // Forward declaration to resolve circular dependency

class Observer {
public:
    virtual void update(Subject& subject) = 0; // Pass the Subject that is calling the update
    virtual ~Observer() = default; // Destructor will change based on the derived class
};

#endif // OBSERVER_H
