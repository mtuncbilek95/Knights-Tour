#pragma once

#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <time.h>
#include <Windows.h>

typedef std::vector<std::vector<int>> matrix_vector;
typedef std::vector<std::pair<int,int>> coord_vector;
#define LINESIZE 8

class knight
{
public:
    knight();
    void move_random(int x, int y);
    void move_backtrack(int x, int y);
    void print_movement();

protected:
    void reset_moves();
    void print_color(uint8_t color, std::string output_string);
    bool safe_to_move(int x, int y);

private:
    matrix_vector visited_cells;
    coord_vector movements;
    int count;
};


