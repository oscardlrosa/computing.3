#include <iostream>
#include <cmath>
using namespace std;

#define METERS_IN_A_FOOT 0.3048
#define INCHES_IN_A_FOOT 12
#define CENTIMETERS_IN_A_METER 100
#define CENTIMETERS_IN_AN_INCH 2.54

void take_input(int& lengthFeet, double& lengthInches);
void calculate(int lengthFeet, double lengthInches, int& lengthMeters, double& lengthCentimeters);
void display(int lengthFeet, double lengthInches, int lengthMeters, double lengthCentimeters);

int main()
{
  int feetGivenByUser = 0, convertedToMeters = 0;
  double inchesGivenByUser = 0, convertedToCentimeters = 0;

  take_input(feetGivenByUser, inchesGivenByUser);

  calculate(feetGivenByUser, inchesGivenByUser, convertedToMeters, convertedToCentimeters);

  display(feetGivenByUser, inchesGivenByUser, convertedToMeters, convertedToCentimeters);

  return 0;
}

void take_input(int& lengthFeet, double& lengthInches)
{
  cout << "Please enter the number of feet  : ";
  cin >> lengthFeet;
  cout << "Please enter the number of inches  : ";
  cin >> lengthInches;
}

void calculate(int lengthFeet, double lengthInches, int& lengthMeters, double& lengthCentimeters)
{
  double fractPortion, intPortion, tempConversionMeters, tempConversionCentimeters;

  tempConversionMeters = lengthFeet * METERS_IN_A_FOOT;
  fractPortion = modf(tempConversionMeters, &intPortion);
  fractPortion *= CENTIMETERS_IN_A_METER;
  lengthMeters = intPortion;

  tempConversionCentimeters = lengthInches * CENTIMETERS_IN_AN_INCH + fractPortion;

  if(tempConversionCentimeters >= CENTIMETERS_IN_A_METER)
  {
    fractPortion = modf(tempConversionCentimeters, &intPortion);
    tempConversionMeters = intPortion / CENTIMETERS_IN_A_METER;
    lengthMeters += tempConversionMeters;
    lengthCentimeters += fractPortion;
  }
  else
  {
      lengthCentimeters = tempConversionCentimeters;
  }
}

void display(int lengthFeet, double lengthInches, int lengthMeters, double lengthCentimeters)
{
  cout << lengthFeet << " feet and ";

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(8);
  cout << lengthInches << " inches converts to ";
  cout << lengthMeters << " meter and ";

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(8);
  cout << lengthCentimeters << " centimeters" << endl;
}
