// Iress_ToyRobot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include <errno.h>

#include "Global.h"
#include "Controller.h"

/* Command IDs */
typedef enum tagCommand {
    COMM_UNSUPPORTED = -1,
    COMM_PLACE = 0,
    COMM_MOVE,
    COMM_LEFT,
    COMM_RIGHT,
    COMM_REPORT
} Command;

using namespace std;

// Controller instance, the Controller is in charge of processing any command coming from the raw input
Controller m_controller;

/*
* Parse and process the command by calling Controller functions
* 
* Parameters:
*   line    : 1 line of input
*/
void ProcessLine(string line) {
    // initially assume that the line parsed is an unsupported command and any parameters that follow (x, y, face) are
    // also unsupported
    Command command = COMM_UNSUPPORTED;
    long x = POS_NOTSET;
    long y = POS_NOTSET;
    Face face = FACE_NOTSET;

    // variables to hold the tokens after parsing based on ' ' (space) delimiter
    vector<string> tokens;
    string token;

    stringstream ss(line);

    // read each token and put in vector
    while (getline(ss, token, ' ')) {
        tokens.push_back(token);
    }

    if (tokens[0] == "PLACE" && tokens.size() == 2) {
        // get succeeding token and treat as params to PLACE command
        vector <string> place_tokens;
        string place_token;

        stringstream place_ss(tokens[1]);

        // parse, delimiter = ',' (comma char)
        while (getline(place_ss, place_token, ',')) {
            place_tokens.push_back(place_token);
        }

        if (place_tokens.size() == 3) {
            // convert to long and check if valid and no trailing unsupported chars
            char* end = NULL;
            errno = 0;

            // try to convert the first argument to long
            x = strtol(place_tokens[0].c_str(), &end, 10);

            // if successfull, proceed. otherwise, discard the line
            if (errno != 0 ||
                (errno == 0 && *end == 0)) {

                // try to convert the second argument to long
                y = strtol(place_tokens[1].c_str(), &end, 10);

                // if successfull, proceed. otherwise, discard the line
                if (errno != 0 ||
                    (errno == 0 && *end == 0)) {

                    // check if the third argument is a valid face (string)
                    if (place_tokens[2] == "NORTH") {
                        face = FACE_N;
                        command = COMM_PLACE;
                    }
                    else if (place_tokens[2] == "SOUTH") {
                        face = FACE_S;
                        command = COMM_PLACE;
                    }
                    else if (place_tokens[2] == "EAST") {
                        face = FACE_E;
                        command = COMM_PLACE;
                    }
                    else if (place_tokens[2] == "WEST") {
                        face = FACE_W;
                        command = COMM_PLACE;
                    }
                    else {
                        // cout << "Invalid face or direction. Supported: NORTH, SOUTH, EAST, WEST. Case sensitive." << endl;
                    }
                }
            }
            else {
                // cout << "Failed to convert x or y to long" << endl;
            }
        }
        else {
            // cout << "Invalid PLACE Command parameters" << endl;
        }
    }
    else if (token == "MOVE" && tokens.size() == 1) {
        command = COMM_MOVE;
    }
    else if (token == "LEFT" && tokens.size() == 1) {
        command = COMM_LEFT;
    }
    else if (token == "RIGHT" && tokens.size() == 1) {
        command = COMM_RIGHT;
    }
    else if (token == "REPORT" && tokens.size() == 1) {
        command = COMM_REPORT;
    }
    else {
        // cout << "Invalid command. Ignore and move to next line." << endl;
    }

    // if line is a valid command, process it
    if (command != COMM_UNSUPPORTED) {
        switch (command) {
        case COMM_PLACE:
            m_controller.Place(x, y, face);
            break;
        case COMM_MOVE:
            m_controller.Move();
            break;
        case COMM_LEFT:
            m_controller.Left();
            break;
        case COMM_RIGHT:
            m_controller.Right();
            break;
        case COMM_REPORT:
            m_controller.Report();
            break;
        default:
            // execution should not reach this point
            break;

        }
    }
}


int main(int argc, char *argv[])
{
    string line;

    // if user provided at least 1 argument, use the first argument as filename and open it
    // otherwise, wait for user input from stdin
    if (argc > 1) {
        ifstream inputFile(argv[1]);

        if (inputFile.is_open()) {
            while (getline(inputFile, line)) {
                ProcessLine(line);
            }
        }
        else {
            cout << "unable to open " << argv[1] << endl;
        }
    }
    else {
        while (getline(std::cin, line)) {
            ProcessLine(line);
        }
    }

    return 0;
}
