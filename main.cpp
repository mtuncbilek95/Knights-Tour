#include "knight.h"

int main(int argc, char* argv[])
{
    knight* the_knight = new knight();
    the_knight->move_random(0,0);
    the_knight->print_movement();

    return 0;
}
