
#include <iostream>
#include <string>
using namespace std;

// Base class
class PetDataBase
{
private:
       // Variables
    string *petNames;
    int *petAge;
    string *petBreed;
    int capacity;
    int Size;

public:
    PetDataBase(int capacity) : capacity(capacity), Size(0)
    {
        petNames = new string[capacity];
        petAge = new int[capacity];
        petBreed = new string[capacity];
    }

    PetDataBase(const PetDataBase &other) : capacity(other.capacity), Size(other.Size)
    {
        petNames = new string[capacity];
        petAge = new int[capacity];
        petBreed = new string[capacity];

        for (int i = 0; i < Size; i++)
        {
            petNames[i] = other.petNames[i];
            petAge[i] = other.petAge[i];
            petBreed[i] = other.petBreed[i];
        }
    }

   // Function 
    void addPet(string name, int age, string breed)
    {
        if (Size < capacity)
        {
            petNames[Size] = name;
            petAge[Size] = age;
            petBreed[Size] = breed;
            Size++;
        }
        else
        {
            cout << "Error: Pet database is full!" << endl;
        }
    }

    void getPetInfo(string name)
    {
        bool found = false;

        for (int i = 0; i < Size; i++)
        {
            if (petNames[i] == name)
            {
                cout << "Pet Name: " << petNames[i] << endl;
                cout << "Pet Age: " << petAge[i] << endl;
                cout << "Pet Breed: " << petBreed[i] << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Error: No pet found with that name!" << endl;
        }
    }

    void listAllPets()
    {
        for (int i = 0; i < Size; i++)
        {
            cout << "Pet Name: " << petNames[i] << endl;
            cout << "Pet Age: " << petAge[i] << endl;
            cout << "Pet Breed: " << petBreed[i] << endl;
        }
    }

     // Destructors
    ~PetDataBase()
    {
        delete[] petNames;
        delete[] petAge;
        delete[] petBreed;
    }
};

int main()

// Sir Dogs Hm Nadiii Sataliii Breed Pata rata nishtaa yaw German Shippard by Name pigano
{
    PetDataBase petDatabaseList(3);

    cout << "------------ D A T A B A S E ------------------\n"
         << endl;

    petDatabaseList.addPet("Cutie-Pie", 3, "German Shippard");
    petDatabaseList.addPet("Khan ", 2, "German Shippard");
    petDatabaseList.addPet("LaLaa", 5, "German Shippard");

    cout << "------------------------------------------------\n"<< endl;

    petDatabaseList.getPetInfo("Cutie-Pie");
    petDatabaseList.getPetInfo("Khan");
    petDatabaseList.getPetInfo("LaLaa");

    cout << "------------------------------------------------\n" << endl;

     cout<<"------------- ALL List ----------------------\n"<<endl;

    petDatabaseList.listAllPets();

    return 0;
}
