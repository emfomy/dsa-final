////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// bank.hpp                                                                   //
// The interface of class Bank                                                //
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
 public:
  ////////////////////////////////////////////////////////////////////////////
  // The constructor of Bank                                                //
  ////////////////////////////////////////////////////////////////////////////
  Bank();

  ////////////////////////////////////////////////////////////////////////////
  // The destructor of Bank                                                 //
  ////////////////////////////////////////////////////////////////////////////
  ~Bank();

  ////////////////////////////////////////////////////////////////////////////
  // Login to a specific account                                            //
  //                                                                        //
  // Parameters:                                                            //
  // id:       the ID of target account                                     //
  // password: the plain password of target account                         //
  //                                                                        //
  // Ensure:                                                                //
  // Set the logined account as target account if permission allowed        //
  ////////////////////////////////////////////////////////////////////////////
  void Login( const ID id, const Plaintext password );

  ////////////////////////////////////////////////////////////////////////////
  // Create a specific account with password                                //
  //                                                                        //
  // Parameters:                                                            //
  // id:       the ID of target account                                     //
  // password: the plain password of target account                         //
  //                                                                        //
  // Ensure:                                                                //
  // Create target account if the ID is unused                              //
  ////////////////////////////////////////////////////////////////////////////
  void Create( const ID id, const Plaintext password );

  ////////////////////////////////////////////////////////////////////////////
  // Delete a specific account with password                                //
  //                                                                        //
  // Parameters:                                                            //
  // id:       the ID of target account                                     //
  // password: the plain password of target account                         //
  //                                                                        //
  // Ensure:                                                                //
  // Delete target account if permission allowed                            //
  ////////////////////////////////////////////////////////////////////////////
  void Delete( const ID id, const Plaintext password );

  ////////////////////////////////////////////////////////////////////////////
  // Merge the second account into the first one                            //
  //                                                                        //
  // Parameters:                                                            //
  // id1:       the ID of the first account                                 //
  // password1: the plain password of the first account                     //
  // id2:       the ID of the second account                                //
  // password2: the plain password of the second account                    //
  //                                                                        //
  // Ensure:                                                                //
  // Merge the second account into the first one and delete the second one  //
  ////////////////////////////////////////////////////////////////////////////
  void Merge( const ID id1, const Plaintext password1,
              const ID id2, const Plaintext password2 );

  ////////////////////////////////////////////////////////////////////////////
  // Deposit money into the logined account                                 //
  //                                                                        //
  // Parameters:                                                            //
  // money: the amount of money to deposit                                  //
  //                                                                        //
  // Ensure:                                                                //
  // Deposit the amount of money into the logined account                   //
  ////////////////////////////////////////////////////////////////////////////
  void Deposit( const Money money );

  ////////////////////////////////////////////////////////////////////////////
  // Withdraw money from the logined account                                //
  //                                                                        //
  // Parameters:                                                            //
  // money: the amount of money to withdraw                                 //
  //                                                                        //
  // Ensure:                                                                //
  // Withdraw the amount of money from the logined account                  //
  //   if there is enough money                                             //
  ////////////////////////////////////////////////////////////////////////////
  void Withdraw( const Money money );

  ////////////////////////////////////////////////////////////////////////////
  // Transfer money from the logined account to a specific account          //
  //                                                                        //
  // Parameters:                                                            //
  // id:    the ID of target account                                        //
  // money: the amount of money to transfer                                 //
  //                                                                        //
  // Ensure:                                                                //
  // Transfer the amount of money from the logined account to target        //
  //   account if there is enough money                                     //
  ////////////////////////////////////////////////////////////////////////////
  void Transfer( const ID id, const Money money );

  ////////////////////////////////////////////////////////////////////////////
  // Find all existing account IDs that matches the wildcard ID             //
  //   but is different from the logined account                            //
  //                                                                        //
  // Parameters:                                                            //
  // id: the wildcard ID                                                    //
  //                                                                        //
  // Ensure:                                                                //
  // List all satisfying IDs separated by ',' in ascending dictionary order //
  ////////////////////////////////////////////////////////////////////////////
  void Find( const ID id );

  ////////////////////////////////////////////////////////////////////////////
  // Search all transfer history of the logined account                     //
  //   from/to a specific account                                           //
  //                                                                        //
  // Parameters:                                                            //
  // id: target ID                                                          //
  //                                                                        //
  // Ensure:                                                                //
  // List all transfer history line by line in ascending time order         //
  ////////////////////////////////////////////////////////////////////////////
  void Search( const ID id );
};

}

#endif  // DSA_BANK_HPP_
