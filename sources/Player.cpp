#include "Player.hpp"
#include <iostream>


using namespace std;

namespace coup {

    Player::Player(Game &game, std::string name): _last_operation("none"), _coins(0){
        _game = &game;
        _name = name;
        game.add_player(*this);
    }

    void Player::coins_check(){
        if (_coins >= 10){
            throw runtime_error(_name + " you must coup at this point");
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
            throw runtime_error(_name + " can't income, it's not his turn");
        }
        ++_coins;
        _game->next_turn();
        _last_operation = "income";
    }

    void Player::foreign_aid() {
        coins_check();
        if (_game->turn() != _name){
            throw runtime_error(_name + " can't foreign_aid, it's not his turn");
        }
        _game->next_turn();
        _coins += 2;
        _last_operation = "foreign_aid";
    }

    int Player::coins() {
        return _coins;
    }

    void Player::set_coins(int coins){
        _coins = coins;
    }

    void Player::coup(Player &to_kick) {
        if (_game->turn() != _name){
            throw runtime_error(_name + " can't coup, it's not his turn");
        }
        if (_coins < 7){
            throw runtime_error(_name + " doesnt have enough coins to coup");
        }
        _coins -= 7;
        _game->remove_player(to_kick);
        _game->next_turn();
        _last_operation = "coup";
    }

    std::string Player::role(){return "";}
}
