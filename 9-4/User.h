#pragma once
#ifndef USER_H
#define USER_H

#include "wallet.h"

// ����� ��� ������������
class User {
private:
    std::string name; // ��� ������������
    Wallet wallet; // ������� ������������

public:
    // �����������, ����������� ��� ������������, ������������� �������� � ��������� ������
    User(const std::string& name, int wallet_id, int initial_balance = 0);

    // ����� ��� ��������� ����� ������������
    std::string get_name() const;

    // ����� ��� ��������� �������������� �������� ������������
    int get_wallet_id() const;

    // ����� ��� ��������� ������� �������� ������������
    int get_wallet_balance() const;

    // ����� ��� ���������� ����� �� ������� ������������
    void add_money_to_wallet(int amount);

    // ����� ��� ������������ ����� � �������� ������������
    void spend_money_from_wallet(int amount);
};
#include "user.h"

// �����������, ����������� ��� ������������, ������������� �������� � ��������� ������
User::User(const std::string& name, int wallet_id, int initial_balance){
    this->name = name;
    this->wallet = Wallet(wallet_id, initial_balance-100);
}

// ����� ��� ��������� ����� ������������
std::string User::get_name() const {
    return name;
}

// ����� ��� ��������� �������������� �������� ������������
int User::get_wallet_id() const {
    return wallet.get_wallet_id();
}

// ����� ��� ��������� ������� �������� ������������
int User::get_wallet_balance() const {
    return wallet.get_balance();
}

// ����� ��� ���������� ����� �� ������� ������������
void User::add_money_to_wallet(int amount) {
    wallet.add_cash(amount);
}

// ����� ��� ������������ ����� � �������� ������������
void User::spend_money_from_wallet(int amount) {
    wallet.spend_cash(amount);
}
#endif // USER_H


