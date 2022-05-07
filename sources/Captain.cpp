#include "Captain.hpp"
#include <iostream>

namespace coup {

    void Captain::block(Player &to_block){
        if (to_block.get_last_operation() != "steal"){
            throw std::runtime_error(_name + " can't block " + to_block.get_name() + " didnt steal last turn");
        }
        Player *stolen_from = ((Captain*) &to_block)->_stolen_from;
        stolen_from->set_coins(stolen_from->coins() + 2);
    }

    void Captain::steal(Player &to_steal){
        if (_game->turn() != _name){
            throw std::runtime_error(_name + " can't steal, it's not his turn");
        }
        _stolen_from = &to_steal;
        if (to_steal.coins() < 2){
            _coins += to_steal.coins();
            to_steal.set_coins(0);
        } else {
            to_steal.set_coins(to_steal.coins() - 2);
            _coins += 2;
        }
        _last_operation = "steal";
        _game->next_turn();
    }

    std::string Captain::role(){return "Captain";}

} // coup