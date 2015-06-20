////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// account.hpp                                                                //
// The header file of class Account                                           //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef DSA_CORE_ACCOUNT_HPP_

#define DSA_CORE_ACCOUNT_HPP_

#include "dsa.hpp"
#include "history_map.hpp"

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
  HistoryMap* history_map_;

 public:
  // Constructor
  Account( const ID id, const Plaintext plaintext );

  // Destructor
  ~Account();

  // Get the starting pointer of ID
  IDptr id();

  // Check password correction
  bool Login( const Plaintext plaintext );

  // Merge with target account
  void Merge( Account* that );

  // Display all history with target ID
  void Search( const ID id );
};

}

#endif  // DSA_CORE_ACCOUNT_HPP_
