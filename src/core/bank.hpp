////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// bank.hpp                                                                   //
// The header file of class Bank                                              //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef DSA_BANK_HPP_

#define DSA_BANK_HPP_

#include "dsa.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

////////////////////////////////////////////////////////////////////////////////
// The class of a bank                                                        //
////////////////////////////////////////////////////////////////////////////////
class Bank {
 private:
  // The map of accounts
  class AccountMap* account_map_;

  // The logined account
  class Account* logined_account_ = nullptr;

 public:
  // Constructor
  Bank();

  // Destructor
  ~Bank();

  // Login an account
  void Login( const ID& id, const Plaintext& password );

  // Create an account
  void Create( const ID& id, const Plaintext& password );

  // Delete an account
  void Delete( const ID& id, const Plaintext& password );

  // Merge two accounts
  void Merge( const ID& id1, const Plaintext& password1, 
              const ID& id2, const Plaintext& password2 );

  // Deposit money
  void Deposit( const Money money );

  // Withdraw money
  void Withdraw( const Money money );

  // Transfer money to an account
  void Transfer( const ID& id, const Money money );

  // Find accounts
  void Find( const ID& id );

  // Search account history
  void Search( const ID& id );
};

}

#endif  // DSA_BANK_HPP_
