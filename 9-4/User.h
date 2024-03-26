#pragma once
#ifndef USER_H
#define USER_H

#include "wallet.h"

//  ласс дл€ пользовател€
class User {
private:
    std::string name; // им€ пользовател€
    Wallet wallet; // кошелек пользовател€

public:
    //  онструктор, принимающий им€ пользовател€, идентификатор кошелька и начальный баланс
    User(const std::string& name, int wallet_id, int initial_balance = 0);

    // ћетод дл€ получени€ имени пользовател€
    std::string get_name() const;

    // ћетод дл€ получени€ идентификатора кошелька пользовател€
    int get_wallet_id() const;

    // ћетод дл€ получени€ баланса кошелька пользовател€
    int get_wallet_balance() const;

    // ћетод дл€ добавлени€ денег на кошелек пользовател€
    void add_money_to_wallet(int amount);

    // ћетод дл€ расходовани€ денег с кошелька пользовател€
    void spend_money_from_wallet(int amount);
};
#include "user.h"

//  онструктор, принимающий им€ пользовател€, идентификатор кошелька и начальный баланс
User::User(const std::string& name, int wallet_id, int initial_balance){
    this->name = name;
    this->wallet = Wallet(wallet_id, initial_balance-100);
}

// ћетод дл€ получени€ имени пользовател€
std::string User::get_name() const {
    return name;
}

// ћетод дл€ получени€ идентификатора кошелька пользовател€
int User::get_wallet_id() const {
    return wallet.get_wallet_id();
}

// ћетод дл€ получени€ баланса кошелька пользовател€
int User::get_wallet_balance() const {
    return wallet.get_balance();
}

// ћетод дл€ добавлени€ денег на кошелек пользовател€
void User::add_money_to_wallet(int amount) {
    wallet.add_cash(amount);
}

// ћетод дл€ расходовани€ денег с кошелька пользовател€
void User::spend_money_from_wallet(int amount) {
    wallet.spend_cash(amount);
}
#endif // USER_H


