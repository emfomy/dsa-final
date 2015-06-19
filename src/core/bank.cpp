////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// bank.cpp                                                                   //
// The class Bank                                                             //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "bank.hpp"
#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

////////////////////////////////////////////////////////////////////////////////
// The constructor of Bank                                                    //
////////////////////////////////////////////////////////////////////////////////
Bank::Bank() {
  account_map_ = new AccountMap();
}

////////////////////////////////////////////////////////////////////////////////
// The destructor of Bank                                                     //
////////////////////////////////////////////////////////////////////////////////
Bank::~Bank() {
  delete account_map_;
}

////////////////////////////////////////////////////////////////////////////////
// Login to a specific account                                                //
//                                                                            //
// Parameters:                                                                //
// id:       the ID of target account                                         //
// password: the plain password of target account                             //
//                                                                            //
// Ensure:                                                                    //
// Set the logined account as target account if permission allowed            //
////////////////////////////////////////////////////////////////////////////////
void Bank::Login( const ID id, const Plaintext password ) {
  auto account = account_map_->At(id);
  if ( account == nullptr ) {
    cout << "ID " << id << " not found" << endl;
  } else if ( !account->Login(password) ) {
    cout << "wrong password" << endl;
  } else {
    logined_account_ = account;
    cout << "success" << endl;
  }
}

////////////////////////////////////////////////////////////////////////////////
// Create a specific account with password                                    //
//                                                                            //
// Parameters:                                                                //
// id:       the ID of target account                                         //
// password: the plain password of target account                             //
//                                                                            //
// Ensure:                                                                    //
// Create target account if the ID is unused                                  //
////////////////////////////////////////////////////////////////////////////////
void Bank::Create( const ID id, const Plaintext password ) {
  auto account = account_map_->At(id);
  if ( account != nullptr ) {
    account_map_->Unused(id, ids_);
    cout << "ID " << id << " exists, " << ids_[0];
    for ( auto i = 1; i < kNumRecommend; ++i ) {
      cout << ',' << ids_[i];
    }
    cout << endl;
  } else {
    account_map_->Insert(new Account(id, password));
    cout << "success" << endl;
  }
}

////////////////////////////////////////////////////////////////////////////////
// Delete a specific account with password                                    //
//                                                                            //
// Parameters:                                                                //
// id:       the ID of target account                                         //
// password: the plain password of target account                             //
//                                                                            //
// Ensure:                                                                    //
// Delete target account if permission allowed                                //
////////////////////////////////////////////////////////////////////////////////
void Bank::Delete( const ID id, const Plaintext password ) {
  void* it;
  auto account = account_map_->At(id, &it);
  if ( account == nullptr ) {
    cout << "ID " << id << " not found" << endl;
  } else if ( !account->Login(password) ) {
    cout << "wrong password" << endl;
  } else {
    account_map_->Erase(it);
    cout << "success" << endl;
  }
}

////////////////////////////////////////////////////////////////////////////////
// Merge the second account into the first one                                //
//                                                                            //
// Parameters:                                                                //
// id1:       the ID of the first account                                     //
// password1: the plain password of the first account                         //
// id2:       the ID of the second account                                    //
// password2: the plain password of the second account                        //
//                                                                            //
// Ensure:                                                                    //
// Merge the second account into the first one and delete the second one      //
////////////////////////////////////////////////////////////////////////////////
void Bank::Merge( const ID id1, const Plaintext password1,
                  const ID id2, const Plaintext password2 ) {
  cout << "merge" << endl;
}

////////////////////////////////////////////////////////////////////////////////
// Deposit money into the logined account                                     //
//                                                                            //
// Parameters:                                                                //
// money: the amount of money to deposit                                      //
//                                                                            //
// Ensure:                                                                    //
// Deposit the amount of money into the logined account                       //
////////////////////////////////////////////////////////////////////////////////
void Bank::Deposit( const Money money ) {
  logined_account_->money_ += money;
  cout << "success, " << logined_account_->money_
       << " dollars in current account" << endl;
}

////////////////////////////////////////////////////////////////////////////////
// Withdraw money from the logined account                                    //
//                                                                            //
// Parameters:                                                                //
// money: the amount of money to withdraw                                     //
//                                                                            //
// Ensure:                                                                    //
// Withdraw the amount of money from the logined account                      //
//   if there is enough money                                                 //
////////////////////////////////////////////////////////////////////////////////
void Bank::Withdraw( const Money money ) {
  if ( logined_account_->money_ < money ) {
    cout << "fail, " << logined_account_->money_
         << " dollars only in current account" << endl;
  } else {
    logined_account_->money_ -= money;
    cout << "success, " << logined_account_->money_
         << " dollars left in current account" << endl;
  }
}

////////////////////////////////////////////////////////////////////////////////
// Transfer money from the logined account to a specific account              //
//                                                                            //
// Parameters:                                                                //
// id:    the ID of target account                                            //
// money: the amount of money to transfer                                     //
//                                                                            //
// Ensure:                                                                    //
// Transfer the amount of money from the logined account to target account    //
//   if there is enough money                                                 //
////////////////////////////////////////////////////////////////////////////////
void Bank::Transfer( const ID id, const Money money ) {
  auto account = account_map_->At(id);
  if ( account == nullptr ) {
    account_map_->Existing(id, ids_);
    cout << "ID " << id << " not found, " << ids_[0];
    for ( auto i = 1; i < kNumRecommend; ++i ) {
      cout << ',' << ids_[i];
    }
    cout << endl;
  } else if ( logined_account_->money_ < money ) {
    cout << "fail, " << logined_account_->money_
         << " dollars only in current account" << endl;
  } else {
    logined_account_->money_ -= money;
    account->money_ += money;
    cout << "success, " << logined_account_->money_
         << " dollars left in current account" << endl;
  }
}

////////////////////////////////////////////////////////////////////////////////
// Find all existing account IDs that matches the wildcard ID                 //
//   but is different from the logined account                                //
//                                                                            //
// Parameters:                                                                //
// id: the wildcard ID                                                        //
//                                                                            //
// Ensure:                                                                    //
// List all satisfying IDs separated by ',' in ascending dictionary order     //
////////////////////////////////////////////////////////////////////////////////
void Bank::Find( const ID id ) {
  account_map_->Existing(id, ids_);
  cout << ids_[0];
  for ( auto i = 1; i < kNumRecommend; ++i ) {
    cout << ',' << ids_[i];
  }
  cout << endl;
}

////////////////////////////////////////////////////////////////////////////////
// Search all transfer history of the logined account                         //
//   from/to a specific account                                               //
//                                                                            //
// Parameters:                                                                //
// id: the target ID                                                          //
//                                                                            //
// Ensure:                                                                    //
// List all transfer history in ascending time order                          //
////////////////////////////////////////////////////////////////////////////////
void Bank::Search( const ID id ) {
  auto account = account_map_->At(id);
  if ( account == nullptr ) {
    cout << "ID " << id << " not found" << endl;
  } else {
    cout << "history" << endl;
  }
}

}
