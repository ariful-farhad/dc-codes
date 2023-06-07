#include <bits/stdc++.h>

using namespace std;



string addBinaryStrings(const string& binary1, const string& binary2) {
    string result;
    int carry = 0;
    int length1 = binary1.length();
    int length2 = binary2.length();
    int maxLength = max(length1, length2);

    for (int i = 0; i < maxLength; i++) {
        int bit1 = (i < length1) ? (binary1[length1 - 1 - i] - '0') : 0;
        int bit2 = (i < length2) ? (binary2[length2 - 1 - i] - '0') : 0;
        int sum = bit1 + bit2 + carry;
        carry = sum / 2;
        result.insert(0, to_string(sum % 2));
    }

    if (carry > 0) {
        result.insert(0, to_string(carry));
    }

    return result;
}


string convertToBinaryString(int number) {


    bitset<11> binary(number);
    string binaryString = binary.to_string();
    cout<<binary<<endl;
    // creating the binary number before 1's compliment

    while(binaryString.size()>8)
    {
        string firstPart = binaryString.substr(0, binaryString.size()-8);
        binaryString.erase(0, binaryString.size()-8);
        binaryString = addBinaryStrings(firstPart, binaryString);
    }


    // 1's compliment

    string result = "";
    for(int i=0; i<binaryString.size(); i++){
        if(binaryString[i]=='1')
            result+='0';
        else 
        result+='1';
    }

    cout<<"before 1's compliment "<<binaryString<<endl;
    return result;
}


int main() {
    int number = 1275;


    // bitset<11> ss(31);
    // cout<<ss<<endl; 

    
    
    string binaryString = convertToBinaryString(number);

    
    cout << "final codeword " << binaryString << endl;

    return 0;
}
