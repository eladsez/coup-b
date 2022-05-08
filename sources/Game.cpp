#include "Game.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

namespace coup {

    Game::Game() : _turn(0), _state("init") {}

    std::string Game::turn() {
        return _players[(size_t) _turn].get_name();
    }

    std::vector <std::string> Game::players() {
        std::vector <std::string> names;
        for (Player plr: _players) {
            names.push_back(plr.get_name());
        }
        return names;
    }

    void Game::add_player(Player &player, int index) {
        if (_players.size() == MAX_PLAYER) {
            throw runtime_error("can't add to the game more then 6 players");
        }
        if (index == -1) {
            _players.push_back(player);
        } else {
            _players.insert(_players.begin() + index, player);
        }
    }

    int Game::remove_player(Player &player) {// https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom
        for (int i = 0; i < _players.size(); ++i) {
            if (player.get_name() == _players[(size_t) i].get_name()) {
                _players.erase(_players.begin() + i);
                return i;
            }
        }
        throw runtime_error("didnt find player " + player.get_name() + " to coup");
        return -1;
    }

    void Game::next_turn() {
        if (_turn == 0) {
            _state = "running";
        }
        ++_turn;
        if (_turn >= _players.size()) {
            _turn = 0;
        }
    }

    std::string Game::winner() {
        if (_players.size() != 1 || _state == "init") {
            throw runtime_error("the game is not done yet!");
        }
        return _players[0].get_name();
    }

    std::string Game::get_state() {
        return _state;
    }

    Game::~Game() {}
} // coup