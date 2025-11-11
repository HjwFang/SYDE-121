#include "large_sum.h"

string num1, num2;

int main(){
    while (true){
        enter_nums(num1, num2);

        if (num1 == "-1" || num2 == "-1"){
            cout << "The End" << endl;
            return 0;
        }

        if (num1[0] < 0 || num2[0] < 0 || cin.fail() || num1.length() > 20 || num2.length() > 20){
            return 1;
        }

        display_num(add_large_numbers(num1, num2));
    }
}

void enter_nums(string &num1, string &num2){
    cout << "num 1/num 2: " << endl;
    cin >> num1 >> num2;
    return;
}

string add_large_numbers(string num1, string num2){
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    int carry = 0;
    string result = "";

    while (i >= 0 || j >= 0 || carry > 0){
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;
        
        int sum = digit1 + digit2 + carry;
        carry = sum / 10; 
        int digitResult = sum % 10; 
        
        result = char('0' + digitResult) + result;  
        
        i--;
        j--;
    }
    
    return result;
}

void display_num(string result){
    while (result.length() > 1 && result[0] == '0'){
        result = result.substr(1);
    }

    cout << "Sum: " << result << endl << endl;
    return;
}