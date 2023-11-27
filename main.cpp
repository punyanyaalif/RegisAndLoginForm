#include <iostream>
#include "temp.h"

using namespace std;

int main(){
    char choice;
    cout << "Welcome to Login Page\n";
    cout << "1. Login\n";
    cout << "2. Sign Up\n";
    cout << "3. Forgot Password\n";
    cout << "4. Exit\n";
    cout << "Select number only : ";
    cin >> choice;

    switch(choice){
        case '1':
            cin.ignore();
            obj.Login();
        break;
        case '2':
            cin.ignore();
            obj.SignUp();
        break;
        case '3':
            cin.ignore();
            obj.ForgotPassword();
        break;
        case '4':
            return 0;
        break;
        default:
            cout << "Invalid input!" << endl;
    }
}