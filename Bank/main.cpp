#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

#include "BankAccountsClass.h"
#include "CheckingAccountsClass.h"
#include "InterestCheckingAccountsClass.h"
#include "SavingsAccountsClass.h"
#include "TransactionsClass.h"

using namespace std;

const string BANK_CONFIGURATION_FILE_NAME_STR         = "InfoBankConfig.txt";
const string BANK_ACCOUNTS_FILE_NAME_STR              = "InfoBankAccounts.txt";
const string BANK_ACCOUNTS_TRANSACTIONS_FILE_NAME_STR = "InfoBankAccountsTransactions.txt";

void CheckFileStreamOpen(string fileNameStr, ifstream& inFile);
void CheckFileStreamOpen(string fileNameStr, ofstream& outFile);
void ReadConfigurationFile(string bankConfigurationFileNameStr);
void ReadInFromBankAccountsFile
(string bankAccountsFileNameStr,
 BankAccountsClass** &bankAccountsAry, unsigned& accountsCount);
void ReadInFromTransactionsFile
(string transactionsFileNameStr,
 TransactionsClass*  &transactionsAry, unsigned& transactionsCountUns);
void ProcessTransactions
(TransactionsClass*   transactionsAry, unsigned& transactionsCountUns,
 BankAccountsClass**& bankAccountsAry, unsigned& accountsCountUns);
bool getMatchingBankAccountIndexUns(
  BankAccountsClass**& bankAccountsAry, unsigned  accountsCountUns,
  string accountIdStr, unsigned& bankAccountIndex);
void UpdateBankAccountsFile
(string   bankAccountsFileNameStr,
 BankAccountsClass**& bankAccountsAry, unsigned totalNoBankAccountsUns);

int main() {
  BankAccountsClass** bankAccountsAry      = nullptr;
  TransactionsClass*  transactionsAry      = nullptr;
  unsigned            accountsCountUns     = 0;
  unsigned            transactionsCountUns = 0;

  cout << setprecision(2) << fixed << showpoint;           //  set up output for dollar amounts

  ReadConfigurationFile (BANK_CONFIGURATION_FILE_NAME_STR);
  ReadInFromBankAccountsFile (BANK_ACCOUNTS_FILE_NAME_STR,bankAccountsAry, accountsCountUns);
  ReadInFromTransactionsFile (BANK_ACCOUNTS_TRANSACTIONS_FILE_NAME_STR,transactionsAry, transactionsCountUns);
  ProcessTransactions (transactionsAry, transactionsCountUns,bankAccountsAry, accountsCountUns);
  UpdateBankAccountsFile (BANK_ACCOUNTS_FILE_NAME_STR,bankAccountsAry, accountsCountUns);

} // int main()

void CheckFileStreamOpen(string fileNameStr, ifstream& inFile) {
  /*$$*/
}

void CheckFileStreamOpen(string fileNameStr, ofstream& outFile) {
  /*$$*/
}

void ReadConfigurationFile(string bankConfigurationFileNameStr) {
  /*$$*/
}

void ReadInFromBankAccountsFile
(string bankAccountsFileNameStr, 
 BankAccountsClass** &bankAccountsAry, unsigned& accountsCountUns) {
  /*$$*/
}//ReadInFromBankAccountsFile()

void ReadInFromTransactionsFile (string transactionsFileNameStr, TransactionsClass* &transactionsAry,  unsigned& transactionsCountUns) {
  /*$$*/
}//ReadInFromTransactionsFile

void ProcessTransactions (TransactionsClass   *transactionsAry, unsigned& transactionsCountUns, BankAccountsClass** &bankAccountsAry, unsigned& accountsCountUns) {
  /*$$*/
}//ProcessTransactions

bool getMatchingBankAccountIndexUns(BankAccountsClass** &bankAccountsAry, unsigned  accountsCountUns, string accountIdStr, unsigned& bankAccountIndex) {
    bankAccountIndex = 0;
    for (; bankAccountIndex < accountsCountUns; ++bankAccountIndex)
        if (bankAccountsAry[bankAccountIndex]->getAcountIdStr() == accountIdStr) {
        return true;
        }
    return false;
}

void UpdateBankAccountsFile (string bankAccountsFileNameStr, BankAccountsClass**& bankAccountsAry, unsigned accountsCountUns) {
    ofstream outFile(bankAccountsFileNameStr);
    CheckFileStreamOpen(bankAccountsFileNameStr, outFile);
    cout << "Updating " << bankAccountsFileNameStr << endl << "-----------------------------" << endl;

    for (unsigned writeIndex = 0; writeIndex < accountsCountUns; ++writeIndex)
        outFile <<
        bankAccountsAry[writeIndex]->getAcountIdStr()      << "," <<
        bankAccountsAry[writeIndex]->getAccountOwnerStr()  << "," <<
        bankAccountsAry[writeIndex]->getAccountBalanceFl() << endl;
    outFile.close();
};