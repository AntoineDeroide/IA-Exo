#include <iostream>


// [1]
int ConvertToFahrenheit(int celsius_temperature) {

	return ((celsius_temperature * 9) / 5 + 32);

}

// [2]
bool IsPair(int number) {
	if (number > 0) {
		int residue = number % 2;
		if (residue != 0) {
			std::cout << "Le nombre est impair" << std::endl;
			return false;
		}
		else {
			std::cout << "Le nombre est pair" << std::endl;
			return true;
		}
	}
}

// [3]
int FindHighestInt(int array[], int size) {

	int highest = 0;

	for (int i = 0; i < size; i++) {

		if (array[i] > highest)
			highest = array[i];
	}
	std::cout << "Le nombre le plus grand est " << highest << '\n';
	return highest;
}

// [4]
void GetMultiplyTable(int value) {

	for (int i = 1; i <= 10; i++) {
		std::cout << i << " x " << value << " = " << i * value << std::endl;
	}
}

// []


int main(void) {
	// [1]
	/*int value;

	std::cout << "Entrez une température en degrés Celsius : ";
	std::cin >> value;

	std::cout << "\n" << ConvertToFahrenheit(value) << std::endl;*/

	// [2]
	/*int value;
	std::cout << "Entrez un nombre entier : ";
	std::cin >> value;

	IsPair(value);*/

	// [3]
	/*static const int size = 3;
	int iArray[size];
	for (int i = 0; i < size; i++) {
		int toAdd;
		std::cout << "Entrez un nombre entier :";
		std::cin >> toAdd;
		std::cout << '\n';
		iArray[i] = toAdd;
	}
	FindHighestInt(iArray, size);*/

	// [4]
	/*int value;
	std::cout << "Entrez un nombre entier :";
	std::cin >> value;
	GetMultiplyTable(value);*/

	// []
	
}