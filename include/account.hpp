////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// account.hpp                                                                //
// The interface of class Account                                             //
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

  ////////////////////////////////////////////////////////////////////////////
  // The constructor of Account                                             //
  //                                                                        //
  // Parameters:                                                            //
  // id:        the ID                                                      //
  // plaintext: the plain password                                          //
  ////////////////////////////////////////////////////////////////////////////
  Account( const IDptr id, const Plaintext plaintext );

  ////////////////////////////////////////////////////////////////////////////
  // The destructor of Account                                              //
  ////////////////////////////////////////////////////////////////////////////
  ~Account();

  ////////////////////////////////////////////////////////////////////////////
  // Get the starting pointer of ID                                         //
  ////////////////////////////////////////////////////////////////////////////
  IDptr id() const;

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
  // Transfer money to target account                                       //
  //                                                                        //
  // Parameters:                                                            //
  // that:  target account                                                  //
  // money: the amount of money to transfer                                 //
  ////////////////////////////////////////////////////////////////////////////
  void Transfer( class Account* that, const Money money );

  ////////////////////////////////////////////////////////////////////////////
  // Merge with target account                                              //
  //                                                                        //
  // Parameters:                                                            //
  // that: target account                                                   //
  ////////////////////////////////////////////////////////////////////////////
  void Merge( class Account* that );

  ////////////////////////////////////////////////////////////////////////////
  // Display all history with target ID                                     //
  //                                                                        //
  // Parameters:                                                            //
  // id: target ID                                                          //
  //                                                                        //
  // Ensure:                                                                //
  // Display all history with target ID to standand output, line by line    //
  ////////////////////////////////////////////////////////////////////////////
  void Search( const IDptr id );
};

}

#endif  // DSA_ACCOUNT_HPP_
