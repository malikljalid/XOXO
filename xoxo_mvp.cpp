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
    //bool isFull;
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

short int readPlayerChoice(int PlayerNumber)
{
    short int Choice;
    std::string name[2] = {"Player", "Computer"};

    std::cout << name[PlayerNumber] << " turn : ";
    std::cin >> Choice;

    return (Choice);
}

void setPlayerChoiceToPlat(stPlat &Plat, stPlayer Player)
{
    Plat.Index[Player.Choice] = Player.Symbol;
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

void showPlat(stPlat Plat)
{
    std::cout << std::endl;

    std::cout << "-------------\n";
    std::cout << "| " << 0 <<" | " << 1 <<" | " << 2 <<" |\n";
    std::cout << "-------------\n";
    std::cout << "| " << 3 <<" | " << 4 <<" | " << 5 <<" |\n";
    std::cout << "-------------\n";
    std::cout << "| " << 6 <<" | " << 7 <<" | " << 8 <<" |\n";
    std::cout << "-------------\n";

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

void gameLoop(void)
{
    stXoxoGame Game;

    Game.Plat = initPlat();
    setPlayersSymbol(Game.Player1, Game.Computer);
    showPlat(Game.Plat);

    while (1)
    {
        Game.Player1.Choice  = readPlayerChoice(0);
        setPlayerChoiceToPlat(Game.Plat, Game.Player1);
        showPlat(Game.Plat);
        if (checkPlat(Game.Plat) == PLAYER)
        {
            std::cout << "\nPLAYER1 Won !\n";
            break;
        }


        Game.Computer.Choice = readPlayerChoice(1);
        setPlayerChoiceToPlat(Game.Plat, Game.Computer);
        showPlat(Game.Plat);
        if(checkPlat(Game.Plat) == COMPUTER)
        {
            std::cout << "\nCOMPUTER Won!\n";
            break;
        }

        if (isFull(Game.Plat))
            break;
    }
}

int main(void)
{
    gameLoop();

    return (0);
}
