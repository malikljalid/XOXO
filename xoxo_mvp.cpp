#include <iostream>
#include <cstdlib>
#include <ctime>

enum enPlayerSymbol     { X='X', O='O' };
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

short int readPlayerChoice(void)
{
    short int Choice;

    std::cout << "Where you want to Draw : ";
    std::cin >> Choice;

    return (Choice);
}

void setPlayerChoice(stPlat &Plat, stPlayer Player)
{
    char xo[2] = {'X', 'O'};

    Plat.Index[Player.Choice] = xo[Player.Symbol];
}

enGameWinner someOneWins(stPlat Plat)
{
    // hard code the posible condition
    if ((Plat.Index[0] == Plat.Index[1] && Plat.Index[1] == Plat.Index[2]) ||
        (Plat.Index[3] == Plat.Index[4] && Plat.Index[4] == Plat.Index[5]) ||
        (Plat.Index[6] == Plat.Index[7] && Plat.Index[7] == Plat.Index[8]) ||

        (Plat.Index[0] == Plat.Index[3] && Plat.Index[3] == Plat.Index[6]) ||
        (Plat.Index[1] == Plat.Index[4] && Plat.Index[4] == Plat.Index[7]) ||
        (Plat.Index[2] == Plat.Index[5] && Plat.Index[5] == Plat.Index[8]) ||

        (Plat.Index[0] == Plat.Index[4] && Plat.Index[4] == Plat.Index[8]) ||
        (Plat.Index[2] == Plat.Index[4] && Plat.Index[4] == Plat.Index[6]))
    {
        if (Plat.Index[0] == X)
            return (enGameWinner::PLAYER);
        else
            return (enGameWinner::COMPUTER);
    }
    return (enGameWinner::DRAW);
}

bool isFull(stPlat Plat)
{
    for (int i = 0; i < 9; i++)
    {
        if (Plat.Index[i] != 'X' && Plat.Index[i] != 'O')
            return (false); 
    }
    return (true);
}

void gameLoop(void)
{
    stXoxoGame Game;

    Game.Plat = initPlat();

    while (someOneWins(Game.Plat) != PLAYER || someOneWins(Game.Plat) != COMPUTER)
    {
        Game.Player1.Choice = readPlayerChoice();
        Game.Computer.Choice = readPlayerChoice();

        setPlayerChoice(Game.Plat, Game.Player1);
        setPlayerChoice(Game.Plat, Game.Computer);

        if (isFull(Game.Plat))
            break;
    }
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
    gameLoop();

    return (0);
}
