#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char buff;
    int err = 0;
    int open = 0;
    fstream wr;
    wr.open("index.html", ios::in | ios::out | ios::app);

    while (!wr.eof())
    {
        wr.get(buff);
        cout << buff;
        if (open == 0 && buff == '>')
        {
            err++;
        }
        if (buff == '<')
        {
            open++;
        }
        if (open > 0 && buff == '>')
        {
            open--;
        }
    }
    err += open;
    cout << "error count: " << err;
}