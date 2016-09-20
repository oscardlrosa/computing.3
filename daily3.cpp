#include <iostream>
using namespace std;

const float ZERODEG_CELSIUS_IN_KELVIN = 273.15;
const float FAHRENHEIT_TO_KELVIN = 459.67;
const int ZERODEG_CELSIUS_IN_FAHRENHEIT = 32;

class Temperature {
public:
  //Accesors
  float get_temp_kelvin();
  float get_temp_fahrenheit();
  float get_temp_celsius();
  //Mutators
  void set_temp_kelvin();
  void set_temp_fahrenheit();
  void set_temp_celsius();

private:
  float temperatureInKelvin;
};

int main() {
  Temperature today;
  int input;

  cout << "Which temperature would you like to enter? " << endl;
  cout << "1. Kelvin  | 2. Fahrenheit | 3. Celsius" << endl;

  do {
    cout << "Please enter your selection: ";
    cin >> input;
  } while(input < 1 || input > 4);

  switch (input) {
    case 1:
      today.set_temp_kelvin();
      break;
    case 2:
      today.set_temp_fahrenheit();
      break;
    case 3:
      today.set_temp_celsius();
      break;
    default:
      cout << "That's not a choice. Quitting now..." << endl;
  }

  cout << "This is the temperature in Kelvin: " << today.get_temp_kelvin() << endl;
  cout << "This is the temperature in Fahrenheit: " << today.get_temp_fahrenheit() << endl;
  cout << "This is the temperature in Celsius: " << today.get_temp_celsius() << endl;

  return 0;
}

//Accessors
float Temperature::get_temp_kelvin() {
  return temperatureInKelvin;
}

float Temperature::get_temp_fahrenheit() {
  return (9.0/5.0) * get_temp_celsius() + ZERODEG_CELSIUS_IN_FAHRENHEIT;
}

float Temperature::get_temp_celsius() {
  return temperatureInKelvin - ZERODEG_CELSIUS_IN_KELVIN;
}

void Temperature::set_temp_kelvin() {
  float inputTemperature;
  cout << "Please, enter the desired temperature in Kelvin degrees: ";
  cin >> inputTemperature;
  temperatureInKelvin = inputTemperature;
}

void Temperature::set_temp_fahrenheit() {
  float inputTemperature;
  cout << "Please, enter the desired temperature in Fahrenheit degrees: ";
  cin >> inputTemperature;
  temperatureInKelvin = (5.0/9.0) * (inputTemperature + FAHRENHEIT_TO_KELVIN);
}

void Temperature::set_temp_celsius() {
  float inputTemperature;
  cout << "Please, enter the desired temperature in Celsius degrees: ";
  cin >> inputTemperature;
  temperatureInKelvin = inputTemperature + ZERODEG_CELSIUS_IN_KELVIN;
}
