// Bank1.cpp : This file contains the 'main' function.
// Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <cstdlib> // Required header for system()

#include "stringfunctions.h"
#include "filefunctions.h"
#include "Client.h"
#include "transactions.h"

using namespace std;

enum enMenueScreen
{
    ShowClientList = 1,
    AddNewClientOption = 2,
    DeleteClient = 3,
    UpdateClient = 4,
    SearchClient = 5,
    transactions_menue=6,
    Exit = 7
};
enMenueScreen ReadMainMenueOption() {
    cout << "Choose what do want to do [1 to 7]";
    short option;
    cin >> option;
    return (enMenueScreen)option;
}
void performMenueOptoin(enMenueScreen menueOption);
void showMainMenue() {
    system("cls");
    cout << "\n=============================================\n";
    cout << "             MAIN MENUE                        ";
    cout << "\n=============================================\n";
    cout << "[1] Show client list\n" << "[2] Add New Client\n" <<
        "[3] Delete Client\n" << "[4] Update Client\n" << "[5] Find client\n" <<  "[6] Transactions Menue\n"<<"[7] Exit";
    cout << "\n=============================================\n";
    performMenueOptoin(ReadMainMenueOption());
}

void performMenueOptoin(enMenueScreen menueOption) {
    string filename = "Clients.txt";
    vector<strCleint> clients = LoadDataFromFile(filename);
    string Account_number;
    strCleint cleint;

    switch (menueOption) {
    case enMenueScreen::ShowClientList:

        system("cls");
        cout << "\n=============================================\n";
        cout << "             Show Client List                        ";
        cout << "\n=============================================\n";
        ShowAllClients(clients);
        system("pause");
        showMainMenue();
        break;



    case enMenueScreen::AddNewClientOption:
        system("cls");
        cout << "\n=============================================\n";
        cout << "             Add New Clients                       ";
        cout << "\n=============================================\n";
        AddClients(filename, clients);
        system("pause");
        showMainMenue();
        break;

    case enMenueScreen::DeleteClient:
        system("cls");
        cout << "\n=============================================\n";
        cout << "             Delete Client                        ";
        cout << "\n=============================================\n";
        Account_number = ReadString("enter account number?");
        deletRec(clients, Account_number, filename);
        system("pause");
        showMainMenue();
        break;

    case enMenueScreen::UpdateClient:
        system("cls");
        cout << "\n=============================================\n";
        cout << "             Update Client                        ";
        cout << "\n=============================================\n";
        Account_number = ReadString("enter account number?");
        while (!isAccExist(clients, Account_number)) {
            Account_number = ReadString("Account is not existed enter account number?");
        }
        ;
        updateClientInfile(clients,Account_number,  cleint ,filename);
        system("pause");
        showMainMenue();

    case enMenueScreen::SearchClient:
        system("cls");
        cout << "\n=============================================\n";
        cout << "             Search for Client                        ";
        cout << "\n=============================================\n";
        Account_number = ReadString("enter account number?");
        FindClient(clients, Account_number);
        system("pause");
        showMainMenue();

    case enMenueScreen::transactions_menue:
        system("cls");
        showTransactionsMenue();
        system("pause");
        showMainMenue();

    case enMenueScreen::Exit:
        system("cls");
        cout << "\n=============================================\n";
        cout << "             Program has end                        ";
        cout << "\n=============================================\n";
    }
};

    

int main()
{
    showMainMenue();
 
    return 0;
}