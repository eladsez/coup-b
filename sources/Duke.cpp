#include "Duke.hpp"
#include <iostream>

namespace coup {

    void Duke::tax() {
        if (_game->turn() != _name){
            throw std::runtime_error(_name + " can't tax, it's not his turn");
        }
        _coins += 3;
        _last_operation = "tax";
        _game->next_turn();
    }

    void Duke::block(Player &to_block) {
        if (to_block.get_last_operation() != "foreign_aid"){
            throw std::runtime_error(_name + " cant block " + to_block.get_name() + ", his last turn wasn't foreign_aid");
        }
        to_block.set_coins(to_block.coins() - 2);
    } // can block whoever foreign_aid

    std::string Duke::role() { return "Duke"; }

    Duke::~Duke() {}
} // coup