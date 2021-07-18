#ifndef CHECKING_ACCOUNTS_CLASS_H
#define CHECKING_ACCOUNTS_CLASS_H

#include <iostream>
#include <iomanip>
#include <string>

#include "BankAccountsClass.h"

using namespace std;

class CheckingAccountsClass : public BankAccountsClass {

protected:

  static float checkingMinimumFl;
  static float chargePerCheckFl;

public:

  CheckingAccountsClass(string accountIdStr, string accountNameStr, float accountBalanceFl)
    :BankAccountsClass(accountIdStr, accountNameStr, accountBalanceFl)
  {}

  static void  setCheckingMinimumFl(float checkingMinimumFl ) 
  { /*$$*/ }
  static float getCheckingMinimumFl(void) 
  { return 0 /*$$*/; }

  static void  setChargePerCheckFl(float chargePerCheckFl)
  { /*$$*/ }
  static float getChargePerCheckFl(void)
  {
    return 0; /*$$*/
  }

  void cashCheck(float);
  void display();

};
#endif