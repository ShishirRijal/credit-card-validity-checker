/*
    A c++ program to check the validity of card based on Luhn's algorithm.
    2022-05-14
*/

#include <iostream>
using namespace std;

// User-defined functions declaraction..
void displayResult(int);
int getOddSum(string);
int getEvenSum(string);
bool check(string);

// driver funciton of our program
int main()
{
    string card; // 16 digits card number
    int oddSum = 0, evenSum = 0, total = 0, length;
    bool hasOnlyNumbers;
    cout << "Enter the card number: ";
    cin >> card;
    hasOnlyNumbers = check(card);
    // if the card number has characters other than the numbers
    // exit the program...
    if (!hasOnlyNumbers)
    {
        cout << "Invalid card number." << endl;
        exit(0);
    }
    oddSum = getOddSum(card);
    evenSum = getEvenSum(card);
    total = oddSum + evenSum;
    displayResult(total);
    return 0;
}

// User-defined functions
bool check(string card)
{
    for (int i = 0; i < card.length(); i++)
    {
        // check if the charactes are number or not..
        if (card[i] < 48 || card[i] > 57)
            return false;
    }
    return true;
}

int getOddSum(string card)
{

    int length = card.length();
    int result = 0;
    // let's get the sum of digits at odd place...
    for (int i = length - 1; i >= 0; i -= 2)
    {
        // '0' = 48
        // So subtracting 48 from given character's decimal value we get the number
        int digit = card[i] - 48;
        result += digit;
    }
    return result;
}

int getEvenSum(string card)
{
    int length = card.length();
    int result = 0;
    // let's analayze the digits at even place..
    for (int i = length - 2; i >= 0; i -= 2)
    {
        int digit = card[i] - 48;
        // double the digit at even place
        int dbl = digit * 2;
        // if the doubled number is greater than 9, then add the digits of that number
        // i.e. 9*2 = 18 = 1 + 8
        result += (dbl / 10) + (dbl % 10);
    }
    return result;
}

void displayResult(int sum)
{
    cout << "###############################################" << endl;
    if (sum % 10 == 0)
        cout << "The card is valid." << endl;
    else
        cout << "The card is invalid" << endl;
    cout << "###############################################" << endl;
}
