#include <iostream>
using namespace std;

// Static Linkage Concept:
/*/* In C++, static linkage refers to the resolution of functions and variables during compile-time.
The 'static' keyword is used to declare entities with static linkage, and such entities are limited in visibility to the translation unit (source file)
 where they are defined. This encapsulation ensures that they are not accessible from other source files,
 providing a level of privacy and modularity within the program.*/

static int staticVariable = 10;

static void staticFunction()
{
    cout << "Static Function" << endl;
}

// Dynamic Linkage Concept:
/*Dynamic Linkage is a concept in software engineering where a program is linked with another program or library at runtime.
 This means that the final linking of the code takes place during the execution of the program, 
 as opposed to static linking where all the linking is done before the program is run.*/

int dynamicVariable = 20;
void dynamicFunction()
{
    cout << "Dynamic Function" << endl;
}

int main()
{
    // Static Linkage Example:
    scout << "Static Variable: " << staticVariable << endl;
    staticFunction();

    // Dynamic Linkage Example:
    cout << "Dynamic Variable: " << dynamicVariable << endl;
    dynamicFunction();

    return 0;
}
