#ifndef COUP_A_DUKE_HPP
#define COUP_A_DUKE_HPP

#include "Player.hpp"

namespace coup {

    class Duke : public Player {

    public:
        Duke(Game &game, std::string name): Player(game, name){}

        void tax();

        void block(Player &to_block);

        std::string role();
    };

} // coup

#endif //COUP_A_DUKE_HPP
