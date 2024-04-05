#ifndef SUBJECT_H
#define SUBJECT_H

#include "observer.h"
#include <vector>

class Subject {
    std::vector<Observer*> observers;
public:
    void attach(Observer *o); // Attach an observer
    void detach(Observer *o); // Detach an observer
    void notifyObservers(); // Notify only the attached observers of a change in this cell
    virtual ~Subject() = default;
};

#endif // SUBJECT_H 
