#ifndef COUP_A_PLAYER_HPP
#define COUP_A_PLAYER_HPP

#include "Game.hpp"
#include <string>

namespace coup {
    class Game;

    class Player {

    protected:
        Game *_game; // the game the player belong to
        std::string _name;
        std::string _last_operation; // the last operation the player chose in the game
        int _coins; // number of coins the player have

        void coins_check();

    public:
        Player(Game &game, std::string name);

        std::string get_name();

        std::string get_last_operation();

        void income();

        void foreign_aid();

        int coins();

        void set_coins(int coins);

        virtual void coup(Player &to_kick); // virtual because the assassin need to override it

        virtual std::string role(); // virtual because each inheritance player return something else
    };
}

#endif //COUP_A_PLAYER_HPP
