#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <string>
#include <unistd.h>
#include <dos.h>
#include <iomanip>
#include <regex>

using namespace std;

class Driver
{
    private:
        string name, licenseNum, contactNum, carModel;
        int carNum, numOfDays, referenceNum, carCapacity, carPrice, totalPrice;
    public:
        void menu();
        void addDriver();
        void checkReservation();
        void returnCar();
        void cancelReservation();
};

class welcome //welcome class
{
	public:
	int welcum()
	{
 ifstream in("logogo.txt"); //displaying welcome ASCII image text on output screen fn1353

  if(!in) {
    cout << "Cannot open input file.\n";
  }
  char str[1000];
  while(in) {
    in.getline(str, 1000);  // delim defaults to '\n' cp
    if(in) cout << str << endl;
  }
  in.close();
  sleep(1);
  cout<<"\n\t\t\t\t\t\t\t\t\tRevving cars engines....."<<endl;
  sleep(1);
  cout<<"\n\t\t\t\t\t\t\t\t\tPreparing to take off....."<<endl;
  sleep(1); //function which waits for (n) seconds
  system ("CLS"); //cleares screen
}

};
int main()
{
    SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
    welcome obj1; //object created for welcome class
    obj1.welcum(); //welcum function is called
    Driver system;
    system.menu();
    return 0;
}

// FUNCTION DECLARATION

//Main Menu
void Driver::menu()
{
    menustart:
    int choice;
    char x;
    system("cls");

    cout << endl;
    cout << "\t\t\t\t\t\t\t+=============================================+" << endl;
    cout << "\t\t\t\t\t\t\t||-------------------------------------------||" << endl;
    cout << "\t\t\t\t\t\t\t||                 CAR-E-BOOK                ||" << endl;
    cout << "\t\t\t\t\t\t\t||  Rent with Confidence and Enjoy the Ride  ||" << endl;
    cout << "\t\t\t\t\t\t\t||-------------------------------------------||" << endl;
    cout << "\t\t\t\t\t\t\t+=============================================+" << endl;
    cout << "\t\t\t\t\t\t\t+---------------------------------------------+" << endl;
    cout << "\t\t\t\t\t\t\t|1. Rent A Car                                |" << endl;
    cout << "\t\t\t\t\t\t\t|---------------------------------------------|" << endl;
    cout << "\t\t\t\t\t\t\t|2. Return A Car                              |" << endl;
    cout << "\t\t\t\t\t\t\t|---------------------------------------------|" << endl;
    cout << "\t\t\t\t\t\t\t|3. Cancel a Reservation                      |" << endl;
    cout << "\t\t\t\t\t\t\t|---------------------------------------------|" << endl;
    cout << "\t\t\t\t\t\t\t|4. Check a Reservation                       |" << endl;
    cout << "\t\t\t\t\t\t\t|---------------------------------------------|" << endl;
    cout << "\t\t\t\t\t\t\t|5. Exit Progress                             |" << endl;
    cout << "\t\t\t\t\t\t\t|---------------------------------------------|" << endl;
    cout << "\t\t\t\t\t\t\t|Choose Option: {1/2/3/4/5}                   |" << endl;
    cout << "\t\t\t\t\t\t\t|---------------------------------------------|" << endl;
    cout << "\t\t\t\t\t\t\t What do you want to do?: ";
    // Error handler
    while (!(cin >> choice && choice >=1 && choice <= 6 ))
        {
            cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t\t Invalid Input. Try Again." << endl;
            cout << "\t\t\t\t\t\t\t Enter a number from 1 to 5: ";
            cin.clear();
            cin.ignore(132, '\n');
        }

    switch (choice)
    {
        case 1:
            addDriver();
            break;
        case 2:
            returnCar();
            break;
        case 3:
            cancelReservation();
            break;
        case 4:
            checkReservation();
            break;
        case 5:
            cout << endl << endl;
            cout << "\t\t\t\t\t\t\t+---------------------------------------------+" << endl;
            cout << "\t\t\t\t\t\t\t||                Thank you!!!               ||"<< endl;
            cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t\t||                Developers:                ||" << endl;
            cout << "\t\t\t\t\t\t\t||          Mark Angelo R. Baricante         ||" << endl;
            cout << "\t\t\t\t\t\t\t||           Kim Mathew C. Bautista          ||" << endl;
            cout << "\t\t\t\t\t\t\t||           Vency Gyro Capistrano           ||" << endl;
            cout << "\t\t\t\t\t\t\t||              Boris Hernandez              ||" << endl;
            cout << "\t\t\t\t\t\t\t||           Renier Adrian R. Luna           ||" << endl;
            cout << "\t\t\t\t\t\t\t+---------------------------------------------" << endl;
            exit(0);
        default:
            cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t\t Invalid choice... Please try again.";
            break;
    }
    getch();
    goto menustart;
}



// FUNCTION 1: RENTING A CAR
void Driver::addDriver()
{
    struct car {
        string model;
        int capacity;
        int price;
    };

    // List of Cars
    car carInfo[6];
    carInfo[0].model = "2017 Toyota Vios 1.3 E AT";
    carInfo[0].capacity = 5;
    carInfo[0].price = 2357;

    carInfo[1].model = "2018 Honda City 1.5 E CVT AT";
    carInfo[1].capacity = 5;
    carInfo[1].price = 2484;

    carInfo[2].model = "2018 Honda Civic 1.8 E CVT AT";
    carInfo[2].capacity = 5;
    carInfo[2].price = 3362;

    carInfo[3].model = "2017 Toyota Innova 2.4 E AT";
    carInfo[3].capacity = 8;
    carInfo[3].price = 4286;

    carInfo[4].model = "2015 Toyota Fortuner 2.5 V AT";
    carInfo[4].capacity = 8;
    carInfo[4].price = 4768;

    carInfo[5].model = "2019 Nissan NV350 Premium 3.0";
    carInfo[5].capacity = 15;
    carInfo[5].price = 5716;

    system("cls");

    cout << endl;
    cout << "\t\t\t\t\t\t\t+=============================================+" << endl;
    cout << "\t\t\t\t\t\t\t||-------------------------------------------||" << endl;
    cout << "\t\t\t\t\t\t\t||             PERSONAL INFORMATION          ||" << endl;
    cout << "\t\t\t\t\t\t\t||-------------------------------------------||" << endl;
    cout << "\t\t\t\t\t\t\t+=============================================+" << endl;
    cout << "\t\t\t\t\t\t\t Enter Name: "; cin >> name;
    system("cls");

    cout << endl;
    cout << "\t\t\t\t\t\t\t+=============================================+" << endl;
    cout << "\t\t\t\t\t\t\t||-------------------------------------------||" << endl;
    cout << "\t\t\t\t\t\t\t||             CONTACT INFORMATION           ||" << endl;
    cout << "\t\t\t\t\t\t\t||-------------------------------------------||" << endl;
    cout << "\t\t\t\t\t\t\t+=============================================+" << endl;
    cout << "\t\t\t\t\t\t\t Contact Number: "; cin >> contactNum;
    system("cls");

    cout << endl;
    cout << "\t\t\t\t\t\t\t+=============================================+" << endl;
    cout << "\t\t\t\t\t\t\t||-------------------------------------------||" << endl;
    cout << "\t\t\t\t\t\t\t||            DRIVER'S LICENSE NUMBER        ||" << endl;
    cout << "\t\t\t\t\t\t\t||-------------------------------------------||" << endl;
    cout << "\t\t\t\t\t\t\t+=============================================+" << endl;
    cout << "\t\t\t\t\t\t\t Driver's License Numbers: "; cin >> licenseNum;
    system("cls");

        cout << endl;
    cout << "\t\t\t\t\t\t\t+=============================================+" << endl;
    cout << "\t\t\t\t\t\t\t||-------------------------------------------||" << endl;
    cout << "\t\t\t\t\t\t\t||                LIST OF CARS               ||" << endl;
    cout << "\t\t\t\t\t\t\t||-------------------------------------------||" << endl;
    cout << "\t      ++========================================+=============================================+==========================================++" << endl;

    cout << "\t      || 1. " << carInfo[0].model;
    cout << "\t     ||         2. " << carInfo[1].model;
    cout << "\t       ||     3. " << carInfo[2].model <<"   ||" << endl;

    cout << "\t      || Maximum of " << carInfo[0].capacity << " persons";
    cout << "\t\t     ||         Maximum of " << carInfo[1].capacity << " persons";
    cout << "\t\t       ||     Maximum of " << carInfo[2].capacity << " persons               ||" << endl;

    cout << "\t      || Php " << carInfo[0].price << "/Day";
    cout << "\t\t\t     ||         Php " << carInfo[1].price << "/Day";
    cout << "\t\t\t       ||     Php " << carInfo[2].price << "/Day                       || " << endl;

    cout << "\t      ++=================================================================================================================================++" << endl;

    cout << "\t      || 4. " << carInfo[3].model;
    cout << "\t     ||         5. " << carInfo[4].model;
    cout << "       ||     6. " << carInfo[5].model << "   ||" << endl;

    cout << "\t      || Maximum of " << carInfo[3].capacity << " persons";
    cout << "\t\t     ||         Maximum of " << carInfo[4].capacity << " persons";
    cout << "\t\t       ||     Maximum of " << carInfo[5].capacity << " persons              ||" << endl;

    cout << "\t      || Php " << carInfo[3].price << "/Day";
    cout << "\t\t\t     ||         Php " << carInfo[4].price << "/Day";
    cout << "\t\t\t       ||     Php " << carInfo[5].price << "/Day                       ||" << endl;

    cout << "\t      ++=================================================================================================================================++" << endl;


    cout << "\t\t\t\t\t\t             Enter Car Number you want to rent: ";
        // Error handler
    while (!(cin >> carNum && carNum >=1 && carNum <= 6 ))
        {
            cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t\t Invalid Input. Try Again." << endl;
            cout << "\t\t\t\t\t\t\t Enter a number from 1 to 6: ";
            cin.clear();
            cin.ignore(132, '\n');
        }
    system("cls");

    cout << endl;
    cout << "\t\t\t\t\t\t\t+=============================================+" << endl;
    cout << "\t\t\t\t\t\t\t||-------------------------------------------||" << endl;
    cout << "\t\t\t\t\t\t\t||                 RENT PERIOD               ||" << endl;
    cout << "\t\t\t\t\t\t\t||-------------------------------------------||" << endl;
    cout << "\t\t\t\t\t\t\t+=============================================+" << endl;
    cout << "\t\t\t\t\t\t\t How many days? : "; cin >> numOfDays;
    system("cls");


    int choice;
    srand(time(0));
    referenceNum = rand();
    carModel = carInfo[carNum - 1].model;
    carCapacity = carInfo[carNum - 1].capacity;
    carPrice = carInfo[carNum - 1].price;
    totalPrice = carPrice * numOfDays;
    fstream file;

      cout << endl;
    cout << "\t\t\t\t\t\t\t+=============================================+" << endl;
    cout << "\t\t\t\t\t\t\t||-------------------------------------------||" << endl;
    cout << "\t\t\t\t\t\t\t||              CONFIRMATION PAGE            ||" << endl;
    cout << "\t\t\t\t\t\t\t||-------------------------------------------||" << endl;
    cout << "\t\t\t\t\t\t\t+=============================================+" << endl;

    cout << "\t\t\t\t\t\t\t Reference Number: " << referenceNum << endl;
    cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t Name: " << name << endl;
    cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t Driver's License Number: " << licenseNum << endl;
    cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t Contact Number: " << contactNum << endl;
    cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t Car Information: ";
    cout << carModel << endl;
    cout << "\t\t\t\t\t\t\t\t\t" << "  Maximum of " << carCapacity << endl;
    cout << "\t\t\t\t\t\t\t\t\t" << "  PHP " << carPrice << "/day" << endl;
    cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t Number of days you want to rent: " << numOfDays << endl;
    cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t Total Price: " << "PHP " << totalPrice << endl;
    cout << "\t\t\t\t\t\t\t+=============================================+" << endl;
    cout << "\t\t\t\t\t\t\t [1] Confirm my rent [2] Go back to Main Menu" << endl;
    cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t Enter the number of your choice: ";
    // Error handler
    while (!(cin >> choice && choice >=1 && choice <= 2 ))
        {
            cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t\t Invalid Input. Try Again." << endl;
            cout << "\t\t\t\t\t\t\t Enter number 1 or 2 only: ";
            cin.clear();
            cin.ignore(132, '\n');
        }

    switch (choice)
        {
            case 1:
                file.open("driverRecord.txt", ios::app | ios::out);
                file << " " << referenceNum << " " << name << " " << licenseNum << " " << contactNum << " " << totalPrice << "\n";
                file.close();
                break;
            case 2:
                system("cls");
                main();
                break;
            default:
                cout << "\t\t\t\t\t\t\t Invalid choice... Please try again.";
                break;
        }
}

// FUNCTION 2: CHECK A RESERVATION
void Driver::checkReservation()
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("driverRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Reservations --------------------------------------------" << endl;
        cout << "\n\t\t\t\t\t\t\tNo record found... " << endl;
    }
    else
    {
        int reference_num;
        cout << endl;
        cout << "\t\t\t\t\t\t\t+=============================================+" << endl;
        cout << "\t\t\t\t\t\t\t||-------------------------------------------||" << endl;
        cout << "\t\t\t\t\t\t\t||                RESERVATIONS               ||" << endl;
        cout << "\t\t\t\t\t\t\t||-------------------------------------------||" << endl;
        cout << "\t\t\t\t\t\t\t+=============================================+" << endl;
        cout << "\t\t\t\t\t\t\t Enter your reference number: ";
        cin >> reference_num;
        file >> referenceNum >> name >> licenseNum >> contactNum >> totalPrice;
        while (!file.eof())
        {
            if (reference_num == referenceNum)
            {
                found++;
                cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
                cout << "\t\t\t\t\t\t\t Reference Number: " << referenceNum << endl;
                cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
                cout << "\t\t\t\t\t\t\t Name: " << name << endl;
                cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
                cout << "\t\t\t\t\t\t\t Driver's License Number: " << licenseNum << endl;
                cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
                cout << "\t\t\t\t\t\t\t Contact Number: " << contactNum << endl;
                cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
                cout << "\t\t\t\t\t\t\t Total Price: " << "PHP " << totalPrice << endl;
                cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
                cout << "\t\t\t\t\t\t\t Press [ENTER] to go back";
            }
            file >> referenceNum >> name >> licenseNum >> contactNum >> totalPrice;
        }
        if (found == 0)
        {
            cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t\t Reservation Number Not Found...." << endl;
            cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t\t Press [ENTER] to go back";
        }
        file.close();
    }
}
// FUNCTION 3: RETURN A CAR
void Driver::returnCar()
{
    system("cls");
    fstream file, file1;
    int found = 0;
    int reference_num;
        cout << "\t\t\t\t\t\t\t+=============================================+" << endl;
        cout << "\t\t\t\t\t\t\t||-------------------------------------------||" << endl;
        cout << "\t\t\t\t\t\t\t||                RETURN A CAR               ||" << endl;
        cout << "\t\t\t\t\t\t\t||-------------------------------------------||" << endl;
        cout << "\t\t\t\t\t\t\t+=============================================+" << endl;
    file.open("driverRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\t\t\t\t\t\t\t Enter the Reference No. of the car" << endl;
        cout << "\t\t\t\t\t\t\t you want to return: ";
        cin >> reference_num;

        file1.open("record.txt", ios::app | ios::out);
        file >> referenceNum >> name >> licenseNum >> contactNum >> totalPrice;
        while (!file.eof())
        {
            if (reference_num != referenceNum)
            {
                file1 << " " << referenceNum << " " << name << " " << licenseNum << " " << contactNum << " " << totalPrice << "\n";
            }
            else
            {
                found++;
                cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
                cout << "\t\t\t\t\t\t\t Successfully Return the car";
                cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
                cout << "\t\t\t\t\t\t\t Press [ENTER] to go back";
            }
            file >> referenceNum >> name >> licenseNum >> contactNum >> totalPrice;
        }
        if (found == 0)
        {
            cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t\t Reference Number Not Found..." << endl;
            cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t\t Press [ENTER] to go back";
        }
        file1.close();
        file.close();
        remove("driverRecord.txt");
        rename("record.txt", "driverRecord.txt");
    }
}

// FUNCTION 4: CANCEL A RESERVATION
void Driver::cancelReservation()
{
    system("cls");
    fstream file, file1;
    int found = 0;
    int reference_num;
        cout << "\t\t\t\t\t\t\t+=============================================+" << endl;
        cout << "\t\t\t\t\t\t\t||-------------------------------------------||" << endl;
        cout << "\t\t\t\t\t\t\t||            CANCEL A RESERVATION           ||" << endl;
        cout << "\t\t\t\t\t\t\t||-------------------------------------------||" << endl;
        cout << "\t\t\t\t\t\t\t+=============================================+" << endl;
    file.open("driverRecord.txt", ios::in);
    if (!file)
    {
        cout << "\t\t\t\t\t\t\t No Data is Present..";
        file.close();
    }
    else
    {
        cout << "\t\t\t\t\t\t\t Enter the Reference No. of the car" << endl;
        cout << "\t\t\t\t\t\t\t you want to cancel: ";
        cin >> reference_num;
        file1.open("record.txt", ios::app | ios::out);
        file >> referenceNum >> name >> licenseNum >> contactNum >> totalPrice;
        while (!file.eof())
        {
            if (reference_num != referenceNum)
            {
                file1 << " " << referenceNum << " " << name << " " << licenseNum << " " << contactNum << " " << totalPrice << "\n";
            }
            else
            {
                found++;
                cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
                cout << "\t\t\t\t\t\t\t Successfully Cancelled the Reservation...";
                cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
                cout << "\t\t\t\t\t\t\t Press [ENTER] to go back";
            }
            file >> referenceNum >> name >> licenseNum >> contactNum >> totalPrice;
        }
        if (found == 0)
        {
            cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t\t Reference number not found..." << endl;
            cout << "\t\t\t\t\t\t\t-----------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t\t Press [ENTER] to go back";
        }
        file1.close();
        file.close();
        remove("driverRecord.txt");
        rename("record.txt", "driverRecord.txt");
    }
}



// FUNCTION 4: CANCEL A RESERVATION

// FUNCTION 5: EXIT












