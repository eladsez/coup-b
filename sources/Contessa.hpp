#ifndef COUP_A_CONTESSA_HPP
#define COUP_A_CONTESSA_HPP

#include "Player.hpp"

namespace coup {

    class Contessa: public Player{

    public:
        Contessa(Game &game, std::string name): Player(game, name){}

        void block(Player &assassin);

        std::string role();

        ~Contessa();
    };

} // coup

#endif //COUP_A_CONTESSA_HPP
