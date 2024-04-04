#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <vector>
class Cell;

class Subject {
    std::vector<Observer*> observers;
public:
    void attach(Observer *o); // Attach an observer
    void detach(Observer *o); 
    void notifyObservers(); // Notify only the attached observers of a change in this cell
    virtual ~Subject() = default;
};

#endif // SUBJECT_H 
