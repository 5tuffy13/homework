#include <iostream>
#include <fstream>
using namespace std;

bool compiler(int& curr_cell, int& value, int& curr_state, int state_arr[201][7]);
void arr_cout(char arr[1000]);

int main()
{
    ifstream in("script.txt");
    if (!in.is_open())
    {
        cout << "Error: file not exist" << endl;
        return -1;
    }
    if (in.fail())
    {
        cout << "Error: cannot read" << endl;
        return -2;
    }

    const int columns = 7;
    int state_arr[201][columns] = { 0 };

    for (int i = 0; i < 201; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            in >> state_arr[i][j];
        }
    }
    in.close();

    char strip[1000];
    cout << "Type string: ";
    cin.getline(strip, 1000);
    cout << "*" << "\n" << "*" << "\n" << "*" << "\n" << "*" << "\n" << "*" << "\n";
    cout << "Old strip: " << strip << endl;
    int value = strip[0] - '0';
    int curr_state = 0;
    int curr_cell = 0;
    int i = 0;
    int counter = 0;
    while(curr_state!=99)
    {
        value = strip[i] - '0';
        if (compiler(curr_cell, value, curr_state, state_arr) == false)
            break;
        strip[i] = value+'0';
        i = curr_cell;
        counter++;
    }
    cout << "New strip: " << strip << endl << "Number of steps: " << counter << endl;
    return 0;
}

bool compiler(int& curr_cell, int& value, int& curr_state, int state_arr[201][7])
{
    if (value == 0 or value == 1)
    {
        if (value == 0)
        {
            value = state_arr[curr_state][1];
            curr_cell += state_arr[curr_state][2];
            curr_state = state_arr[curr_state][3];
        }
        else
        {
            value = state_arr[curr_state][4];
            curr_cell += state_arr[curr_state][5];
            curr_state = state_arr[curr_state][6];
        }

    }
    else
    {
        cout << "Incorrect value" << endl;
        return false;
    }
    return true;
}


void arr_cout(char arr[1000])
{
    int k = 0;
    while (*(arr + k) != '\0')
    {
        cout << *(arr + k);
        k++;
    }
    cout << '\n';
}
