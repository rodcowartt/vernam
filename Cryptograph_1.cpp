#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

void crypt(string key)
{
    string line;
    ifstream ifst;
    ofstream ofst;

    int keylen = key.length();

    ifst.open("decode.txt");
    ofst.open("code.txt");


    if (ifst.is_open())
    {
        while (!ifst.eof())
        {
            getline(ifst, line);
            std::cout << "Decode msg:" << line << std::endl;
        }
        ifst.close();
    }
    else cout << "Unable to open decode file";

    string pascode;

    int codelen = line.length();
    char* key1 = new char[codelen];
    char* str1 = new char[codelen];

    str1[codelen] = '\0';
    for (int k = 0; k < codelen; k++) {
        key1[k] = (char)rand() % 255;
        str1[k] = line[k];
    }
    cout << "\nstr1:" << str1;
    char* codemsg = new char[codelen];
    for (int k = 0; k < codelen; k++) {
        codemsg[k] = str1[k] ^ key1[k];
    }
    codemsg[codelen] = '\0';
    printf("\nshifr:%s", codemsg);
    ofst << codemsg;
    ofst.close();
    ifst.close();

    ifst.open("code.txt");
    std::cout << "\n-----------------------------------" << std::endl;
    std::cout << "Code message:" << std::endl;
    if (ifst.is_open())
    {
        while (!ifst.eof())
        {
            getline(ifst, line);
            std::cout << line << std::endl;
        }
        ifst.close();
    }
    else std::cout << "Unable to open code file";
}
void decrypt(string key)
{
    std::string line;
    std::ifstream ifst;
    std::ofstream ofst;
    std::ifstream pst;
    int keylen = key.length();
    ifst.open("code.txt");
    ofst.open("decode.txt");


    if (ifst.is_open())
    {
        while (!ifst.eof())
        {
            getline(ifst, line);
            cout << "code msg:" << line << endl;
        }
        ifst.close();
    }
    else cout << "Unable to open code file";

    int codelen = line.length();
    char* key1 = new char[codelen];
    char* str1 = new char[codelen];

    str1[codelen] = '\0';
    for (int k = 0; k < codelen; k++) {
        key1[k] = (char)rand() % 255;
        str1[k] = line[k];
    }
    std::cout << "\nstr1:" << str1;
    char* codemsg = new char[codelen];
    for (int k = 0; k < codelen; k++) {
        codemsg[k] = str1[k] ^ key1[k];
    }
    codemsg[codelen] = '\0';
    printf("\nshifr:%s", codemsg);
    ofst << codemsg;
    ofst.close();
    ofst.close();

    cout << "\n-----------------------------------" << std::endl;
    cout << "Decode message:" << std::endl;
    pst.open("decode.txt");
    if (pst.is_open())
    {
        while (!pst.eof())
        {
            getline(pst, line);
            cout << line << endl;
        }
        pst.close();
    }
    else cout << "Unable to open file";
    cout << "----------------------------------" << endl;

}

int main() {
    setlocale(LC_ALL, "Russian");
    string line, key, mes1;
    int menu;
    std::ifstream ifst;
    std::ifstream ofst;
    int i = -1;
    while (i != 3)
    {
        cout << "Чтобы зашифровать нажмите 1" << endl;
        cout << "Чтобы расшифровать нажмите 2 " << endl;
        cout << "Чтобы выйти нажмите 3" << endl;
        std::cin >> i;
        if (i == 1) {
            crypt(key); break;
        }
        if (i == 2)
            decrypt(key); break;

    }



}