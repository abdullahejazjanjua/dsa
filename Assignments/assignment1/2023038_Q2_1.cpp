#include <iostream>
using namespace std;

struct UniverseCoordinate
{
    int s_number = 0;
    int x_position = -1;
    int y_position = -1;
    bool is_snake = false;
};

void displayUniverse(UniverseCoordinate** array, int rows, int columns)
{
    cout << "\nCurrent Universe State:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (array[i][j].is_snake)
                cout << "[S" << array[i][j].s_number << "] ";
            else
                cout << "[ ] ";
        }
        cout << endl;
    }
}

UniverseCoordinate **Create2DArray(int rows, int columns)
{
    UniverseCoordinate **UniverseData = new UniverseCoordinate*[rows];
    for (int i = 0; i < rows; i++)
    {
        UniverseData[i] = new UniverseCoordinate[columns];
    }

    return UniverseData;

}

void delete2Darray(UniverseCoordinate **array, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete array[i];
    }
    delete array;
}

bool fullArray(UniverseCoordinate **array, int rows, int columns)
{
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (array[i][j].is_snake != 1)
            {
                return false;
            }
        }
    }
    return true;
}

void inputSnake(UniverseCoordinate **array, int row, int column, int &current_count)
{
    if (!array[row][column].is_snake)
    {
        current_count++;
        array[row][column].x_position = row;
        array[row][column].y_position = column;
        array[row][column].s_number = current_count;
        array[row][column].is_snake = 1;
    }
    else
    {
        cout << "\nChoose another coordinate because a snake is already at " << row << " and " << column << endl;
    }

}

int main()
{
    int rows = 2, columns = 2, count = 0;
    UniverseCoordinate **UniverseData = Create2DArray(rows, columns);
    while(true)
    {
        if (fullArray(UniverseData, rows, columns))
        {
            char choice;
            cout << "\nThe array is Full! Do you want to increase size of the array?(y/n) ";
            cin >> choice;
            if (choice == 'Y' || choice == 'y')
            {
                int new_rows, new_columns;
                cout << "\nEnter new rows and columns: ";
                cin >> new_rows >> new_columns;
                UniverseCoordinate **tmp = Create2DArray(new_rows, new_columns);
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < columns; j++)
                    {
                        tmp[i][j] = UniverseData[i][j];
                    }
                }
                delete2Darray(UniverseData, rows);
                UniverseData = tmp;
                rows = new_rows;
                columns = new_columns;
            }
        }
        else
        {
            int r,c;
            dummy:
                cout << "Enter snake coordinates: (Row, Column): ";
                cin >> r >> c;
                if (r < rows && c < columns)
                {
                    inputSnake(UniverseData, r, c, count);
                    displayUniverse(UniverseData, rows, columns);
                }
                else
                {
                    cout << "\nRange is: (" << 0 << "," << rows - 1 << ") , (" << 0 << "," << columns - 1 << ")" << endl;
                    goto dummy;
                }
        }
        char quit;
        tmp:
            cout << "Do you want to exit? (y/n) ";
            cin >> quit;
        if (quit == 'y' || quit == 'Y')
        {
            delete2Darray(UniverseData, rows);
            break;
        }
        else if (!isalpha(quit))
        {
            goto tmp;
        }
    }

}