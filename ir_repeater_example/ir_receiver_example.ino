#include <IRremote.h>

//Define the pin the receive is connected to
const int RECV_PIN = 7;
unsigned long keyValue = 0;

//We define an IRrecv object for the IR Receiver
IRrecv irrecv(RECV_PIN);

//We define a decodification results object
decode_results results;

void setup()
{
    //Start serial monitor
    Serial.begin(9600);

    //Enable the IR Receiver
    irrecv.enableIRIn();

    //Blink On-board LED when it receiver data
    irrecv.blink13(true);
}

void loop()
{
    //Returns true if a code is received
    if(irrecv.decode(&results))
    {
        // We avoid key repetition
        if(results.value == 0xFFFFFFFF)
            results.value = keyValue;

        //Prints out in serial monitor the value of results object in hexadecimal format
        Serial.println(results.value,HEX);

        //To avoid repetition, we asign results.value to the keyValue variable
        //And resume the data reading
        keyValue = results.value;
        irrecv.resume();
    }
}

