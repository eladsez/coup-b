#include "Contessa.hpp"
#include "Assassin.hpp"
#include "Player.hpp"
#include <iostream>

namespace coup {

    void Contessa::block(Player &assassin) {
        Assassin *to_block = dynamic_cast<Assassin *> (&assassin);

        if (assassin.get_last_operation() != "Assassin-coup") {
            throw std::runtime_error(
                    _name + "cant block " + assassin.get_name() + "because his last turn wasn't assassination");
        }

        _game->add_player(to_block->get_last_kicked(), to_block->get_last_kick_index());

        std::vector <std::string> players = _game->players();
        int his_index = -1;
        int my_index = -1;
        int now_index = -1;
        for (size_t i = 0; i < players.size(); ++i) {
            if (to_block->get_last_kicked().get_name() == players[i]) {
                his_index = (int) i;
            }
            if (_name == players[i]) {
                my_index = (int) i;
            }
            if (_game->turn() == players[i]) {
                now_index = (int) i;
            }
        }
        if (his_index < my_index && now_index > his_index) {
            _game->next_turn();
        }
    }

    std::string Contessa::role() { return "Contessa"; }

    Contessa::~Contessa() {}

} // coup