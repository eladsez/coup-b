#ifndef COUP_A_GAME_HPP
#define COUP_A_GAME_HPP

#include <vector>
#include <string>
#include "Player.hpp"

namespace coup {

    class Player;

    class Game {

    private:
        int _turn;
        std::vector<Player> _players;

    public:
        Game();

        std::string turn();

        std::vector<std::string> players();

        std::string winner();

        void add_player(Player &player, int index = -1);

        int remove_player(Player &player); // when someone coup another player this is called, return index of the removal

        void next_turn();

        static const int MAX_PLAYERS = 6;
        static const int MIN_PLAYERS = 2;
    };

} // coup

#endif //COUP_A_GAME_HPP
