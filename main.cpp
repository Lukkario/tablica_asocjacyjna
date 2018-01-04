#include "atable.hpp"
#include <iostream>
using namespace std;

int main()
{
atable a;
atableNNW b;
a["test"] = 10;
a["xd"] = 11;
b["TeST"] = 20;
cout << b["test"] << endl;
cout << a["xd"] << endl;
return 0;
}
