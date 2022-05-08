#include "Assassin.hpp"
#include "Player.hpp"
#include <iostream>

namespace coup {
    void Assassin::coup(Player &to_kick) {
        if (_game->turn() != _name) {
            throw std::runtime_error(_name + " can't coup, it's not his turn");
        }
        if (_coins < ASS_KICK_MIN) {
            throw std::runtime_error(_name + " doesnt have enough coins to coup");
        }
        if (_coins >= PLY_KICK_MIN) {
            Player::coup(to_kick);
            return;
        }
        std::vector<std::string> players = _game->players();
        int his_index = -1;
        int my_index = -1;
        for (size_t i = 0; i < players.size(); ++i){
            if (to_kick.get_name() == players[i]){
                his_index = (int)i;
            }
            if (_name == players[i]){
                my_index = (int)i;
            }
        }
        _last_kick_index = _game->remove_player(to_kick);
        _last_kicked = &to_kick;
        if (his_index > my_index || my_index == _game->players().size()) {
            _game->next_turn();
        }
        _coins -= ASS_KICK_MIN;
        _last_operation = "Assassin-coup";
    }

    Player &Assassin::get_last_kicked() {
        return *_last_kicked;
    }

    int Assassin::get_last_kick_index() const{
        return _last_kick_index;
    }

    std::string Assassin::role() { return "Assassin"; }

    Assassin::~Assassin() {}
} // coup