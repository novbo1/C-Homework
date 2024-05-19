#include "Security.h"

int Security::validate(string username, string password) 
{
    if ((username == "abbott") && (password == "monday")) return 2; // Valid administrator
    if ((username == "costello") && (password == "tuesday")) return 1; // Valid user
    return 0; // Invalid credentials
}
