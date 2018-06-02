#include <iostream>
#include <map>
#include <algorithm>

#include "Global.h"
#include "Context.h"
#include "SearchTree.h"

using namespace std;

int main()
{
    cout << "Please input color (-1 for White, 1 for Black): " << endl;
    int color;
    cin >> color;
    Context context(color);

};
