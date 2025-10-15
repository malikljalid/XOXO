#include <iostream>
#include <cstdlib>
#include <ctime>

enum enPlayerSymbol     { X, O };
enum enGameWinner       { PLAYER, COMPUTER, DRAW };

struct stPlayer
{
    enPlayerSymbol  Symbol;
    short int       Choice;
};

struct stPlat
{
    char Index[9];
};

struct stXoxoGame
{
    stPlat          Plat;
    stPlayer        Player1;
    stPlayer        Computer;
    enGameWinner    Winner;
};

stPlat initPlat(void)
{
    stPlat Plat;

    for (int i = 0; i < 9; i++)
    {
        Plat.Index[i] = ' ';
    }

    return (Plat);
}

void setPlayerChoice(stPlayer &Player, short int Choice)
{
    Player.Choice = Choice;
}

void setPlayerChoice(stPlat &Plat, stPlayer Player)
{
    char xo[2] = {'X', 'O'};

    Plat.Index[Player.Choice] = xo[Player.Symbol];
}

void showPlat(stPlat Plat)
{
    std::cout << std::endl;

    std::cout << "-------------\n";
    std::cout << "| " << Plat.Index[0] <<" | " << Plat.Index[1] <<" | " << Plat.Index[2] <<" |\n";
    std::cout << "-------------\n";
    std::cout << "| " << Plat.Index[3] <<" | " << Plat.Index[4] <<" | " << Plat.Index[5] <<" |\n";
    std::cout << "-------------\n";
    std::cout << "| " << Plat.Index[6] <<" | " << Plat.Index[7] <<" | " << Plat.Index[8] <<" |\n";
    std::cout << "-------------\n";

    std::cout << std::endl;
}

int main(void)
{
    stPlat      Plat = initPlat();
    stPlayer    Me;

    Me.Symbol = X;
    Me.Choice = 4;

    showPlat(Plat);

    setPlayerChoice(Plat, Me);
    showPlat(Plat);

    Me.Choice = 1;
    setPlayerChoice(Plat, Me);
    showPlat(Plat);


    Me.Choice = 8;
    setPlayerChoice(Plat, Me);
    showPlat(Plat);

    return (0);
}
