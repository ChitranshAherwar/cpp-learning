#include <iostream>
#include <cstdlib>
#include <ctime>

class Player
{
public:
    int coins{0};
    int health{0};
    int xp{0};
};

void showHealth(Player& p) // p can be used for stuff like coin health xp. p is referencing object (player1, player2 in this case)
{
    std::cout << "Health: " << p.health << std::endl;
}

void showCoins(Player& p)
{
    std::cout << "Coins: " << p.coins << std::endl;
}

void showXP(Player& p)
{
    std::cout << "XP: " << p.xp << std::endl;
}

int main()
{

    std::srand(std::time(nullptr)); //generate random number
    int num1 = std::rand() % 100 + 1; // In range of 0 - 100.  for different random number is same lifetime of program
    int num2 = std::rand() % 100 + 1; // In range of 0 - 100. use multiple var. like num1, num2, num3, and so on.
    int num3 = std::rand() % 100 + 1;
    int num4 = std::rand() % 100 + 1;

    Player player1; //object created
    Player player2;

    player1.health = num1; // Object value
    player2.health = num2;

    player1.coins = 90;
    player2.coins = 89;

    player1.xp = num3;
    player2.xp = num4;

    showHealth(player1); //passing object to function
    showHealth(player2);

    showCoins(player1);
    showCoins(player2);

    showXP(player1);
    showXP(player2);

    return 0;
}