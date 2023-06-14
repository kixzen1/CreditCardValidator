#include <iostream>
#include <string>

using namespace std;

bool isValidCC(const string& creditCardNumber) {
    // Luhn's algorithm - see docs
    int sum = 0;
    bool alternate = false;
    for (int i = creditCardNumber.length() - 1; i >= 0; i--) {
        int digit = creditCardNumber[i] - '0';
        if (alternate) {
            digit *= 2;
            if (digit > 9) {
                digit = (digit / 10) + (digit % 10);
            }
        }
        sum += digit;
        alternate = !alternate;
    }
    return (sum % 10 == 0);
}


int main() {
    string creditCardNumber;

    while(true) {
        cout << "Enter a CC Number: ";
        cin >> creditCardNumber;
    
        // Removing all ' ' and '-' from the string
        creditCardNumber.erase(remove(creditCardNumber.begin(), creditCardNumber.end(), ' '), creditCardNumber.end());
        creditCardNumber.erase(remove(creditCardNumber.begin(), creditCardNumber.end(), '-'), creditCardNumber.end());

    
        if (isValidCC(creditCardNumber)) {
            cout << "Credit Card is Verified.";
            cout << endl << endl;
            break;
        } else {
            cout << "Credit card is not Verified";
            cout << endl << endl;
        }
    }
  
    return 0;

}

