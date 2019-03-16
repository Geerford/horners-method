#include <bits/stdc++.h>
using namespace std;

void init(int &n, int &binomial, vector<int> &coefficients, vector<int> &result);
void perform(int n, int binomial, const vector<int> &coefficients, vector<int> &result);
void print(int n, int binomial, const vector<int> &coefficients, const vector<int> &result);
void printPolynomial(const vector<int> &coefficients, int pow, int i);

int main() {
    int n, binomial;
    vector<int> coefficients, result;
    init(n, binomial, coefficients, result);
    perform(n, binomial, coefficients, result);
    print(n, binomial, coefficients, result);
    return 0;
}

void init(int &n, int &binomial, vector<int> &coefficients, vector<int> &result) {
    cout << "Enter highest degree number: ";
    cin >> n;
    int pow = n;
    while(pow >= 0){
        int coefficient;
        printf("Enter %d degree number: ", pow);
        cin >> coefficient;
        coefficients.push_back(coefficient);
        --pow;
    }
    cout << "Enter binomial coefficient: ";
    cin >> binomial;
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
        if(coefficients[i] != 0 && pow > 1 && coefficients[i+1] > 0){
            cout << "+";
        }
        ++i;
        --pow;
    }
    if(binomial > 0){
        printf(")/(x+%d) = (", binomial);
    }
    else{
        printf(")/(x%d) = (", binomial);
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