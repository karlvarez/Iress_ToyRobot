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

using namespace std;    

Controller m_controller;


void ProcessLine(string line) {
    Command command = COMM_UNSUPPORTED;
    long x = POS_NOTSET;
    long y = POS_NOTSET;
    Face face = FACE_NOTSET;

    vector<string> tokens;
    string token;

    stringstream ss(line);

    while (getline(ss, token, ' ')) {
        tokens.push_back(token);
    }

    if (tokens[0] == "PLACE" && tokens.size() == 2) {
        // get succeeding token and treat as params to PLACE command
        vector <string> place_tokens;
        string place_token;

        stringstream place_ss(tokens[1]);

        while (getline(place_ss, place_token, ',')) {
            place_tokens.push_back(place_token);
        }

        if (place_tokens.size() == 3) {
            // convert to long and check if valid and no trailing unsupported chars
            char* end = NULL;
            errno = 0;
            x = strtol(place_tokens[0].c_str(), &end, 10);
            y = strtol(place_tokens[1].c_str(), &end, 10);

            if (errno != 0 ||
                (errno == 0 && *end == 0)) {
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

    if (argc > 1) {
        ifstream inputFile(argv[1]);
        if (inputFile.is_open()) {
            while (getline(inputFile, line)) {
                ProcessLine(line);
            }
        }
    }
    else {
        while (getline(std::cin, line)) {
            ProcessLine(line);
        }
    }

    return 0;
}

