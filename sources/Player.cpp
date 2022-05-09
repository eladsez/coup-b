#include "Player.hpp"
#include <iostream>

namespace coup {

    Player::Player(Game &game, std::string name): _last_operation("none"), _coins(0){
        if (game.get_state() != "init"){
            throw std::runtime_error("can't add new players in the middle of the game");
        }
        _game = &game;
        _name = std::move(name);
        game.add_player(*this);
    }

    void Player::coins_check(){
        if (_coins >= MAX_COINS_HOLD){
            throw std::runtime_error(_name + " you must coup at this point");
         }
        if (_game->players().size() < 2){
            throw std::runtime_error(_name + " try to start the game alone");
        }
    }

    std::string Player::get_name(){
        return _name;
    }

    std::string Player::get_last_operation(){
        return _last_operation;
    }

    void Player::income() {
        coins_check();
        if (_game->turn() != _name){
            throw std::runtime_error(_name + " can't income, it's not his turn");
        }
        ++_coins;
        _game->next_turn();
        _last_operation = "income";
    }

    void Player::foreign_aid() {
        coins_check();
        if (_game->turn() != _name){
            throw std::runtime_error(_name + " can't foreign_aid, it's not his turn");
        }
        _game->next_turn();
        _coins += 2;
        _last_operation = "foreign_aid";
    }

    int Player::coins() const{
        return _coins;
    }

    void Player::set_coins(int coins){
        _coins = coins;
    }

    void Player::coup(Player &to_kick) {
        if (_game->turn() != _name){
            throw std::runtime_error(_name + " can't coup, it's not his turn");
        }
        if (_coins < PLY_KICK_MIN){
            throw std::runtime_error(_name + " doesnt have enough coins to coup");
        }
        int his_index = -1;
        int my_index = -1;
        std::vector<std::string> players = _game->players();
        for (size_t i = 0; i < players.size(); ++i){
            if (to_kick.get_name() == players[i]){
                his_index = (int)i;
            }
            if (_name == players[i]){
                my_index = (int)i;
            }
        }
        _game->remove_player(to_kick);
        _coins -= PLY_KICK_MIN;
        if (his_index > my_index || my_index == _game->players().size()) {
            _game->next_turn();
        }
        _last_operation = "coup";
    }

    std::string Player::role(){return "";}

    Player::~Player() {}
}
