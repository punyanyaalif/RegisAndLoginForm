#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class temp{
    string Username, Email, Password;
    string SearchName, SearchPass, SearchEmail;
    fstream file;

    public :
        void Login();
        void SignUp();
        void ForgotPassword();
}obj;

void temp :: SignUp(){
    cout << "\nEnter username : " << endl;
    getline(cin,Username);
    cout << "Enter email : " << endl;
    getline(cin,Email);
    cout << "Enter password : " << endl;
    getline(cin,Password);

    file.open("userdatabase.txt", ios::out | ios::app);
    file << Username << "/" << Email << "/" << Password << endl;
    file.close();
}

void temp :: Login(){
    cout << "---Please enter your login credentials---\n";
    cout << "\nEnter username : " << endl;
    getline(cin,SearchName);
    cout << "Enter password : " << endl;
    getline(cin,SearchPass);

    file.open("userdatabase.txt", ios::in);
    getline(file,Username,'/');
    getline(file,Email,'/');
    getline(file,Password,'\n');

    while(!file.eof()){
        if(Username == SearchName){
            if(Password == SearchPass){
                cout << "\nAccout Login Successful..." << endl;
                cout << "Welcome back " << Username << endl;
                cout << "Your email : " << Email << " has been verified" << endl; 
            } else {
                cout << "Password is incorrect" << endl;
            }
        }
        getline(file,Username,'/');
        getline(file,Email,'/');
        getline(file,Password,'\n');
    }
    file.close();
}

void temp :: ForgotPassword(){
    cout << "\nEnter email : " << endl;
    getline(cin, SearchEmail);
    cout << "Enter username : " << endl;
    getline(cin,SearchName);

    file.open("userdatabase.txt", ios::in);
    getline(file,Username,'/');
    getline(file,Email,'/');
    getline(file,Password,'\n');

    while(!file.eof()){
        if(Username == SearchName){
            if(Email == SearchEmail){
                cout << "Your account username is : " << Username << endl;
                cout << "Your Password is : " << Password << endl;
            }
        } else {
            cout << "Account not found. Try signing up." << endl;
        }
        getline(file,Username,'/');
        getline(file,Email,'/');
        getline(file,Password,'\n');
    }
    file.close();
}