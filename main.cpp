#include <bits/stdc++.h>
#include "Result.h"
using namespace std;

void init(int &n, int &binomial, vector<int> &coefficients);
void perform(int n, int binomial, const vector<int> &coefficients, vector<int> &result);
void print(int n, int binomial, const vector<int> &coefficients, const vector<int> &result);
void printPolynomial(const vector<int> &coefficients, int pow, int i);
void clear();

void readKey();

int getInt(int &n);

class Result;

int main() {
    bool menu = true;
    vector<Result> history;
    while(menu){
        cout << "Menu:" << endl;
        cout << "1. New calculation" << endl << "2. Show history" << endl << "3. Exit" << endl;
        int choice = getInt(choice);
        switch(choice){
            case 1:{
                clear();
                int n, binomial;
                vector<int> coefficients, result;
                init(n, binomial, coefficients);
                perform(n, binomial, coefficients, result);
                cout << "Result: ";
                print(n, binomial, coefficients, result);
                Result historyResult;
                historyResult.coefficients = coefficients;
                historyResult.result = result;
                historyResult.n = n;
                historyResult.binomial = binomial;
                history.push_back(historyResult);
                readKey();
                break;
            }
            case 2:{
                clear();
                if(history.empty()){
                    cout << "History is empty. Solve new calculations" << endl;
                }
                else{
                    cout << "History:" << endl;
                    int count = 0;
                    for (auto &i : history) {
                        printf("№%d: ", ++count);
                        print(i.n, i.binomial, i.coefficients, i.result);
                    }
                }
                readKey();
                break;
            }
            case 3:{
                menu = false;
                break;
            }
            default:
                clear();
                continue;
        }
    }
    return 0;
}

void readKey() {
    do
    {
        cout << "Press any key to return...";
    } while (cin.get() != '\n');
    cin.get();
    clear();
}

void clear()
{
    cout << "\033[2J\033[1;1H";
}

void init(int &n, int &binomial, vector<int> &coefficients) {
    cout << "Enter highest degree number: ";
    n = getInt(n);
    int pow = n;
    while(pow >= 0){
        int coefficient;
        printf("Enter %d degree number: ", pow);
        coefficient = getInt(coefficient);
        coefficients.push_back(coefficient);
        --pow;
    }
    cout << "Enter binomial coefficient: ";
    binomial = getInt(binomial);
}

int getInt(int &n) {
    double input;
    while (true)
    {
        cin >> n;
        if(!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a numeric value!" << endl;
            continue;
        }
        else {
            break;
        }
    }
    return n;
}

void perform(int n, int binomial, const vector<int> &coefficients, vector<int> &result) {
    result.push_back(coefficients[0]);
    int i = 0;
    while(i < n){
        result.push_back(binomial * result[i] + coefficients[i+1]);
        ++i;
    }
}

void print(int n, int binomial, const vector<int> &coefficients, const vector<int> &result) {
    int pow = n, i = 0;
    cout << "(";
    while(i <= n){
        printPolynomial(coefficients, pow, i);
        if(coefficients[i] != 0 && pow >= 1 && coefficients[i+1] > 0){
            cout << "+";
        }
        ++i;
        --pow;
    }
    if(binomial > 0){
        printf(")/(x-%d) = (", binomial);
    }
    else{
        printf(")/(x+(%d)) = (", binomial);
    }

    pow = n-1;
    i = 0;
    while(i < n){
        printPolynomial(result, pow, i);
        if(result[i] != 0 && pow > 0 && result[i+1] > 0){
            cout << "+";
        }
        ++i;
        --pow;
    }
    if(result[n] >= 0){
        cout << ")+" << result[n];
    }
    else{
        cout << ")" << result[n];
    }
    cout << endl;
}

void printPolynomial(const vector<int> &coefficients, int pow, int i) {
    switch(coefficients[i]){
            case 0:
                break;
            case 1:
                switch(pow){
                    case 0:
                        cout << "1";
                        break;
                    case 1:
                        cout << "x";
                        break;
                    default:
                        printf("x^%d", pow);
                        break;
                }
                break;
            default:
                switch(pow){
                    case 0:
                        printf("%d", coefficients[i]);
                        break;
                    case 1:
                        printf("%dx", coefficients[i]);
                        break;
                    default:
                        printf("%dx^%d", coefficients[i], pow);
                        break;
                }
                break;
        }
}