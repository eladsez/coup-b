#ifndef COUP_A_AMBASSADOR_HPP
#define COUP_A_AMBASSADOR_HPP

#include "Player.hpp"

namespace coup {

    class Ambassador : public Player {

    public:
        Ambassador(Game &game, std::string name): Player(game, name){}

        void transfer(Player &from, Player &to);

        void block(Player &player); // block captain from stealing

        std::string role();

        ~Ambassador();
    };

} // coup

#endif //COUP_A_AMBASSADOR_HPP
