////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// account.hpp                                                                //
// The header file of class Account                                           //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef DSA_CORE_ACCOUNT_HPP_

#define DSA_CORE_ACCOUNT_HPP_

#include "core.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

////////////////////////////////////////////////////////////////////////////////
// The class of a account                                                     //
////////////////////////////////////////////////////////////////////////////////
class Account
{
 private:
  // The ciphered password
  Ciphertext ciphertext_;

 public:
  // The money
  Money money_;

  Account(){};
  ~Account(){};

  // Check password
  bool Login( const Plaintext plaintext );
};

}

#endif  // DSA_CORE_ACCOUNT_HPP_
