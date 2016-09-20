#include <iostream>
using namespace std;

int is_prime( int num );

int main()
{
	int startingNumber, endingNumber, totalSum = 0;

	cout << "Please enter a starting number: ";
	cin >> startingNumber;

	cout << "Please enter an ending number: ";
	cin >> endingNumber;

	while( startingNumber <= endingNumber ) {
		if( is_prime( startingNumber ) ) {
			cout << startingNumber << endl;
			totalSum += startingNumber;
			startingNumber++;
		}
		else
			startingNumber++;
    }

	cout << "The sum of all the numbers is: " << totalSum << endl;

	return 0;
}

int is_prime( int num )
{
    int i, flag = 1;
		if( num <= 1 ) {
			flag = 0;
			return flag;
		}
    for( i = 2; i <= num/2; ++i ) {
			if( num % i == 0 ) {
				flag = 0;
				break;
			}
    }
    return flag;
}
