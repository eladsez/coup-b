#ifndef COUP_A_ASSASSIN_HPP
#define COUP_A_ASSASSIN_HPP

#include "Player.hpp"

namespace coup {

    class Assassin : public Player {

    private:
        Player *_last_kicked;
        int _last_kick_index;
        const static int ASS_KICK_MIN = 3;

    public:
        Assassin(Game &game, std::string name) : Player(game, name), _last_kicked(nullptr), _last_kick_index(-1){}

        void coup(Player &to_kick); // override because he has other permissions to coup

        Player &get_last_kicked();

        int get_last_kick_index() const;

        std::string role();

        ~Assassin();

    };

} // coup

#endif //COUP_A_ASSASSIN_HPP
