#include <iostream>
using namespace std;

void toRoman(int decimal){
    cout << "Is: ";
    while (decimal != 0) {
        if (decimal / 1000) {cout << "M"; decimal-=1000;}
        else if(decimal / 500) {cout << "D";decimal-=500;}
        else if(decimal / 100) {cout << "C";decimal-=100;}
        else if(decimal / 100) {cout << "C";decimal-=100;}
        else if(decimal / 50) {cout << "L";decimal-=50;}
        else if(decimal / 10) {cout << "X";decimal-=10;}
        else if(decimal / 5) {cout << "V";decimal-=5;}
        else if(decimal / 1) {cout << "I";decimal-=1;}

    }
    cout << " in roman" << endl;
};

int toDecimal(char roman_char){
    //cout << "character: " << roman_char<< endl;
    int decimal = 0;
    if (roman_char == 'I'){decimal = 1;}
    else if (roman_char == 'V'){decimal = 5;}
    else if (roman_char == 'X'){decimal = 10;}
    else if (roman_char == 'L'){decimal = 50;}
    else if (roman_char == 'C'){decimal = 100;}
    else if (roman_char == 'D'){decimal = 500;}
    else if (roman_char == 'M'){decimal = 1000;}
    else {
        cout<<"Invalid Character"<< endl;
        decimal= -1;}
    return decimal;
};

//Checks if the the roman numeral is a valid input
bool isValid(string input_text){
    bool isValid = true;
    //cout <<"Checking if valid " <<endl;
    int prev = toDecimal(input_text[0]);
    for (int i=0; i<input_text.size();i++){
        int curr_char = toDecimal(input_text[i]);
        if (curr_char >(prev*10)+1){
            cout<< "larger input"<< endl;
            isValid = false;
        }
    prev = curr_char;
    }
    return isValid;
};

//Decodes Valid Roman Numeral to Decimal
void decodeText(string input_text){
    int total =0;
    int prev = toDecimal(input_text[0]);
    for (int i=0; i<input_text.size();i++){
        int curr_char = toDecimal(input_text[i]);
        //cout <<"Decoding " << curr_char <<endl;
        if (prev<curr_char){
            //cout<< "subtracting"<< endl;
            total = (total-prev) +(curr_char-prev);
            prev = 999999;
        }
        else if(curr_char<=prev){
            //cout<< "adding"<< endl;
            total = curr_char + total;
            prev = curr_char;
        }
    }
    cout << input_text<<  " converts to " << total << " in Decimal"<< endl;
};



int main(int argc, char *argv[]) {
    string input_text;

    bool repeat =true;
    while(repeat) {
        cout<< "Press A to convert from roman to decimal"<< endl;
        cout << "Press B to convert from decimal to roman (currently does not support subtractive notation)"<< endl;
        cin >> input_text;
        if(input_text=="A"||input_text=="a") {
            cout << "Enter Roman Numeral Here:";
            cin >> input_text;
            if (isValid(input_text)) {
                cout << "Valid Numeral:" << endl;
                decodeText(input_text);
            } else {
                cout << "Invalid numeral:" << endl;
            }
        }
        else if (input_text=="B"||input_text=="b"){
            cout << "Enter Decimal Here:";
            int input_decimal;
            cin >> input_decimal;
            toRoman(input_decimal);
        }

        cout << "Enter Q to quit, to continue enter any character" << endl;
        cin>> input_text;
        if(input_text =="Q"||input_text =="q"){
            repeat = false;
        }
    }

    //test
    //decodeText("I");
    //decodeText("II");
    //decodeText("III");
    //decodeText("XIV");
    return 0;
}