#include <iostream>
#include "Administrator.h"
#include "User.h"
using namespace std;

int main() {
    Administrator admin;
    User user;

    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (admin.login(username, password)) {
        cout << "Administrator login successful." << endl;
    }
    else {
        cout << "Administrator login failed." << endl;
    }

    if (user.login(username, password)) {
        cout << "User login successful." << endl;
    }
    else {
        cout << "User login failed." << endl;
    }

    return 0;
}
