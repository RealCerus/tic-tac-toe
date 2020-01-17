#include <iostream>
#include <random>
#include <ctime>

using namespace std;

void draw_grid();

bool eval_grid();

void request_move();

void make_move();

const char player_computer = 'x';
const char player_person = 'o';

char grid[] = {
        ' ', ' ', ' ',
        ' ', ' ', ' ',
        ' ', ' ', ' '
};

int main() {
    cout << "Tic Tac Toe" << endl;
    cout << "Welcome! To start simply enter something." << endl;
    cout << endl;

    auto *tmpStr = new string;
    cin >> *tmpStr;
    delete tmpStr;

    cout << "Alright, lets begin!" << endl;
    cout << endl;

    draw_grid();
    cout << endl;

    cout << "I'll make the first move." << endl;
    cout << endl;

    srand(time(0));
    grid[rand() % 9] = player_computer;

    draw_grid();
    cout << endl;

    request_move();
    return 0;
}

void draw_grid() {
    cout << "   A   B   C" << endl;
    cout << "1 [" << grid[0] << "] [" << grid[1] << "] [" << grid[2] << "]" << endl;
    cout << "2 [" << grid[3] << "] [" << grid[4] << "] [" << grid[5] << "]" << endl;
    cout << "3 [" << grid[6] << "] [" << grid[7] << "] [" << grid[8] << "]" << endl;
}

bool eval_grid() {
    for (int idx = 0; idx < 3; idx++) {
        if (grid[idx * 3] == player_computer && grid[idx * 3 + 1] == player_computer &&
            grid[idx * 3 + 2] == player_computer) {
            cout << "Computer won" << endl;
            return true;
        } else if (grid[idx * 3] == player_person && grid[idx * 3 + 1] == player_person &&
                   grid[idx * 3 + 2] == player_person) {
            cout << "Player won" << endl;
            return true;
        }
    }
    for (int idx = 0; idx < 3; idx++) {
        if (grid[idx] == player_computer && grid[idx + 3] == player_computer &&
            grid[idx + 6] == player_computer) {
            cout << "Computer won" << endl;
            return true;
        } else if (grid[idx] == player_person && grid[idx + 3] == player_person &&
                   grid[idx + 6] == player_person) {
            cout << "Player won" << endl;
            return true;
        }
    }

    if (grid[2] == player_computer && grid[4] == player_computer && grid[6] == player_computer) {
        cout << "Computer won" << endl;
        return true;
    } else if (grid[2] == player_person && grid[4] == player_person && grid[6] == player_person) {
        cout << "Player won" << endl;
        return true;
    }

    if (grid[0] == player_computer && grid[4] == player_computer && grid[8] == player_computer) {
        cout << "Computer won" << endl;
        return true;
    } else if (grid[0] == player_person && grid[4] == player_person && grid[8] == player_person) {
        cout << "Player won" << endl;
        return true;
    }

    return false;
}

void request_move() {
    cout << "Its your turn! Enter a number between 1 and 9!" << endl;

    int index;
    cin >> index;
    if(index < 1 || index > 9) {
        cout << "Index is not valid! Try again!" << endl;
        request_move();
        return;
    }
    index--;

    if(grid[index] != ' ') {
        cout << "There is already someone! Try again!" << endl;
        request_move();
        return;
    }

    grid[index] = player_person;

    draw_grid();
    cout << endl;

    if(!eval_grid()) {
        make_move();
    }
}

void make_move() {
    // TODO: Implement some sort of little AI later

    srand(time(0));
    int index = rand() % 9;
    while (grid[index] != ' ') {
        index = rand() % 9;
    }

    grid[index] = player_computer;

    draw_grid();
    cout << endl;

    if(!eval_grid()) {
        request_move();
    }
}
