#include "Subject.h"

void Subject::attach(Observer* obs) {
    observers.push_back(obs);
}

void Subject::detach(Observer* obs) {
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        if (*it == obs) {
            observers.erase(it);
            break;
        }
    }
}

void Subject::notifyObservers() {
    for (Observer* observer : observers) {
        observer->update(*this);
    }
}
