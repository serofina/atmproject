#include <iostream>
#include <iomanip>
using namespace std;

//user sign in and return account number
int signIn()
{
    //get user's choice
    int userChoice;
    cout
        << "Please choose an account (0-9) to start: ";
    cin >> userChoice;
    cout << "You chose account #" << userChoice << endl;
    //check if account number is valid
    if (userChoice > 9 || userChoice < 0)
    {
        cout
            << "You have entered and invalid account number." << endl
            << "Please enter a valid account number between 0-9." << endl;
        userChoice = signIn();
    }
    return userChoice;
}

//output current balance
void checkBalance(int accountNumber, int currentBalance)
{

    //display current balance
    cout
        << "Here is the current balance in account #"
        << accountNumber
        << ": "
        << currentBalance << endl;
    //show low balance status if <= 100
    if (currentBalance <= 100)
    {
        cout << "Balance Status: "
             << "Low Balance" << endl;
    }
}

//output deposit and return updated balance
int deposit(int accountNumber, int currentBalance, int attempts)
{
    //initialize updated balance
    int updatedBalanace = currentBalance;

    //get amount to deposit
    int depositAmount;
    cout << "Deposit Amount: ";
    cin >> depositAmount;
    cout << endl;
    //check if the input amount is valid
    if (depositAmount < 0)
    {
        cout
            << "The despit amount is invalid." << endl
            << "Please enter a positive integer value." << endl;
        attempts++;
        if (attempts == 2)
        {
            cout
                << "You have entered an invalid deposit amount." << endl
                << "Terminating deposit request and returning to main menu ... " << endl;
            return updatedBalanace;
        }
        else
        {
            deposit(accountNumber, currentBalance, attempts);
        }
    }
    updatedBalanace += depositAmount;
    return updatedBalanace;
}

//output withdraw and return updated balance
int withdraw(int accountNumber, int currentBalance, int attempts)
{
    //initialize updated balance
    int updatedBalanace = currentBalance;

    //get amount to deposit
    int widthdrawalAmount;
    cout << "withdrawal Amount: ";
    cin >> widthdrawalAmount;
    cout << endl;
    //check if the input amount is valid
    if (widthdrawalAmount > currentBalance)
    {
        cout
            << "The despit amount is invalid." << endl
            << "You are attempting to widthdraw more than the current balance." << endl;
        attempts++;
        if (attempts == 2)
        {
            cout
                << "You have entered an invalid withdrawal amount." << endl
                << "Terminating withdrawal request and returning to main menu ... " << endl;
            return updatedBalanace;
        }
        else
        {
            withdraw(accountNumber, currentBalance, attempts);
        }
    }
    updatedBalanace -= widthdrawalAmount;
    return updatedBalanace;
}

//display menu and store user choice
int displayMenu(int accountNumber, int accountArray[])
{
    int userChoice;
    cout
        << "Please choose an option:" << endl
        << "1. Sign in" << endl
        << "2. Balance" << endl
        << "3. Deposit" << endl
        << "4. Withdraw" << endl
        << "5. Exit" << endl;
    cin >> userChoice;

    switch (userChoice)
    {
    case 1:
    {
        //select account number
        accountNumber = signIn();
        displayMenu(accountNumber, accountArray);
        break;
    }
    case 2:
    {
        //check balance
        checkBalance(accountNumber, accountArray[accountNumber]);
        displayMenu(accountNumber, accountArray);
    }
    break;
    case 3:
    {
        //deposit
        int depositAttempts = 0;
        int updatedDepositedBalanace = deposit(accountNumber, accountArray[accountNumber], depositAttempts);
        accountArray[accountNumber] = updatedDepositedBalanace;
        displayMenu(accountNumber, accountArray);
        break;
    }
    case 4:
    {
        //withdraw
        int widthdrawAttempts = 0;
        int updatedWidthdrawnBalanace = withdraw(accountNumber, accountArray[accountNumber], widthdrawAttempts);
        accountArray[accountNumber] = updatedWidthdrawnBalanace;
        displayMenu(accountNumber, accountArray);
        break;
    }
    case 5:
    {
        cout << "Good Bye" << endl;
        break;
    }
    default:
    {
        cout
            << "You have entered and invalid option." << endl
            << "Please try again ..." << endl;
        displayMenu(accountNumber, accountArray);
    }
    }
    return 0;
}

int main()
{
    //show welcome message
    cout << "Welcome to the Bank of Serofina!" << endl;
    //initialize account number
    int accountNumber = signIn();
    //initialize account balance array to $1000 for each index
    const int maxArrayIndex = 10;
    const int maxBalance = 1000;
    int accountArray[maxArrayIndex];
    for (int i = 0; i < maxArrayIndex; i++)
    {
        accountArray[i] = maxBalance;
    }
    displayMenu(accountNumber, accountArray);

    return 0;
}
