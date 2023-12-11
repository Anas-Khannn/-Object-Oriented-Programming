#include <iostream>
using namespace std;

class Robot
{
protected:
    double SerialNumber;
    string name;
    double YearManufactured;

public:
    // Constructor with parameters
    Robot(double serialNumber, string robotName, double yearManufactured)
        : SerialNumber(serialNumber), name(robotName), YearManufactured(yearManufactured) {}

    // Virtual destructor
    virtual ~Robot() {}

    // Virtual sound function
    virtual void sound() const = 0;

    // Getter methods
    double getSerialNumber() const
    {
        return SerialNumber;
    }

    string getName() const
    {
        return name;
    }

    double getYearManufactured() const
    {
        return YearManufactured;
    }
};

class BasicRobot : public Robot
{
public:
    // Overloaded constructor
    BasicRobot(double serialNumber, string robotName, double yearManufactured)
        : Robot(serialNumber, robotName, yearManufactured) {}

    // Implementation of sound function for BasicRobot
    void sound() const override
    {
        cout << "BasicRobot1 emits a beeping sound." << endl;
    }
};

class AdvancedRobot : public Robot
{
public:
    // Overloaded constructor
    AdvancedRobot(double serialNumber, string robotName, double yearManufactured)
        : Robot(serialNumber, robotName, yearManufactured) {}

    // Implementation of sound function for AdvancedRobot
    void sound() const override
    {
        cout << "AdvancedRobot1 generates a complex sound." << endl;
    }
};

int main()
{
    // Use static array instead of vector
    const int numRobots = 2;
    Robot *robots[numRobots];

    // Create instances of BasicRobot and AdvancedRobot
    robots[0] = new BasicRobot(1, "BasicRobot1", 2020);
    robots[1] = new AdvancedRobot(2, "AdvancedRobot1", 2022);

    // Iterate through the array and call the sound function for each robot
    for (int i = 0; i < numRobots; ++i)
    {
        cout << "Robot Name: " << robots[i]->getName() << endl;
        cout << "Serial Number: " << robots[i]->getSerialNumber() << endl;
        cout << "Year Manufactured: " << robots[i]->getYearManufactured() << endl;
        robots[i]->sound();
        cout << "--------------------------\n";
    }

    // Cleanup: Delete dynamically allocated objects
    for (int i = 0; i < numRobots; ++i)
    {
        delete robots[i];
    }

    return 0;
}
