#ifndef INTEREST_CHECKING_ACCOUNTS_CLASS_H
#define INTERESTCHECKING_ACCOUNTS_CLASS_H

#include <iostream>
#include <iomanip>
#include <string>

#include "CheckingAccountsClass.h"

using namespace std;

class InterestCheckingAccountsClass : public CheckingAccountsClass {

protected:
  static float interestCheckingRate;              // annual interest rate earned when bal > minbal credited monthly
  static float minimmunBalanceRequired;           // minimum balance required to receive interest
  static float monthlyFeeChargeNoMinimumBalance;  // monthly fee (only charged if minimum balance not met)

public:
  InterestCheckingAccountsClass(
    string accountIdStr, string accountNameStr, float accountBalanceFl)
  : CheckingAccountsClass(accountIdStr,         accountNameStr,  accountBalanceFl) { }

  static void  setInterestCheckingRate(float interestCheckingRate)
  { /*$$*/ }
  static float getInterestCheckingRate()
  { return 0; /*$$*/ }

  static void  setMinimmunBlanceRequired(float minimmunBalanceRequired)
  { /*$$*/ }
  static float getMinimmunBlanceRequired()
  {
    return 0; /*$$*/
  }

  static void  setMonthlyFeeChargeNoMinimumBalance(float monthlyFeeChargeNoMinimumBalance)
  { /*$$*/ }
  static float getMonthlyFeeChargeNoMinimumBalance()
  { return 0; }

  void calculateInterest();
  void display();

};
#endif