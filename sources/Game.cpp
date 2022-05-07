#include "Game.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

namespace coup {

    Game::Game():_turn(0), _players(){}

    std::string Game::turn(){
        return _players[(size_t)_turn].get_name();
    }

    std::vector<std::string> Game::players(){
        std::vector<std::string> names;
        for (Player p : _players){
            names.push_back(p.get_name());
        }
        return names;
    }

    void Game::add_player(Player &p, int index){
        if (index == -1) {
            _players.push_back(p);
        } else{
            _players.insert(_players.begin() + index, p);
        }
    }

    int Game::remove_player(Player &player){// https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom
        for (int i = 0; i < _players.size(); ++i){
            if (player.get_name() == _players[(size_t)i].get_name()){
                _players.erase(_players.begin() + i);
                return i;
            }
        }
        return -1;
    }

    void Game::next_turn(){
        ++_turn;
        if (_turn >= _players.size()){
            _turn = 0;
        }
    }

    std::string Game::winner(){return "";}
} // coup