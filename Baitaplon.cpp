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

// Lop Nguoi dung
class User {
public:
    string username;
    string passwordHash;
    string fullName;
    string email;
    int walletId;
    bool isManager;
    bool isAutoGenerated;
    
    User() : username(""), passwordHash(""), fullName(""), email(""), walletId(-1), 
             isManager(false), isAutoGenerated(false) {}
        
    User(string uname, string pwd, string name, string mail, int wId, bool manager = false)
        : username(uname), passwordHash(pwd), fullName(name), email(mail), walletId(wId),
          isManager(manager), isAutoGenerated(false) {}
};
    
// Danh sach nguoi dung va vi
unordered_map<string, User> users;
unordered_map<int, Wallet> wallets;

// Ham bam mat khau (gia lap voi salt don gian)
string hashPassword(string password) {
    hash<string> hasher;
    string salt = "simpleSalt123";
    return to_string(hasher(password + salt));
}

// Sinh mat khau ngau nhien
string sinhMatKhauNgauNhien() {
    string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    string pwd;
    srand(time(0));
    for (int i = 0; i < 8; i++) {
        pwd += chars[rand() % chars.size()];
    }
    return pwd;
}

// Sinh OTP
string sinhOTP() {
    srand(time(0));
    string otp = "";
    for (int i = 0; i < 6; i++) {
        otp += to_string(rand() % 10);
    }
    return otp;
}

// Luu du lieu vao file (dang van ban)
void luuDuLieu() {
    ofstream userFile("users.txt");
    if (!userFile.is_open()) {
        cerr << "Loi: Khong the mo users.txt de ghi!\n";
        return;
    }
    for (const auto& pair : users) {
        const User& user = pair.second;
        userFile << user.username << "|"
                 << user.passwordHash << "|"
                 << user.fullName << "|"
                 << user.email << "|"
                 << user.walletId << "|"
                 << (user.isManager ? "1" : "0") << "|"
                 << (user.isAutoGenerated ? "1" : "0") << "\n";
    }
    userFile.close();

    ofstream walletFile("wallets.txt");
    if (!walletFile.is_open()) {
        cerr << "Loi: Khong the mo wallets.txt de ghi!\n";
        return;
    }
    for (const auto& pair : wallets) {
        const Wallet& wallet = pair.second;
        walletFile << wallet.walletId << "|"
                   << wallet.balance << "|";
        for (size_t i = 0; i < wallet.transactionLog.size(); ++i) {
            walletFile << wallet.transactionLog[i];
            if (i < wallet.transactionLog.size() - 1) walletFile << ";";
        }
        walletFile << "\n";
    }
    walletFile.close();

#ifdef _WIN32
    system("copy users.txt backup_users.txt >nul 2>&1");
    system("copy wallets.txt backup_wallets.txt >nul 2>&1");
#else
    system("cp users.txt backup_users.txt >/dev/null 2>&1");
    system("cp wallets.txt backup_wallets.txt >/dev/null 2>&1");
#endif
    cout << "Du lieu da duoc luu va sao luu.\n";
}

// Doc du lieu tu file (dang van ban)
bool docDuLieuTuFile(const string& userFileName, const string& walletFileName) {
    users.clear();
    wallets.clear();

    ifstream userFile(userFileName);
    if (userFile.is_open()) {
        string line;
        while (getline(userFile, line)) {
            stringstream ss(line);
            string username, passwordHash, fullName, email;
            int walletId;
            bool isManager, isAutoGenerated;

            getline(ss, username, '|');
            getline(ss, passwordHash, '|');
            getline(ss, fullName, '|');
            getline(ss, email, '|');
            ss >> walletId;
            ss.ignore(1);
            ss >> isManager;
            ss.ignore(1);
            ss >> isAutoGenerated;

            users.emplace(username, User(username, passwordHash, fullName, email, walletId, isManager));
            users[username].isAutoGenerated = isAutoGenerated;
        }
        userFile.close();
    } else {
        cout << "Khong tim thay du lieu nguoi dung trong " << userFileName << ". Bat dau moi.\n";
        return false;
    }

    ifstream walletFile(walletFileName);
    if (walletFile.is_open()) {
        string line;
        while (getline(walletFile, line)) {
            stringstream ss(line);
            int walletId, balance;
            string transactions;

            ss >> walletId;
            ss.ignore(1);
            ss >> balance;
            ss.ignore(1);
            getline(ss, transactions);

            Wallet wallet(walletId, balance);
            if (!transactions.empty()) {
                stringstream transStream(transactions);
                string trans;
                while (getline(transStream, trans, ';')) {
                    wallet.transactionLog.push_back(trans);
                }
            }
            wallets.emplace(walletId, wallet);
        }
        walletFile.close();
    } else {
        cout << "Khong tim thay du lieu vi trong " << walletFileName << ". Bat dau moi.\n";
        return false;
    }
    return true;
}











































