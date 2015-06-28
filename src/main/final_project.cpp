////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// final_project.cpp                                                          //
// The main functions                                                         //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

#include "dsa.hpp"
#include "bank.hpp"
#include "account.hpp"

using namespace std;
using namespace dsa;

////////////////////////////////////////////////////////////////////////////////
// Main function                                                              //
////////////////////////////////////////////////////////////////////////////////
int main( int argc, char const *argv[] ) {
  Bank bank;

  ID id1, id2;
  Plaintext password1, password2;
  Money money;

  ios::sync_with_stdio(false);

  // Read commands
  string str;
  while ( cin >> str ) {
    if ( str == "login" ) {
      cin >> id1 >> password1;
      bank.Login(id1, password1);
    } else if ( str == "create" ) {
      cin >> id1 >> password1;
      bank.Create(id1, password1);
    } else if ( str == "delete" ) {
      cin >> id1 >> password1;
      bank.Delete(id1, password1);
    } else if ( str == "merge" ) {
      cin >> id1 >> password1 >> id2 >> password2;
      bank.Merge(id1, password1, id2, password2);
    } else if ( str == "deposit" ) {
      cin >> money;
      bank.Deposit(money);
    } else if ( str == "withdraw" ) {
      cin >> money;
      bank.Withdraw(money);
    } else if ( str == "transfer" ) {
      cin >> id1 >> money;
      bank.Transfer(id1, money);
    } else if ( str == "find" ) {
      cin >> id1;
      bank.Find(id1);
    } else if ( str == "search" ) {
      cin >> id1;
      bank.Search(id1);
    }
  }
}
