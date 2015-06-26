////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// account.hpp                                                                //
// The header file of class Account                                           //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef DSA_ACCOUNT_HPP_

#define DSA_ACCOUNT_HPP_

#include "dsa.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

////////////////////////////////////////////////////////////////////////////////
// The class of a account                                                     //
////////////////////////////////////////////////////////////////////////////////
class Account {
 public:
  // The money
  Money money_ = 0;

 private:
  // The ID
  ID id_;

  // The ciphered password
  Ciphertext ciphertext_;

  // The map of history
  class HistoryMap* history_map_;

 public:
  // Constructor
  Account( const IDptr id, const Plaintext plaintext );

  // Destructor
  ~Account();

  // Get the starting pointer of ID
  const IDptr id() const;

  // Check password correction
  bool Login( const Plaintext plaintext );

  // Transfer money to an account
  void Transfer( class Account* that, const Money money );

  // Merge with target account
  void Merge( class Account* that );

  // Display all history with target ID
  void Search( const IDptr id );
};

}

#endif  // DSA_ACCOUNT_HPP_
