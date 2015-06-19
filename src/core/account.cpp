////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// account.cpp                                                                //
// The class Account                                                          //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "account.hpp"
#include "md5.h"

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

////////////////////////////////////////////////////////////////////////////////
// Check password correction                                                  //
//                                                                            //
// Parameters:                                                                //
// plaintext: the plain password                                              //
//                                                                            //
// Return Value:                                                              //
// true if the password is correct, false if not                              //
////////////////////////////////////////////////////////////////////////////////
bool Account::Login( const Plaintext plaintext ) {
  MD5 md5(plaintext);
  return (ciphertext_ == *reinterpret_cast<const Ciphertext*>(md5.result()));
}

}
