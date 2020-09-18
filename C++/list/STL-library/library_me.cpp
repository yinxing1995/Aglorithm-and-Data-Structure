#include<iostream>
#include<characters.h>

using namespace std;

int menu()
{
    int option;
    cout << "\nEnter one of the following options:\n"
         << "1. Include a book in the catalog\n2. Check out a book\n"
         << "3. Return a book\n4. Status\n5. Exit\n"
         << "Your option? ";
    cin >> option;
    while(cin.get()!='\n');
    return option;
}

int main()
{
    while(1)
    {
        switch (menu())
        {
            case 1: cout << "option = includeBook" << endl;
                    includeBook();
                    break;

            case 2: cout << "option = checkOutBook" << endl;
                    checkOutBook();
                    break;

            case 3: cout << "option = returnBook" << endl;
                    returnBook();
                    break;

            case 4: cout << "option = status" << endl;
                    status();
                    break;

            case 5: cout << "option = nothing" << endl;
                    return 0;

            default: cout << "Wrong option, try again: ";
        }
    }
    cout << "fail" << endl;
    system("pause");
    return 0;
}
