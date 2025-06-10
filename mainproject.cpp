#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>  //for system()
using namespace std;

struct salesdata
{
    int year;
    int revenue;
    int expenses;
}data;

void writedata()
{
    fstream file("data.txt", ios::app);
    if (!file.is_open()) 
    {
        cout << "\nError opening file!\n";
        return;
    }

    while (1)
    {
        char ans;
        cout << "Enter year: ";
        cin >> data.year;

        cout << "Enter revenue: ";
        cin >> data.revenue;

        cout << "Enter expenses: ";
        cin >> data.expenses;

        file << data.year << " " << data.revenue << " " << data.expenses << endl;

        cout << "\nData entered successfully!\n";

        while (true)
        {
            cout << "\nDo you want to enter more data? (y/n): ";
            cin >> ans;
            if (ans == 'n' || ans == 'N') 
            {
                file.close();
                return;
            }
            else if (ans == 'y' || ans == 'Y') 
            {
                break;
            }
            else 
            {
                cout << "\nInvalid input! Please enter 'y' or 'n'.\n";
            }
        }  
    }
    file.close();
}

void readdata()
{
    fstream file("data.txt");
    if (!file.is_open()) 
    {
        cout << "\nError opening file!\n";
        return;
    }

    while (file >> data.year >> data.revenue >> data.expenses) 
    {
        cout << "Year: " << data.year << ", Revenue: " << data.revenue << ", Expenses: " << data.expenses << endl;
    }
    file.close();
}

void searchdata(int key)
{
    int found = 1;

    fstream file("data.txt");
    if (!file.is_open())
    {
        cout << "\nError opening file!\n";
        return;
    }
    
    while (file >> data.year >> data.revenue >> data.expenses)
    {
        if (data.year == key)
        {
            cout << "\nData found for year: " << key << ":\n";
            cout << "Year: " << data.year << ", Revenue: " << data.revenue << ", Expenses: " << data.expenses << endl;
            found = 0;
            break;
        }
    }
    if (found == 1)
    {
        cout << "\nData not found for year: " << key << endl;
    }
    file.close();
}

void deletedata(int key)
{
    int found = 0;

    fstream file("data.txt");
    if (!file.is_open())
    {
        cout << "\nError opening file!\n";
        return;
    }
    
    ofstream temp("tempdata.txt");
    if (!temp.is_open())
    {
        cout << "\nError opening temp file!\n";
        file.close();
        return;
    }

    while (file >> data.year >> data.revenue >> data.expenses)
    {
        if (data.year == key)
        {
            cout << "\n" << "Data deleted for year: " << key << endl;
            found = 1;
        }
        else
        {
            temp << data.year << " " << data.revenue << " " << data.expenses << endl;
        }
    }

    file.close();
    temp.close();

    if (found == 0)
    {
        cout << "\nData not found for year: " << key << endl;
        remove("tempdata.txt");
        return;
    }

    if (found == 1)
    {
        remove("data.txt");
        rename("tempdata.txt", "data.txt");
    }
}

void plotdata()
{
    cout << "\n" << "Plotting data...\n";
    system("python plotting.py");
}

void analysis()
{
    cout << "\n" << "Performing data analysis...\n";
    system("python analysis.py");
}

int main() 
{
    int ch, key;
    while (true) 
    {
        cout << "\nMenu:\n1. Write Data\n2. Read Data\n3. Search Data\n4. Delete Data\n5. Plot Data\n6. Data Analysis\n7. Exit\nEnter your choice: ";
        cin >> ch;

        switch (ch) 
        {
            case 1:
                writedata();
                break;
            case 2:
                cout << "\nReading data...\n";
                readdata();
                break;
            case 3:
                cout << "\nEnter year to search: ";
                cin >> key;
                searchdata(key);
                break;
            case 4:
                cout << "\nEnter year to delete: ";
                cin >> key;
                deletedata(key);
                break;
            case 5:
                plotdata();
                break;
            case 6:
                analysis();
                break;
            case 7:
                cout << "\nExiting...\n";
                return 0;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    }

    return 0;
}
