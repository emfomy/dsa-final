////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// account.hpp                                                                //
// The interface of class Account                                             //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef DSA_INC_ACCOUNT_HPP_

#define DSA_INC_ACCOUNT_HPP_

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

  ////////////////////////////////////////////////////////////////////////////
  // The constructor of Account                                             //
  //                                                                        //
  // Parameters:                                                            //
  // id:        the ID                                                      //
  // plaintext: the plain password                                          //
  ////////////////////////////////////////////////////////////////////////////
  Account( const ID id, const Plaintext plaintext );

  ////////////////////////////////////////////////////////////////////////////
  // The destructor of Account                                              //
  ////////////////////////////////////////////////////////////////////////////
  ~Account();

  ////////////////////////////////////////////////////////////////////////////
  // Get the starting pointer of ID                                         //
  ////////////////////////////////////////////////////////////////////////////
  IDptr id();

  ////////////////////////////////////////////////////////////////////////////
  // Check password correction                                              //
  //                                                                        //
  // Parameters:                                                            //
  // plaintext: the plain password                                          //
  //                                                                        //
  // Return Value:                                                          //
  // true if the password is correct, false if not                          //
  ////////////////////////////////////////////////////////////////////////////
  bool Login( const Plaintext plaintext );

  ////////////////////////////////////////////////////////////////////////////
  // Merge with another account                                             //
  //                                                                        //
  // Parameters:                                                            //
  // that: another account                                                  //
  ////////////////////////////////////////////////////////////////////////////
  void Merge( Account* that );
};

}

#endif  // DSA_INC_ACCOUNT_HPP_
