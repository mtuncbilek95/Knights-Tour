#include "knight.h"

knight::knight()
{
    count = 0;
    visited_cells.resize(LINESIZE);
    for (int i = 0; i < visited_cells.size(); i++)
    {
        visited_cells.at(i).resize(LINESIZE);
        for (int j = 0; j < visited_cells[i].size(); j++)
        {
            visited_cells.at(i).at(j) = -1;
        }
    }

    visited_cells.at(0).at(0) = 0;
    reset_moves();
}
void knight::move_random(int x, int y)
{
    while (movements.size() > 0)
    {
        srand((int)time(NULL));
        int random_number = rand() % movements.size();

        int x_next = x + movements[random_number].first;
        int y_next = y + movements[random_number].second;
        
        if (safe_to_move(y_next, x_next))
        {
            if (visited_cells.at(x_next).at(y_next) == -1)
            {
                count += 1;
                visited_cells.at(x_next).at(y_next) = count;
                reset_moves();
                move_random(x_next, y_next);
            }
            else
            {
                movements.erase(movements.begin() + random_number);
                move_random(x, y);
            }
        }
        else
        {
            movements.erase(movements.begin() + random_number);
            move_random(x, y);
        }
    }
}

void knight::move_backtrack(int x, int y)
{
}

void knight::print_movement()
{
    for (int i = 0; i < visited_cells.size(); i++)
    {
        for (int j = 0; j < visited_cells[i].size(); j++)
        {
            if(visited_cells.at(j).at(i) == -1)
                print_color(0, std::to_string(visited_cells.at(j).at(i)));
            else
                print_color(5,  std::to_string(visited_cells.at(j).at(i)));
        }
        std::cout << std::endl;
    }
    
    print_color(0,"---------------------------------------------------");
    std::cout << std::endl;

    if(count == 63)
        print_color(0,"You have visited every cell in the board. Congratulations!");
    else
        print_color(0,"You still have " + std::to_string(63-count) + " cells to visit, but you got stuck!"); 
}
bool knight::safe_to_move(int x, int y)
{
    if ((x >= 0 && y >= 0) && (x < LINESIZE && y < LINESIZE))
        return true;
    else
        return false;
}
void knight::reset_moves()
{
    movements.resize(LINESIZE);
    movements.clear();
    movements = {{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}};
}
void knight::print_color(uint8_t color, std::string output_string)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);
    Sleep(5);
    std::cout << std::setw(5) << output_string;
}