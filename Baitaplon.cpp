#include<bits/stdc++.h>
using namespace std;

// Ty le quy doi
const double DOLLARS_PER_POINT = 10.0; // 10 do = 1 diem

// Lop Vi
class Wallet {
public:
    int walletId;
    int balance;
    vector<string> transactionLog;

    Wallet() : walletId(-1), balance(0) {}
    Wallet(int id, int initialBalance = 0) : walletId(id), balance(initialBalance) {}
};