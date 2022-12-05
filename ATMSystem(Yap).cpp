#include <iostream>

using namespace std;

int main()
{
    int mainBit=1, balBit=1, accBit=1;
    double deposit, withdraw=0, total=0;
    char mainChoice, balChoice;
    string id, password, idVal, passwordVal;

        cout << "=================================================" << endl;
        cout << "Virtual ATM Machine" << endl;

    while(mainBit==1)
    {
        cout << "=================================================" << endl;
        cout << "Please select an option from the menu below:" << endl << endl;
        cout << "(A) Login" << endl;
        cout << "(B) Create New Account" << endl;
        cout << "(C) Quit" << endl << endl << "> ";
        cin >> mainChoice;
        cin.ignore();

        switch(mainChoice)
        {
            case 'A':
            case 'a':
                if (id == "" && password == "")
                {
                    cout << endl << "No Account Registered!" << endl;
                    break;
                }

                cout << "=================================================" << endl;
                cout << "Please enter your ID: ";
                getline(cin, idVal);
                cout << "Please enter your password: ";
                getline(cin, passwordVal);

                if (idVal == id && password == passwordVal){
                    cout << "ACCESS GRANTED!" << endl;
                    while(mainBit == 1){
                        cout << "=================================================" << endl;
                        cout << "Choose an action:" << endl << endl;
                        cout << "(1) Deposit Money" << endl;
                        cout << "(2) Withdraw Money" << endl;
                        cout << "(3) View Balance" << endl;
                        cout << "(4) Quit" << endl << endl << "> ";
                        cin >> balChoice;

                    switch(balChoice)
                    {
                        case '1':
                            cout << "=================================================" << endl;
                            cout << "Deposit Amount: P";
                            cin >> deposit;
                            cout << "P" << deposit << " deposited" << endl;
                            total += deposit;
                            cout << "P" << total << " in machine" << endl;
                            break;

                        case '2':
                            cout << "=================================================" << endl;
                            while(balBit == 1)
                            {
                                cout << "Withdraw Amount: P";
                                cin >> withdraw;
                                if(withdraw <= deposit)
                                {
                                    cout << "P" << withdraw << " withdrawn" << endl;
                                    total -= withdraw;
                                    cout << "P" << total << " in machine" << endl;
                                    balBit--;
                                }
                                else
                                {
                                    cout << "Please withdraw a valid amount" << endl;
                                    cout << "=================================================" << endl;
                                }
                            }
                            balBit++;
                            break;

                        case '3':
                            cout << "=================================================" << endl;
                            cout << "Account Balance: P" << total << endl;
                            break;

                        case '4':
                            cout << "=================================================" << endl;
                            cout << "Thank you for using Virtual ATM Machine!" << endl;
                            mainBit--;
                            return 0;
                            break;

                        default:
                            cout << endl << "Please enter a valid option" << endl;
                            break;
                    }
                }
            }
            else
            {
                cout << "LOGIN FAILED!" << endl;
                break;
            }

        case 'B':
        case 'b':
            cout << "=================================================" << endl;
            cout << "Please enter your new ID: ";
            getline(cin, id);
            while(accBit == 1)
            {
                cout << "Please enter your new password: ";
                getline(cin, password);
                if(password.length() <= 5)
                {
                    cout << "Please create a SECURE PASSWORD!" << endl;
                    cout << "=================================================" << endl;
                }
                else
                {
                    cout << "Account Registered!" << endl;
                    accBit--;
                }
            }
            accBit++;
            break;

        case 'C':
        case 'c':
            cout << "=================================================" << endl;
            cout << "Thank you for using Virtual ATM Machine!" << endl;
            mainBit--;
            return 0;

        default:
            cout << endl << "Please enter a valid option" << endl;
        }
    }
}
