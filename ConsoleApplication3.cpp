#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Person
{
    string Name;
    string Family;
};

int main()
{
    string path = "C:\\programming\\ooo.txt";

    ifstream file;
    file.open(path);

    if (!file.is_open())
    {
        cout << "File could not be opened" << endl;
        return -1;
    }

    string line;
    while (getline(file, line))
    {
        int pos = line.find('|');
        Person person;
        person.Family = line.substr(0, pos);
        person.Name = line.substr(pos + 1);

        string path2 = "C:\\programming\\eee.txt";

        ofstream file2;
        file2.open(path2, ios::app);

        if (file2.is_open())
           {
            file2 << person.Family << endl;
            file2.close();
           }
        
    }
    file.close();

    return 0;
    
}

