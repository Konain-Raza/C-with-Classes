#include <iostream>
#include <string>

using namespace std;

int main() {
    int number;
    cout << "Enter a Number: ";
    cin >> number;

    string roman;

    const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const string numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	if(number>0){
	
    for (int i = 0; i < 13; ++i) {
        while (number >= values[i]) {
            roman += numerals[i];
            number -= values[i];
        }
    }

    cout << "Roman numeral: " << roman << endl;
}
else{
	cout<< "Negative numbers are not allowed."<<endl;
}
    return 0;
}

