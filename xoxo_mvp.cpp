#include <iostream>
#include <cstdlib>
#include <ctime>

enum enPlatCapacity     { FULL=9 };
enum enPlayerSymbol     { X='X', O='O' };
enum enGameWinner       { PLAYER, COMPUTER, DRAW, UNKNOWN };

struct stPlayer
{
    enPlayerSymbol  Symbol;
    short int       Choice;
};

struct stPlat
{
    char        Index[FULL];
    short int   Capacity;
};

struct stGame
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

    Plat.Capacity = 0;

    return (Plat);
}

short int readPlayerChoice(enPlayerSymbol Symbol)
{
    short int Choice;

    std::cout << " player " << (char)Symbol << " turn : ";
    std::cin >> Choice;

    return (Choice);
}

void setPlayerChoiceToPlat(stPlat &Plat, stPlayer Player)
{
    Plat.Index[Player.Choice] = Player.Symbol;
    Plat.Capacity++;
}

enGameWinner checkPlat(stPlat Plat)
{
    // hard code the posible condition
    if ((Plat.Index[0] == X && Plat.Index[1] == X && Plat.Index[2] == X) ||
        (Plat.Index[3] == X && Plat.Index[4] == X && Plat.Index[5] == X) ||
        (Plat.Index[6] == X && Plat.Index[7] == X && Plat.Index[8] == X) ||

        (Plat.Index[0] == X && Plat.Index[3] == X && Plat.Index[6] == X) ||
        (Plat.Index[1] == X && Plat.Index[4] == X && Plat.Index[7] == X) ||
        (Plat.Index[2] == X && Plat.Index[5] == X && Plat.Index[8] == X) ||

        (Plat.Index[0] == X && Plat.Index[4] == X && Plat.Index[8] == X) ||
        (Plat.Index[2] == X && Plat.Index[4] == X && Plat.Index[6] == X))
        return (enGameWinner::PLAYER);

    if ((Plat.Index[0] == O && Plat.Index[1] == O && Plat.Index[2] == O) ||
        (Plat.Index[3] == O && Plat.Index[4] == O && Plat.Index[5] == O) ||
        (Plat.Index[6] == O && Plat.Index[7] == O && Plat.Index[8] == O) ||

        (Plat.Index[0] == O && Plat.Index[3] == O && Plat.Index[6] == O) ||
        (Plat.Index[1] == O && Plat.Index[4] == O && Plat.Index[7] == O) ||
        (Plat.Index[2] == O && Plat.Index[5] == O && Plat.Index[8] == O) ||

        (Plat.Index[0] == O && Plat.Index[4] == O && Plat.Index[8] == O) ||
        (Plat.Index[2] == O && Plat.Index[4] == O && Plat.Index[6] == O))
        return (enGameWinner::COMPUTER);

    return (enGameWinner::UNKNOWN);
}

bool isFull(stPlat Plat)
{
    return (Plat.Capacity >= enPlatCapacity::FULL);
}

void showPlat(stPlat Plat)
{
    std::cout << std::endl;

    std::cout << "-------------\n";
    std::cout << "| " << 0 <<" | " << 1 <<" | " << 2 <<" |\n";
    std::cout << "-------------\n";
    std::cout << "| " << 3 <<" | " << 4 <<" | " << 5 <<" |\n";
    std::cout << "-------------\n";
    std::cout << "| " << 6 <<" | " << 7 <<" | " << 8 <<" |\n";
    std::cout << "-------------\n\n";

    std::cout << "-------------\n";
    std::cout << "| " << Plat.Index[0] <<" | " << Plat.Index[1] <<" | " << Plat.Index[2] <<" |\n";
    std::cout << "-------------\n";
    std::cout << "| " << Plat.Index[3] <<" | " << Plat.Index[4] <<" | " << Plat.Index[5] <<" |\n";
    std::cout << "-------------\n";
    std::cout << "| " << Plat.Index[6] <<" | " << Plat.Index[7] <<" | " << Plat.Index[8] <<" |\n";
    std::cout << "-------------\n";

    std::cout << std::endl;
}

void setPlayersSymbol(stPlayer &Player1, stPlayer &Computer)
{
    char symbol = '\0';

    while (symbol != X && symbol != O)
    {
        std::cout << "What Do you want (X/O) ? : ";
        std::cin >> symbol;
    }

    if (symbol == X)
    {
        Player1.Symbol  = X;
        Computer.Symbol = O;
    }

    if (symbol == O)
    {
        Player1.Symbol  = O;
        Computer.Symbol = X;
    }
}

stGame initGame(void)
{
    stGame Game;

    Game.Plat = initPlat();
    setPlayersSymbol(Game.Player1, Game.Computer);
    showPlat(Game.Plat);

    return (Game);
}

enGameWinner playerTurn(stPlayer &Player, stPlat &Plat)
{
    std::string  players[2] = {"\nPLAYER1", "\nCOMPUTER"};
    enGameWinner Winner;

    Player.Choice  = readPlayerChoice(Player.Symbol);
    setPlayerChoiceToPlat(Plat, Player); //increment plat size for isFull check later insteaf of iterating in for()
    showPlat(Plat);
    Winner = checkPlat(Plat);

    if (Winner != UNKNOWN)
        return (Winner);

    if (isFull(Plat))
        return (enGameWinner::DRAW);

    return (enGameWinner::UNKNOWN);
}

void showWinner(enGameWinner Winner)
{
    switch (Winner)
    {
        case (PLAYER) :
        {
            std::cout << "Player Won\n";
            break;
        }
        case (COMPUTER) :
        {
            std::cout << "Computer Won\n";
            break;
        }
        case (DRAW) :
        {
            std::cout << "DRAW, No One Won\n";
            break;
        }
        default :
            std::cout << "ERROR\n";
    }
}

void gameLoop(void)
{
    stGame Game = initGame();

    while (1)
    {
        Game.Winner = playerTurn(Game.Player1, Game.Plat);
        if (Game.Winner != enGameWinner::UNKNOWN)
            break;

        Game.Winner = playerTurn(Game.Computer, Game.Plat);
        if (Game.Winner != enGameWinner::UNKNOWN)
            break;
    }

    showWinner(Game.Winner);
}

int main(void)
{
    gameLoop();

    return (0);
}

// add "this spot is taken in plat" feuature
// make playerX and playerO instead of player vs computer 
// set playerX enum to player sturct member type or something