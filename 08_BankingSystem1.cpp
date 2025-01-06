#include <iostream>
#include<vector>
#include<fstream>
#include<windows.h>
#include<sstream>
#include<time.h>
using namespace std;

class Account{
string AccountHolderName;
long long AccountNumber;
double balance;
vector<string> TransactionHistory;
public:
Account() : AccountHolderName(""),AccountNumber(0),balance(0){}
void setAccountNumber(long long number);
void setAccountHolderName(string name);
void setAccountBalance(double bal);
long long getAccountNumber();
string getAccountHolderName();
double getAccountBalance();
};

void Account :: setAccountNumber(long long number){
AccountNumber = number;
}
void Account :: setAccountHolderName(string name){
    AccountHolderName = name;
}

void Account :: setAccountBalance(double bal){
    balance = bal;
}

long long Account :: getAccountNumber(){
    return AccountNumber;
}

string Account :: getAccountHolderName(){
    return AccountHolderName;
}

double Account :: getAccountBalance(){
    return balance;
}



void openAccount(Account user){
system("cls");
string name;
long long accNo;
srand(time(0));
accNo = rand()%999999999999 + 100000000000;

ifstream infile("D:/accounts.txt");
if(!infile){
    cout<<"Error! file not opening"<<endl;
}

string line;

while(getline(infile,line)){
    stringstream ss;
    ss<<line;

    string userName;
    long long userAccNo;
    double userbalance;
    char delimeter;

    ss>>userAccNo>>delimeter>>userName>>delimeter>>userbalance;
    if(accNo == userAccNo){
        srand(time(0));
        accNo = rand()%999999999999 + 100000000000;
    }

}
user.setAccountNumber(accNo);
cout<<"Your account number is: "<<user.getAccountNumber()<<endl;

cout<<"\tEnter account holder name: ";
cin.ignore();
getline(cin,name);
user.setAccountHolderName(name);

user.setAccountBalance(0);

ofstream outFile("D:/accounts.txt",ios :: app);
if(!outFile){
    cout<<"\tError: File can't open!"<<endl;
}
else{
    outFile<<"\t"<<user.getAccountNumber()<<" : "<<user.getAccountHolderName()<<" : "<<user.getAccountBalance()<<endl;
    cout<<"\tAccount created succesfully"<<endl;
}
outFile.close();
Sleep(3000);
}

void depositeAmount(){
    system("cls");
    string AccNo;
    cout<<"Enter account No: ";
    cin>>AccNo;

    ifstream inFile("D:/accounts.txt");
    ofstream outFile("D:/accounts temp.txt");
    if(!inFile || !inFile){
        cout<<"Error: file can't open!"<<endl;
    }
    string line;
    bool found = false;

    while(getline(inFile,line)){
        stringstream ss;
        ss<<line;
        string userAccNo,userName;
        double userBalance;
        char delimeter;

        ss>>userAccNo>>delimeter>>userName>>delimeter>>userBalance;
        if(AccNo == userAccNo){
            found = true;
            double amount;
            cout<<"Enter amount ot deposite: ";
            cin>>amount;
            double newbalance = userBalance + amount;
            userBalance = newbalance;
            outFile<<"\t"<<userAccNo<<" : "<<userName<<" : "<<userBalance<<endl;
            cout<<"\tYour Balance is: "<<userBalance<<endl;
        }
        else{
            outFile<<line<<endl;
        }
        
    }
    if(!found){
            cout<<"Account not found"<<endl;
        }
        outFile.close();
        inFile.close();
        remove("D:/accounts.txt");
        rename("D:/accounts temp.txt","D:/accounts.txt");
    Sleep(5000);
}

void withdrawAmount(){
    system("cls");
    string AccNo;
    cout<<"Enter account number: ";
    cin>>AccNo;

    ifstream infile("D:/accounts.txt");
    ofstream outfile("D:/accounts temp.txt");
    if(!infile || !outfile){
        cout<<"Error: file can't not open!"<<endl;
    }

    string line;
    bool found = false;

    while(getline(infile,line)){
        stringstream ss;
        ss<<line;

        string userAccNo,userName;
        double userbal;
        char delimeter;
        ss>>userAccNo>>delimeter>>userName>>delimeter>>userbal;
        if(AccNo == userAccNo){
            found = true;
            double amount;
            cout<<"Enter amount to withdraw: ";
            cin>>amount;
            if(amount>0 && amount<userbal){
            double newbalance = userbal - amount;
            userbal = newbalance;
            outfile<<"\t"<<userAccNo<<" : "<<userName<<" : "<<userbal<<endl;
            }
            else{
                cout<<"You have only amount: "<<userbal<<endl;
            }
        }
        else{
            outfile<<line<<endl;
        }
    }
    if(!found){
        cout<<"Error: account not found"<<endl;
    }
    infile.close();
    outfile.close();
    remove("D:/accounts.txt");
    rename("D:/accounts temp.txt","D:/accounts.txt");
    Sleep(2000);
}

void checkBalance(){
    system("cls");
    string AccNo;
    cout<<"Enter account Number: ";
    cin>>AccNo;

    ifstream infile("D:/accounts.txt");
    if(!infile){
        cout<<"Error: file can't open"<<endl;
    }
    string line;
    bool found = false;

    while(getline(infile,line)){
        stringstream ss;
        ss<<line;

        string userAccNo,userName;
        double userbalance;
        char delimeter;

        ss>>userAccNo>>delimeter>>userName>>delimeter>>userbalance;
        if(AccNo == userAccNo){
            found = true;
            cout<<"Your account balance is: "<<userbalance<<endl;
        }
        
    }
    if(!found){
        cout<<"Account not found"<<endl;
    }
    infile.close();

    Sleep(2000);
}

void deleteAccount(){
    system("cls");
    string AccNo;
    cout<<"Enter account number: ";
    cin>>AccNo;

    ifstream infile("D:/accounts.txt");
    ofstream outfile("D:/accounts temp.txt");
    if(!infile || !outfile){
        cout<<"Error: file not opening"<<endl;
    }

    string line;
    bool found = false;

    while(getline(infile,line)){
        stringstream ss;
        ss<<line;

        string userAccNo,userName;
        double userbalance;
        char delimeter;
        ss>>userAccNo>>delimeter>>userName>>delimeter>>userbalance;
        if(AccNo == userAccNo){
            found = true;
        }
        else{
            outfile<<line<<endl;
        }
    }
    if(!found){
        cout<<"Error: file is not found"<<endl;
    }
    infile.close();
    outfile.close();
    remove("D:/accounts.txt");
    rename("D:/accounts temp.txt","D:/accounts.txt");

}

int main() {
    Account user;
    int choice;

    do{
        //  system("cls");
        cout<<"\t************BankingSystem**************"<<endl;
        cout<<"\t1. open account"<<endl
            <<"\t2. Deposite amount"<<endl
            <<"\t3. Withdraw amount"<<endl
            // <<"\t4. view transaction history"<<endl
            <<"\t5. check balance of account"<<endl
            <<"\t6. delete account"<<endl
            <<"\t0. Exit the system"<<endl;
        cout<<"Choose from these"<<endl;
        cin>>choice;
        switch(choice){
            case 1:{
                openAccount(user);
                break;
            }
            case 2:{
                depositeAmount();
                break;
            }
            case 3:{
                withdrawAmount();
                break;
            }
            case 5:{
                checkBalance();
                break;
            }
            case 6:{
                deleteAccount();
            }
            case 0:{
                cout<<"\tExiting the system"<<endl;
            }

        }
    }while(choice!=0);

    
    return 0;
}
