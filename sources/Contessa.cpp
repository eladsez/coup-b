#include "Contessa.hpp"
#include "Assassin.hpp"
#include "Player.hpp"
#include <iostream>

namespace coup {

    void Contessa::block(Player &assassin){
        Assassin* to_block = (Assassin*) &assassin;

        if (assassin.get_last_operation() != "Assassin-coup"){
            throw std::runtime_error(_name + "cant block " + assassin.get_name() + "because his last turn wasn't assassination");
        }

        _game->add_player(to_block->get_last_kicked(), to_block->get_last_kick_index());
    }

    std::string Contessa::role(){return "Contessa";}

} // coup