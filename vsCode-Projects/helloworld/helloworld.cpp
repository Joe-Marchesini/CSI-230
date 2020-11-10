#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!", "running on Joe's PopOS!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}