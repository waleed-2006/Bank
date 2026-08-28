#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <limits>

#include "stringfunctions.h"
#include "filefunctions.h"

using namespace std;

struct strCleint {
    string AccountNumber, PINcode, Name, Phone;
    double AccountBalance;
    bool markForDelet = false;
};
strCleint CreatClientInfile(vector<strCleint>& records, string FileName);
string CreatAccountNumber();
bool isAccExist(vector<strCleint>& clients,string accountNumber) {
    for (strCleint &client : clients) {
        if (client.AccountNumber == accountNumber) {
            return true;
        }
    }

}
strCleint CreatClient(vector<strCleint> &clients) {
    strCleint client;
    cout << "enter Name? "; cin >> client.Name;
    cout << "enter Your phone Number ?"; cin >> client.Phone;
    cout << "enter your balance? "; cin >> client.AccountBalance;
    cout << "enter your PIN ? "; cin >> client.PINcode;


    cout << "enter your Account Number ? "; 
    cin >> client.AccountNumber;
    while (isAccExist(clients, client.AccountNumber)) {

        cout << "Account already exists, use new  Account Number ? ";
        cin >> client.AccountNumber;

        return client;
    }
}
strCleint ReadCleint() {
    strCleint client;
    cout << "enter Name? "; cin >> client.Name;
    cout << "enter Your phone Number ?"; cin >> client.Phone;
    cout << "enter your balance? "; cin >> client.AccountBalance;
    cout << "enter your PIN ? "; cin >> client.PINcode;


    cout << "enter your Account Number ? "; cin >> client.AccountNumber;
    return client;
}

string convertClientToline(const strCleint& client, string delim) {
    return client.AccountNumber+ delim + client.PINcode+ delim + client.Name + delim + client.Phone + delim +
        to_string(client.AccountBalance);
}

strCleint convertLineToRecord(string line, string delim) {
    strCleint client;
    vector<string> info = split(line, delim);

    if (info.size() >= 5) {
        client.Name = info[2];
        client.Phone = info[3];
        client.AccountNumber = info[0];
        client.PINcode = info[1];
        client.AccountBalance = stof(info[4]);
    }

    return client;
}
bool FindClient(vector<strCleint> clients, string AccountNumber);
void AddClient(string FileName, vector<strCleint>& vClientsRecords) {
    fstream myfile(FileName, ios::app);
    myfile << "\n"<<convertClientToline(CreatClientInfile(vClientsRecords, FileName), "#//#") << endl;
}

void AddClients(string FileName, vector<strCleint>& vClientsRecords) {
    char AddMore = 'y';

    while (tolower(AddMore) == 'y') {
        AddClient(FileName, vClientsRecords);
        cout << "client Added correctly, do You want to add more records: [Y/N]";
        cin >> AddMore;
    }
}

vector<strCleint> LoadDataFromFile(string FileName) {
    vector<strCleint> clients;
    fstream myfile(FileName);
    string line;

    while (getline(myfile, line))
        if (!line.empty())
            clients.push_back(convertLineToRecord(line, "#//#"));

    return clients;
}

void printRecord(strCleint client) {
    cout << "| " << setw(25) << client.Name
        << "| " << setw(15) << client.Phone
        << "| " << setw(20) << client.AccountNumber
        << "| " << setw(9) << client.PINcode
        << "| " << setw(10) << client.AccountBalance<<"";
}

void ShowAllClients(vector<strCleint> clients) {
    cout << "\t\t\t\t\t\tclient list (" << clients.size() << ") client(s)\n";
    cout << "\n------------------------------------------------------------------------------------------------\n";

    cout << "| " << left << setw(25) << "Name"
        << "| " << setw(15) << "Phone Number "
        << "| " << setw(20) << "Account Number "
        << "| " << setw(9) << "PIN code"
        << "| " << setw(10) << "Account Balance";

    cout << "\n------------------------------------------------------------------------------------------------\n";

    for (strCleint& client : clients) {
        printRecord(client);
        cout << endl;
    }
}

void LoadFromVectorToFile(vector<strCleint>& clients, string FileName) {
    ofstream myfile(FileName);

    for (strCleint& client : clients)
        if (!client.markForDelet)
            myfile << convertClientToline(client, "#//#") << endl;
}

void clearfile(string FileName) {
    fstream MyFile(FileName, ios::trunc);
    //if (MyFile.is_open())
    //    cout << "file cleared!\n";
}

string CreatAccountNumber() {
    static int ClientId = -1;
    return "1234" + to_string(++ClientId);
}

bool FindClient(vector<strCleint> clients, string AccountNumber) {
    strCleint client;
    for (strCleint& record : clients)
        if (record.AccountNumber == AccountNumber) {
            client.AccountNumber = record.AccountNumber;
            client.AccountBalance = record.AccountBalance;
            client.Name = record.Name;
            client.markForDelet = record.markForDelet;
            client.PINcode = record.PINcode;
            client.Phone = record.Phone;
            printRecord(client);
            return true;
        }

    return false;
}

bool markfordelet(string AccountNumber, vector<strCleint>& clients) {
    for (strCleint& client : clients)
        if (client.AccountNumber == AccountNumber) {
            client.markForDelet = true;
            return true;
        }

    return false;
}

bool updateClient(string AccountNumber, vector<strCleint>& clients) {
    for (strCleint& client : clients)
        if (client.AccountNumber == AccountNumber) {
            client.Name = ReadString("Name? ");
            client.AccountBalance = ReadNumber("Account Balance? ");
            client.Phone = ReadString("Phone? ");
            client.PINcode = ReadString("PIN? ");
            return true;
        }

    return false;
}

void deletRec(vector<strCleint>& records, string AccountNumber, string FileName) {
    char delet = 'n';

    if (FindClient(records, AccountNumber)) {
        cout << "\nAre you sure that you want to delete this account? [Y/N] ";
        cin >> delet;

        if (delet == 'y' || delet == 'Y') {
            markfordelet(AccountNumber, records);
            LoadFromVectorToFile(records, FileName);
            cout << "Account deleted successfully\n";
            records = LoadDataFromFile(FileName);
        }
    }
    else
        cout << "Client is not found\n";
}

void updateClientInfile(vector<strCleint>& records, string AccountNumber,
    strCleint& client, string FileName) {
    char update = 'n';

    if (FindClient(records, AccountNumber)) {
        cout << "Are you sure that you want to update this account? [Y/N] ";
        cin >> update;

        if (update == 'y' || update == 'Y')
            if (updateClient(AccountNumber, records)) {
                LoadFromVectorToFile(records, FileName);
                cout << "Account updated successfully\n";
                records = LoadDataFromFile(FileName);
            }
    }
    else
        cout << "Client is not found\n";
}
strCleint CreatClientInfile(vector<strCleint>& records, string FileName) {
    char update = 'n';
    strCleint client= CreatClient(records);


    //LoadFromVectorToFile(records, FileName);
    //cout << "Account updated successfully\n";
    //records = LoadDataFromFile(FileName);
    return client;
;
}