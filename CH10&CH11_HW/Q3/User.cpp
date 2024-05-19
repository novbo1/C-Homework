#include "User.h"
#include "Security.h"

bool User::login(string username, string password) {
    int clearance = Security::validate(username, password);
    return (clearance == 1 || clearance == 2);
}