#include <iostream>
#include <cstdlib>
#include <ctime>

enum enGameWinner { PLAYER, COMPUTER, DRAW };

struct stPlayer
{
    short int Choice;
};

struct stPlat
{
    short int Index[9];
};

struct stXoxoGame
{
    stPlat          Plat;
    stPlayer        Player1;
    stPlayer        Computer;
    enGameWinner    Winner;
};

int main(void)
{
    return (0);
}
