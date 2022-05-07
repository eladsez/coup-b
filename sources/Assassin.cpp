#include "Assassin.hpp"
#include "Player.hpp"
#include <iostream>

namespace coup {
    void Assassin::coup(Player &to_kick) {
        if (_game->turn() != _name) {
            throw std::runtime_error(_name + " can't coup, it's not his turn");
        }
        if (_coins < 3) {
            throw std::runtime_error(_name + " doesnt have enough coins to coup");
        }
        if (_coins >= 7) {
            Player::coup(to_kick);
            return;
        }

        _last_kick_index = _game->remove_player(to_kick);
        _last_kicked = &to_kick;
        _game->next_turn();
        _coins -= 3;
        _last_operation = "Assassin-coup";
    }

    Player &Assassin::get_last_kicked() {
        return *_last_kicked;
    }

    std::string Assassin::role() { return "Assassin"; }
} // coup