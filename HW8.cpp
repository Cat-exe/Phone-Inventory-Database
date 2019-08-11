/*Homework Assignment 8
Author: Carol Pignato
Date: December 12, 2016
Comments: This program lets you read in a database of ten phones you are selling,
          prints the database of information in an orderly fashion, and
          prompts you to search for an item from a particular company that you would
          like to buy from.
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Name {
    public:
        string company;
        string pname;
};
class Phone {
    public:
        int productnum;
        double price;
        int quantityOnHand;
        Name name;
};

void readData (Phone[], int);
void printPhone (Phone[], int, int);
void printdb (Phone[], int);
int findCompany (Phone[], int, string);

int main() {
    const int n=10;
    Phone phones[n];
    readData(phones,n);
    printdb(phones,n);
    string item;
    cout << "Enter the company of an item you would like to find: ";
    getline(cin, item);
    int f = findCompany (phones, n, item);
    if (f!=-1)
        printPhone(phones, n, f);
    return 0;
}

//This function reads in all data about 10 phones from hw8input.txt.
void readData (Phone p[], int n) {
    ifstream db;
    db.open("hw8input.txt");
    for (int i=0; i<n; i++) {
        db >> p[i].productnum >> p[i].price >> p[i].quantityOnHand
           >> p[i].name.company >> p[i].name.pname;
        cout << endl;
    }
    db.close();
}
//This function holds the design that will be printed for each phone.
void printPhone (Phone p[], int n, int i) {
     cout << endl << "Product Number: #" << p[i].productnum << endl
          << p[i].name.company << " " << p[i].name.pname << endl
          << "Price: $" << p[i].price << endl
          << "[" << p[i].quantityOnHand << "] in stock." << endl
          << "_________________________________" << endl << endl;

}
//This function calls the printPhone function for each phone.
void printdb (Phone p[], int n) {
    for (int i=0; i<n; i++)
        printPhone(p, n, i);
}
//This function searches for the company name of an item in the database.
int findCompany (Phone p[], int n, string key) {
    size_t found=0;
    for (int i=0; i<n; i++) {
        found = p[i].name.company.find(key, 0);
        if (found!=string::npos){
            cout << "Found in location: " << i << endl;
            return i;
        }
    }
    cout << "Not found." << endl;
    return -1;
}



