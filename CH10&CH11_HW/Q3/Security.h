#ifndef SECURITY_H
#define SECURITY_H

#include <string>
using namespace std;

class Security 
{
public:
    static int validate(string username, string password);
};

#endif // SECURITY_H