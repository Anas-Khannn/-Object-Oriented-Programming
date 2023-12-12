#include <iostream>
using namespace std;

class shape
{
public:
    virtual void Draw() = 0;
};

class Rectangle : public shape
{
    int length;
    int width;

public:
    void Draw()
    {
        cout << "we are drawing rectangle" << endl;
    }
};

class circle : public shape
{
    int radius;

public:
    void Draw()
    {
        cout << "we are drawing Circle" << endl;
    }
};

void drawAll(shape *s[])
{
    for (int i = 0; i < 2; i++)
    {
        s[i]->Draw();
    }
}

int main()
{
    shape *s[2];
    s[0] = new Rectangle();
    s[1] = new circle();

    cout << "Drawing Rectangle and Circle in Main" << endl;

    for (int i = 0; i < 2; i++)
    {
        s[i]->Draw();
    }

    drawAll(s);

    // Remember to free the allocated memory
    for (int i = 0; i < 2; i++)
    {
        delete s[i];
    }

    return 0;
}
