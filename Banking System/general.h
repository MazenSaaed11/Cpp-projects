#pragma once
#include"trust_account.h"
#include<iostream>
#include<map>
using namespace std;
void display();
void add_account();
int account_type();
void deposit();
void withdraw();
int returning_to_main_menu();
void display_account();
double amount_to_deposit();
bool check_account(int password, string phone_number);
double amount_to_withdraw();
int take_password();