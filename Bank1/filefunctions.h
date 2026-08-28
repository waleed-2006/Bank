#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void AddFromFileToVector(string FileName, vector<string>& vContent) {
    fstream MyFile(FileName);
    string line;
    while (getline(MyFile, line))
        vContent.push_back(line);
}

void PrintFile(string FileName) {
    ifstream MyFile(FileName);
    string line;
    while (getline(MyFile, line))
        cout << line << endl;
}

void AddFromVectorToFile(string FileName, vector<string>& vContent) {
    fstream MyFile(FileName);
    for (string& line : vContent)
        MyFile << line << endl;
}

void DeleteFromFile(string FileName, string Record) {
    vector<string> vContent;
    AddFromFileToVector(FileName, vContent);

    for (auto it = vContent.begin(); it != vContent.end();)
        if (*it == Record)
            it = vContent.erase(it);
        else
            ++it;

    AddFromVectorToFile(FileName, vContent);
}

void UpdateFile(string FileName, string Record, string UpdateTo) {
    vector<string> vContent;
    AddFromFileToVector(FileName, vContent);

    for (string& line : vContent)
        if (line == Record)
            line = UpdateTo;

    AddFromVectorToFile(FileName, vContent);
}