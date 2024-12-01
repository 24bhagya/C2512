#include <iostream>
#include <string>
#include "Surgery.h"

using std::cout;
using std::endl;

int main()
{
    Surgery surgery1("S001", 90);
    Surgery surgery2("S002", 120);

    std::cout << std::boolalpha;

    cout << "Equals:" << surgery1.Equals(surgery2) << endl;
    cout << "Not equals:" << surgery1.NotEquals(surgery2) << endl;
    cout << "Greater than:" << surgery1.GreaterThan(surgery2) << endl;
    cout << "Greater than or equals:" << surgery1.GreaterThanEquals(surgery2) << endl;
    cout << "Less than:" << surgery1.LessThan(surgery2) << endl;
    cout << "Less than or equals:" << surgery1.LessThanEquals(surgery2) << endl;

    return 0;
}
