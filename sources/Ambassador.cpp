#include "Ambassador.hpp"
#include "Captain.hpp"
#include <iostream>

namespace coup {

    void Ambassador::transfer(Player &from, Player &toP) {
        if (_game->turn() != _name){
            throw std::runtime_error(_name + " can't transfer, it's not his turn");
        }
        if (from.coins() < 1){
            throw std::runtime_error(from.get_name() + " doesnt have enough money");
        }
        from.set_coins(from.coins() - 1);
        toP.set_coins(toP.coins() + 1);
        _last_operation = "transfer";
        _game->next_turn();
    }

    void Ambassador::block(Player &player){
        Captain *to_block = dynamic_cast<Captain *>(&player);
        if (to_block->get_last_operation() != "steal"){
            throw std::runtime_error(_name + " can't block, " + to_block->get_name() + " didnt steal last turn");
        }
        to_block->get_stolen_from().set_coins(to_block->get_stolen_from().coins() + 2);
        to_block->set_coins(to_block->coins() - 2);
    }

    std::string Ambassador::role() {return "Ambassador";}

    Ambassador::~Ambassador() {}
} // coup