// UART_Sandbox.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SerialPort.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <cstdlib>
using namespace std;

char output[MAX_DATA_LENGTH];
const char* port= "\\\\.\\COM4";
char incoming[MAX_DATA_LENGTH];

int main() {

    SerialPort arduino(port);
    if(arduino.isConnected()){
        cout<<"Connection is Established";
    }
    else{
        cout<<"Error in port name";
    }
    while (arduino.isConnected()){
        string command;

        for(int i=0; i<6; i++){
            if(i%3==0){
                command="block1";
                char* charArray = new char[command.size()+1];
                copy(command.begin(),command.end(),charArray);
                charArray[command.size()]= '\n';

                arduino.writeSerialPort(charArray,MAX_DATA_LENGTH);
                //arduino.readSerialPort(output,MAX_DATA_LENGTH);

                //cout<<output;

                delete [] charArray;
            }
            if(i%3==1){
                command="block2";
                char* charArray = new char[command.size()+1];
                copy(command.begin(),command.end(),charArray);
                charArray[command.size()]= '\n';

                arduino.writeSerialPort(charArray,MAX_DATA_LENGTH);
                //arduino.readSerialPort(output,MAX_DATA_LENGTH);

                //cout<<output;

                delete [] charArray;
            }
            if(i%3==2){
                command="block3";
                char* charArray = new char[command.size()+1];
                copy(command.begin(),command.end(),charArray);
                charArray[command.size()]= '\n';

                arduino.writeSerialPort(charArray,MAX_DATA_LENGTH);
                //arduino.readSerialPort(output,MAX_DATA_LENGTH);

                //cout<<output;

                delete [] charArray;
            }
            Sleep(1000);
        }

    }

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
