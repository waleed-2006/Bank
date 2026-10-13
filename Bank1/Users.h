#pragma once
#include <string>
#include <fstream>
#include "stringfunctions.h"
#include "filefunctions.h"
#include "Client.h"
#include "transactions.h"
using namespace std;
enum enUserMenueScreen
{
    ListUsers = 1,
    AddNewUser = 2,
    DeleteUser = 3,
    UpdateUser = 4,
    searchUser = 5,
    MainMenuescreen = 6,
};
enum enPermissions {
    allAccess = -1
};
struct strUser {
    string Name;
    string Password;
    vector<int>  permision;
    bool markForDelet = false;
    
};
strUser CurrentUser;
void printUser(strUser User) {
    string permissions;
    for (int perm : User.permision) {
        permissions += to_string(perm) + " ";
    }
    cout << "| " << setw(25) << User.Name
        << "| " << setw(15) << User.Password
        << "| " << setw(20) << permissions;

}
void ShowAllUsers(vector<strUser> Users) {
    cout << "\t\t\t\t\t\tclient list (" << Users.size() << ") client(s)\n";
    cout << "\n------------------------------------------------------------------------------------------------\n";

    cout << "| " << left << setw(25) << "Name"
        << "| " << setw(15) << "Pass Word "
        << "| " << setw(20) << "Permissions ";


    cout << "\n------------------------------------------------------------------------------------------------\n";

    for (strUser& client : Users) {
        printUser(client);
        cout << endl;
    }
}
enUserMenueScreen ReadUserMenueOption() {
    cout << "Choose what do want to do [1 to 6]";
    short option;
    cin >> option;
    return (enUserMenueScreen)option;
}
void performUserOptoin(enUserMenueScreen menueOption);
void ShowUsersMenue() {
    system("cls");
    cout << "[1] List Users\n" << "[2] Add New Users\n" <<
        "[3] Delete User\n" << "[4] Update User\n" << "[5] User\n" << "[6] Main Menue";
    cout << "\n=============================================\n";
    performUserOptoin(ReadUserMenueOption());
}
strUser convertLineToUser(string line, string delim);
vector<strUser> LoadUsersFromFile(string FileName) {
    vector<strUser> Users;
    fstream myfile(FileName);
    string line;

    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            cout << "Line: [" << line << "]" << endl;
            bool hasData = !line.empty();

            if (hasData)
                Users.push_back(convertLineToUser(line, "#//#"));
        }
    }
    else {
        cout << "coudn't open file";
    }
    return Users;
}
bool isUserExist(vector<strUser>& Users, string UserName) {
    for (strUser& user : Users) {
        if (user.Name == UserName) {
            return true;
        }
    }
    return false;

}
strUser CreatUser(vector<strUser>& Users) {
    strUser User;
    cout << "enter Name? "; cin >> User.Name;
    cout << "enter Password?"; cin >> User.Password;
    cout << "Do you want to give if the user full Access?y,n";
    char fullAccess = 'y';
    cin >> fullAccess;
    if (tolower(fullAccess) == 'y') {
        User.permision.push_back(-1);
        
    }
    if (fullAccess == tolower('n')) {
        cout << "Do you want to allow this user to list users?y,n";
        char giveperm;
        cin >> giveperm;
        if (tolower(giveperm) == 'y') {
            User.permision.push_back(1);

        }
        cout << "Do you want to allow this user to add users?y,n";
        cin >> giveperm;
        if (tolower(giveperm) == 'y') {
            User.permision.push_back(2);

        }

        cout << "Do you want to allow this user to delete users?y,n";
        cin >> giveperm;
        if (tolower(giveperm) == 'y') {
            User.permision.push_back(3);

        }

        cout << "Do you want to allow this user to update users?y,n";
        cin >> giveperm;
        if (tolower(giveperm) == 'y') {
            User.permision.push_back(4);

        }
        cout << "Do you want to allow this user to find users?y,n";
        cin >> giveperm;
        if (tolower(giveperm) == 'y') {
            User.permision.push_back(5);

        }

    }


    while (isUserExist(Users, User.Name)) {

        cout << "User  already exists, use new  Account Number ? ";
        cin >> User.Name;


    }
    Users.push_back(User);
    return User;
}
void LoadUserFromVectorToFile(vector<strUser>& Users, string FileName);
strUser CreatUsertInfile(vector<strUser>& users, string FileName) {
    char update = 'n';
    strUser client = CreatUser(users);


    LoadUserFromVectorToFile(users, FileName);
    cout << "Account updated successfully\n";
    users = LoadUsersFromFile(FileName);
    return client;

}
string convertUserToline(const strUser& user, string delim) {
    string permissions;
    for (int perm : user.permision) {
        permissions += to_string(perm)+" ";
    }
    return user.Name + delim + user.Password + delim + permissions;
}
void AddUserTofile(string FileName, vector<strUser>& vUsersRecords) {
    fstream myfile(FileName, ios::app);
    myfile << "\n" << convertUserToline(CreatUsertInfile(vUsersRecords, FileName), "#//#") << endl;
}

void AddUsers(string FileName, vector<strUser>& vUsersRecords) {
    char AddMore = 'y';

    while (tolower(AddMore) == 'y') {
        CreatUsertInfile(vUsersRecords, FileName);
        cout << "User Added correctly, do You want to add more records: [Y/N]";
        cin >> AddMore;
    }
}

bool FindUser(vector<strUser> vUsers, string Name) {
    strUser user;
    for (strUser& userRecord : vUsers)
        if (userRecord.Name == Name) {
            user.Name = userRecord.Name;
            user.Password = userRecord.Password;
            user.permision = userRecord.permision;

            printUser(user);
            return true;
        }

    return false;
}
strUser loggedIn(vector<strUser> vUsers, string Name) {
    strUser user;
    for (strUser& userRecord : vUsers)
        if (userRecord.Name == Name) {
            user.Name = userRecord.Name;
            user.Password = userRecord.Password;
            user.permision = userRecord.permision;
            return user;
        }

}
string FindUserPassword(vector<strUser> vUsers, string Name) {
    strUser user;
    for (strUser& userRecord : vUsers)
        if (userRecord.Name == Name) {
            return userRecord.Password;
        }

    return " ";
}


bool markUserfordelet(string AccountNumber, vector<strUser>& vUsers) {
    for (strUser& user : vUsers)
        if (user.Name == AccountNumber) {
            user.markForDelet = true;
            return true;
        }

    return false;
}
void LoadUserFromVectorToFile(vector<strUser>& Users, string FileName) {
    ofstream myfile(FileName);

    for (strUser& user : Users)
        if (!user.markForDelet)
            myfile << convertUserToline(user, "#//#") << endl;
}
strUser convertLineToUser(string line, string delim) {
    strUser user;
    vector<string> info = split(line, delim);
    vector<string> permstring= split(info[2], " ");
    vector<int> arrPerm;
    for (string& perm : permstring) {
        arrPerm.push_back(stoi(perm));
    }

    if (info.size() >= 3) {
        user.Name = info[0];
        user.Password = info[1];
        user.permision = arrPerm;
        
    }

    return user;
}

void deletUser(vector<strUser>& records, string Name, string FileName) {
    char delet = 'n';

    if (FindUser(records, Name)) {
        cout << "\nAre you sure that you want to delete this account? [Y/N] ";
        cin >> delet;

        if (delet == 'y' || delet == 'Y') {
            markUserfordelet(Name, records);
            LoadUserFromVectorToFile(records, FileName);
            cout << "Account deleted successfully\n";
            records = LoadUsersFromFile(FileName);
        }
    }
    else {
        cout << "Client is not found\n";
    }
}

bool updateUser(string Name, vector<strUser>& Users) {
    for (strUser& User : Users)
        if (User.Name == Name) {
            User.Name = ReadString("Name? ");
            User.Password = ReadNumber("enter New Password? ");
            cout << "Do you want to give if the user full Access?y,n";
            char fullAccess = 'y';
            cin >> fullAccess;
            if (tolower(fullAccess) == 'y') {
                User.permision.push_back(-1);

            }
            if (!fullAccess == tolower('y')) {
                cout << "Do you want to allow this user to list users?y,n";
                char giveperm;
                cin >> giveperm;
                if (tolower(giveperm) == 'y') {
                    User.permision.push_back(1);

                }
                cout << "Do you want to allow this user to add users?y,n";
                cin >> giveperm;
                if (tolower(giveperm) == 'y') {
                    User.permision.push_back(2);

                }

                cout << "Do you want to allow this user to delete users?y,n";
                cin >> giveperm;
                if (tolower(giveperm) == 'y') {
                    User.permision.push_back(3);

                }

                cout << "Do you want to allow this user to update users?y,n";
                cin >> giveperm;
                if (tolower(giveperm) == 'y') {
                    User.permision.push_back(4);

                }
                cout << "Do you want to allow this user to find users?y,n";
                cin >> giveperm;
                if (tolower(giveperm) == 'y') {
                    User.permision.push_back(5);

                }
                return true;
            }

            return false;
        }
}
void updateUsertInfile(vector<strUser>&records, string Name,
    strUser &user, string FileName) {
    char update = 'n';

    if (FindUser(records, Name)) {
        cout<< "Are you sure that you want to update this account? [Y/N] ";
        cin >> update;

        if (update == 'y' || update == 'Y'){
            if (updateUser(Name, records)) {
                LoadUserFromVectorToFile(records, FileName);
                cout << "User updated successfully\n";
                records = LoadUsersFromFile(FileName);}
            }
    }

    else {
        cout<< "Client is not found\n";
    }
        
}
bool checkPermit(strUser currentUser,enUserMenueScreen option) {
    for (int i : CurrentUser.permision) {
        if (i == -1) {
            return true;
        }
        else if (static_cast<enUserMenueScreen>(i) == option) {
            return true;
        }
    }
    return false;


}
void performUserOptoin(enUserMenueScreen menueOption) {
    string filename = "Users.txt";
    vector<strUser> Users = LoadUsersFromFile(filename);
    string User_Name;
    strUser user;
    bool isPermited= checkPermit(CurrentUser, menueOption);
    if (!isPermited) {
        cout << "\nYou are not permited to do this\n";
        system("pause");
        system("cls");
        ShowUsersMenue();
        return;
    }
    else {
        switch (menueOption) {
        case enUserMenueScreen::ListUsers:
            system("cls");
            cout << "\n=============================================\n";
            cout << "             Users List                        ";
            cout << "\n=============================================\n";
            ShowAllUsers(Users);
            system("pause");
            ShowUsersMenue();
            break;



        case enUserMenueScreen::AddNewUser:
            system("cls");
            cout << "\n=============================================\n";
            cout << "             Add New Users                       ";
            cout << "\n=============================================\n";
            AddUsers(filename, Users);
            system("pause");
            ShowUsersMenue();
            break;

        case enUserMenueScreen::DeleteUser:
            system("cls");
            cout << "\n=============================================\n";
            cout << "             Delete User                        ";
            cout << "\n=============================================\n";
            User_Name = ReadString("enter UserName?");
            deletUser(Users, User_Name, filename);
            system("pause");
            ShowUsersMenue();
            break;

        case enUserMenueScreen::UpdateUser:
            system("cls");
            cout << "\n=============================================\n";
            cout << "             Update Client                        ";
            cout << "\n=============================================\n";
            User_Name = ReadString("enter Name?");
            while (!isUserExist(Users, User_Name)) {
                User_Name = ReadString("user is not existed enter account number?");
            };
            updateUsertInfile(Users, User_Name, user, filename);
            system("pause");
            ShowUsersMenue();
            break;

        case enUserMenueScreen::searchUser:
            system("cls");
            cout << "\n=============================================\n";
            cout << "             Search for User                        ";
            cout << "\n=============================================\n";
            User_Name = ReadString("enter account number?");
            FindUser(Users, User_Name);
            system("pause");
            ShowUsersMenue();
            break;

        case enUserMenueScreen::MainMenuescreen:
            system("cls");

            showMainMenue();
            system("pause");
            break;
        }
    }


};