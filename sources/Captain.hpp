#ifndef COUP_A_CAPTAIN_HPP
#define COUP_A_CAPTAIN_HPP

#include "Player.hpp"

namespace coup {

    class Captain: public Player {

    private:
        Player *_stolen_from;

    public:
        Captain(Game &game, std::string name): Player(game, name), _stolen_from(nullptr){}

        void block(Player &to_block);

        void steal(Player &to_steal);

        std::string role();
    };

} // coup

#endif //COUP_A_CAPTAIN_HPP
