#include <iostream>
#include <exception>

using namespace std;  // Add this line to use the std namespace

class Population {
 private:
  int population;
  int births;
  int deaths;

 public:
  Population(int population, int births, int deaths) {
    if (population < 1 || births < 0 || deaths < 0) {
      throw invalid_argument("Invalid population figures");
    }
    this->population = population;
    this->births = births;
    this->deaths = deaths;
  }

  int get_population() const { return population; }
  int get_births() const { return births; }
  int get_deaths() const { return deaths; }

  double get_birth_rate() const {
    return static_cast<double>(births) / population;
  }

  double get_death_rate() const {
    return static_cast<double>(deaths) / population;
  }
};

int main() {
  int inputPopulation, inputBirths, inputDeaths;

  cout << "Enter the population: ";
  cin >> inputPopulation;

  cout << "Enter the number of births: ";
  cin >> inputBirths;

  cout << "Enter the number of deaths: ";
  cin >> inputDeaths;

  try {
    Population myPopulation(inputPopulation, inputBirths, inputDeaths);

    double birth_rate = myPopulation.get_birth_rate();
    double death_rate = myPopulation.get_death_rate();

    cout << "Birth rate: " << birth_rate << endl;
    cout << "Death rate: " << death_rate << endl;
  } catch (invalid_argument& e) {
    cout << e.what() << endl;
  }

  return 0;
}
