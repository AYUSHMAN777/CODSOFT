#include <iostream>
#include <string>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int column;
char token = 'x';
string n1;
string n2;
bool tie;
void functionOne()
{

    // cout << "  |   | \n";
    // cout << "" << space[0][0] << " | " << space[0][1] << " | " << space[0][2] << "\n";
    // cout << "__|___|__\n";
    // cout << "  |   | \n";
    // cout << "" << space[1][0] << " | " << space[1][1] << " | " << space[1][2] << "\n";
    // cout << "__|___|__\n";
    // cout << "  |   | \n";
    // cout << "" << space[2][0] << " | " << space[2][1] << " | " << space[2][2] << "\n";
    // cout << "  |   | \n";
    cout << "   |   | \n";
    cout << " " << space[0][0] << " | " << space[0][1] << " | " << space[0][2] << "\n";
    cout << "___|___|___\n";
    cout << "   |   | \n";
    cout << " " << space[1][0] << " | " << space[1][1] << " | " << space[1][2] << "\n";
    cout << "___|___|___\n";
    cout << "   |   | \n";
    cout << " " << space[2][0] << " | " << space[2][1] << " | " << space[2][2] << "\n";
    cout << "   |   | \n";
}

void functionTwo()
{
    int digit;
    if (token == 'x')
    {
        cout << n1 << " Please Enter the digit : ";
        cin >> digit;
    }
    else if (token == '0')
    {
        cout << n2 << " Please Enter the digit : ";
        cin >> digit;
    }

    if (digit == 1)
    {
        row = 0;
        column = 0;
    }

    else if (digit == 2)
    {
        row = 0;
        column = 1;
    }
    else if (digit == 3)
    {
        row = 0;
        column = 2;
    }

    else if (digit == 4)
    {
        row = 1;
        column = 0;
    }
    else if (digit == 5)
    {
        row = 1;
        column = 1;
    }
    else if (digit == 6)
    {
        row = 1;
        column = 2;
    }
    else if (digit == 7)
    {
        row = 2;
        column = 0;
    }
    else if (digit == 8)
    {
        row = 2;
        column = 1;
    }
    else if (digit == 9)
    {
        row = 2;
        column = 2;
    }

    else
    {
        cout << "Invalid Input" << endl;
    }

    if (token == 'x' && space[row][column] != 'x' && space[row][column] != '0')
    {
        space[row][column] = 'x';
        token = '0';
    }

    else if (token == '0' && space[row][column] != 'x' && space[row][column] != '0')
    {
        space[row][column] = '0';
        token = 'x';
    }

    else
    {
        cout << "No Space Left" << endl;
        functionTwo(); // to show that at that position already a value 'x' or '0' is being alloted
    }
    functionOne();
}

bool functionthree()
{
    for (int i = 0; i < 3; i++)
    {
        if (space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i])
            return true;
    }
    if (space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0])
    {
        return true;
    }
    for (int i = 0; i < 3; i++) // for game still left or not
    {
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j] != 'x' && space[i][j] != '0')
            {
                return false;
            }
        }
    }
    tie = true;
    return true; // returning true indicate that game has been won by anyone or it is been tie between them
}

int main()
{
    cout << "Enter the name of first player : \n";
    getline(cin, n1);
    cout << "Enter the name of second player : \n";
    getline(cin, n2);
    cout << n1 << " is a player1 so he/she will play first\n";
    cout << n2 << " is a player2 so he/she will play secocnd\n";
    while (!functionthree())
    {
        functionOne();
        functionTwo();
        // functionOne();
    }

    if (token == 'x' && tie == false)
    {
        cout << n2 << " wins" << endl;
    }
    else if (token == '0' && tie == false)
    {
        cout << n1 << " wins" << endl;
    }

    else
    {
        cout << "Game Draw";
    }
    return 0;
}
