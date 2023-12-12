#include<iostream>
using namespace std;

// Forward Declaration for the add class
class add;

class Distance {
private:
    int meter;

public:
    int getMeter() {
        return meter;
    }

    Distance(int meter) {
        this->meter = meter;
    }

    // Declare addFive function
    friend int add::addFive(Distance d);
};

// Define the add class
class add {
public:
    // Define the addFive function
    int addFive(Distance d) {
        return d.meter + 5;
    }
};

int main() {
    // Your main program logic goes here
    return 0;
}
