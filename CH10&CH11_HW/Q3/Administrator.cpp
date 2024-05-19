#include "Administrator.h"
#include "Security.h"

bool Administrator::login(string username, string password) {
    int clearance = Security::validate(username, password);
    return (clearance == 2);
}
