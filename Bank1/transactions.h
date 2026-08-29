#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <limits>

#include "stringfunctions.h"
#include "filefunctions.h"
#include "Client.h"
void showMainMenue();

enum enTransactionsMenue
{
    Deposit = 1,
    Withdraw = 2,
    totalBalances = 3,
    MainMenue = 4,
};
void PerformTransActionsMenue(enTransactionsMenue option);
enTransactionsMenue ReadTransActionsMenue() {
    cout << "Choose what do want to do [1 to 4]";
    short option;
    cin >> option;
    return (enTransactionsMenue)option;
}
void printClient(strCleint client) {
    cout << "\n=============================================\n";
    cout << "Name: " << client.Name
        << "\n" << "Phone: " << client.Phone
        << "\n" << "Account Number: " << client.AccountNumber
        << "\n" << "PIN code: " << client.PINcode
        << "\n" << "Account Balance: " << client.AccountBalance ;
    cout << "\n=============================================\n";
}
void printBalance(strCleint client) {
    cout << "| " << setw(30) << client.Name

        << "| " << setw(20) << client.AccountNumber

        << "| " << setw(10) << client.AccountBalance << "";
}

void ShowAllBalances(vector<strCleint> clients) {
    cout << "\t\t\t\t\t\tclient list (" << clients.size() << ") client(s)\n";
    cout << "\n------------------------------------------------------------------------------------------------\n";

    cout << "| " << left << setw(30) << "Name"
        << "| " << setw(20) << "Account Number "

        << "| " << setw(10) << "Account Balance";

    cout << "\n------------------------------------------------------------------------------------------------\n";

    for (strCleint& client : clients) {
        printBalance(client);
        cout << endl;
    }
}

bool printClientDet(vector<strCleint> clients, string AccountNumber) {
    strCleint client;
    for (strCleint& record : clients)
        if (record.AccountNumber == AccountNumber) {
            client.AccountNumber = record.AccountNumber;
            client.AccountBalance = record.AccountBalance;
            client.Name = record.Name;
            client.markForDelet = record.markForDelet;
            client.PINcode = record.PINcode;
            client.Phone = record.Phone;
            printClient(client);
            return true;
        }

    return false;
}

string ReadAccountNumber(vector<strCleint> &clients) {
    string Account_number;
    cout << "Please enter Account Number? ";
    cin >> Account_number;
    while (isAccExist(clients, Account_number)!=true) {
        cout << "Account Number Not found, please enter again? ";
        cin >> Account_number;
    }
    return Account_number;
}
bool updateDeposit(string AccountNumber, vector<strCleint>& clients,int amount) {
    for (strCleint& client : clients)
        if (client.AccountNumber == AccountNumber) {

            client.AccountBalance += amount;

            return true;
        }

    return false;
}
bool updateWithdraw(string AccountNumber, vector<strCleint>& clients, int amount) {
    for (strCleint& client : clients)
        if (client.AccountNumber == AccountNumber) {
            while (amount > client.AccountBalance) {
                cout << "amount to be withdrawn is exeeding the current balance\npleaes enter amount to be withdrawn? ";
                cin >> amount;
            }
            client.AccountBalance -= amount;

            return true;
        }

    return false;
}
void Perform_Deposit(vector<strCleint>& records, string AccountNumber,
    strCleint& client, string FileName) {
    char update = 'n';

    if (printClientDet(records, AccountNumber)) {
        int deposit_amoutn;
        cout << "Enter Amount of Deposit: ";
        cin >> deposit_amoutn;


        cout << "Are you sure that you want to deposit to this account? [Y/N] ";
        cin >> update;

        if (update == 'y' || update == 'Y')
            if (updateDeposit(AccountNumber, records,deposit_amoutn)) {
                LoadFromVectorToFile(records, FileName);
                cout << "Deposit done successfully\n";
                records = LoadDataFromFile(FileName);
            }
    }
    else
        cout << "Client is not found\n";
}

void Perform_Withdraw(vector<strCleint>& records, string AccountNumber,
    strCleint& client, string FileName) {
    char update = 'n';

    if (printClientDet(records, AccountNumber)) {
        int deposit_amoutn;
        cout << "\nEnter Amount of Withdraw: ";
        cin >> deposit_amoutn;


        cout << "\nAre you sure that you want to withdraw to this account? [Y/N] ";
        cin >> update;

        if (update == 'y' || update == 'Y')
            if (updateWithdraw(AccountNumber, records, deposit_amoutn)) {
                LoadFromVectorToFile(records, FileName);
                cout << "Withdraw done successfully\n";
                records = LoadDataFromFile(FileName);
            }
    }
    else
        cout << "Client is not found\n";
}


void showTransactionsMenue() {
    system("cls");
    cout << "\n=============================================\n";
    cout << "             Transactions                        ";
    cout << "\n=============================================\n";
    cout << "[1] Deposit\n" << "[2] WithDraw\n" <<
        "[3] Show all Balances\n" << "[4] Main Menue\n" ;
    cout << "\n=============================================\n";
    PerformTransActionsMenue(ReadTransActionsMenue());
}

void PerformTransActionsMenue(enTransactionsMenue option) {
    string filename = "Clients.txt";
    vector<strCleint> clients = LoadDataFromFile(filename);
    string Account_number;
    strCleint cleint;
    switch (option) {
    case enTransactionsMenue::Deposit:
        system("cls");
        cout << "\n=============================================\n";
        cout << "                   Deposit                       ";
        cout << "\n=============================================\n";
        Account_number = ReadAccountNumber(clients);
        cout << "the folowing are the client details: ";
        FindClient(clients, Account_number);
        Perform_Deposit(clients, Account_number, cleint,filename);
        system("pause");
        showTransactionsMenue();
        break;

    case enTransactionsMenue::Withdraw:
        system("cls");
        cout << "\n=============================================\n";
        cout << "                   Withdraw                       ";
        cout << "\n=============================================\n";
        Account_number = ReadAccountNumber(clients);
        cout << "the folowing are the client details: ";
        FindClient(clients, Account_number);
        Perform_Withdraw(clients, Account_number, cleint, filename);
        system("pause");
        showTransactionsMenue();
        break;

    case enTransactionsMenue::totalBalances:
        system("cls");
        cout << "\n=============================================\n";
        cout << "                   Total Balances                       ";
        cout << "\n=============================================\n";
        ShowAllBalances(clients);
        system("pause");
        showTransactionsMenue();
        break;

    case enTransactionsMenue::MainMenue:

        showMainMenue();
        break;
    }
    }


