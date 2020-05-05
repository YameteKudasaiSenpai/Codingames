#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

class ChuckNorris {
    private:
        // Attributes
        string _message;
        
        // Methods
        const string bitConvert (const string message) noexcept;
    
    public:
        // Constructors
        ChuckNorris(string const& message) noexcept : _message(message) {}
        
        // Methods
        const string translate(void) noexcept;
};

int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);

    ChuckNorris *Boss = new ChuckNorris(MESSAGE);
    cout << Boss->translate() << endl;
    delete Boss;
}


// Implementation of ChuckNorris
const string ChuckNorris::bitConvert (const string message) noexcept
{
    string bitsConverted;
    
    for (int counter = 0; counter < message.length(); ++counter)
    {
        char s = message[counter];
        bitset<7> bits(s);
        bitsConverted += bits.to_string();
    }
    
    return bitsConverted;
}

const string ChuckNorris::translate(void) noexcept
{
    string binaryMsg = this->bitConvert(this->_message);
    
    string unaryMsg;
    char firstChar = binaryMsg[0];
    bool isOne;
    
    firstChar == '1' ? isOne = true : isOne = false;
    isOne == true ? unaryMsg.append("0 ") : unaryMsg.append("00 ");
    
    for(int i(1); i < binaryMsg.length(); ++i) {
        if( binaryMsg[i] == firstChar ) {
            unaryMsg.append("0");
        }
        else {
            unaryMsg.append("0 ");
            firstChar = binaryMsg[i];
            isOne = !isOne;
            isOne == true ? unaryMsg.append("0 ") : unaryMsg.append("00 ");
        }
    }
    
    return unaryMsg + "0";
}