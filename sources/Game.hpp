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
        std::string _state;
        const static int MAX_PLAYER = 6;

    public:
        Game();

        std::string turn();

        std::vector<std::string> players();

        std::string winner();

        void add_player(Player &player, int index = -1);

        int remove_player(Player &player); // when someone coup another player this is called, return index of the removal

        void next_turn();

        std::string get_state();

        ~Game();
    };

} // coup

#endif //COUP_A_GAME_HPP
