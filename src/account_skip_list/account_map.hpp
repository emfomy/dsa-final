////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// account_map.hpp                                                            //
// The header file of class AccountMap                                        //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef DSA_ACCOUNT_MAP_HPP_

#define DSA_ACCOUNT_MAP_HPP_

#include "dsa.hpp"
#include "skip_list_for_account.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

////////////////////////////////////////////////////////////////////////////////
// The class of a map of accounts                                             //
////////////////////////////////////////////////////////////////////////////////
class AccountMap : private SkipList {
 private:
  using SkipList::Find;
  using SkipList::Insert;

 public:
  ////////////////////////////////////////////////////////////////////////////
  // The constructor of AccountMap                                          //
  ////////////////////////////////////////////////////////////////////////////
  AccountMap();

  ////////////////////////////////////////////////////////////////////////////
  // The destructor of AccountMap                                           //
  ////////////////////////////////////////////////////////////////////////////
  ~AccountMap();

  ////////////////////////////////////////////////////////////////////////////
  // Access account by its ID                                               //
  //                                                                        //
  // Parameters:                                                            //
  // id: the ID                                                             //
  //                                                                        //
  // Return Value:                                                          //
  // Target account if exists, null pointer if not exists                   //
  ////////////////////////////////////////////////////////////////////////////
  class Account* At( const IDptr id );

  ////////////////////////////////////////////////////////////////////////////
  // Access account by its ID                                               //
  //                                                                        //
  // Input Parameters:                                                      //
  // id: the ID                                                             //
  //                                                                        //
  // Output Parameters:                                                     //
  // pit: the pointer of iterator                                           //
  //                                                                        //
  // Return Value:                                                          //
  // Target account if exists, null pointer if not exists                   //
  ////////////////////////////////////////////////////////////////////////////
  class Account* At( const IDptr id, void** pit );

  ////////////////////////////////////////////////////////////////////////////
  // Display existing IDs                                                   //
  //                                                                        //
  // Input Parameters:                                                      //
  // id: the ID                                                             //
  //                                                                        //
  // Ensure:                                                                //
  // Display best satisfying IDs to standand output, separated by ','       //
  ////////////////////////////////////////////////////////////////////////////
  void Existing( const IDptr id );

  ////////////////////////////////////////////////////////////////////////////
  // Display unused IDs                                                     //
  //                                                                        //
  // Input Parameters:                                                      //
  // id: the ID                                                             //
  //                                                                        //
  // Ensure:                                                                //
  // Display best satisfying IDs to standand output, separated by ','       //
  ////////////////////////////////////////////////////////////////////////////
  void Unused( const IDptr id );

  ////////////////////////////////////////////////////////////////////////////
  // Find existing IDs that matches the wildcard ID                         //
  //   but is different from target account                                 //
  //                                                                        //
  // Input Parameters:                                                      //
  // id:      the wildcard ID                                               //
  // account: target account                                                //
  //                                                                        //
  // Ensure:                                                                //
  // Display all satisfying IDs to standand output,                         //
  //   separated by ',' in ascending dictionary order                       //
  ////////////////////////////////////////////////////////////////////////////
  void Find( const IDptr id, const class Account* account );

  ////////////////////////////////////////////////////////////////////////////
  // Construct and insert an account                                        //
  //                                                                        //
  // Parameters:                                                            //
  // id:        the ID                                                      //
  // plaintext: the plain password                                          //
  //                                                                        //
  // Return Value:                                                          //
  // true if insert succeeded, false if the ID already exists               //
  ////////////////////////////////////////////////////////////////////////////
  bool Emplace( const IDptr id, const Plaintext plaintext );

  ////////////////////////////////////////////////////////////////////////////
  // Erase an account of target iterator                                    //
  //                                                                        //
  // Parameters:                                                            //
  // it: the iterator                                                       //
  ////////////////////////////////////////////////////////////////////////////
  void Erase( void* it );
};

}

#endif  // DSA_ACCOUNT_MAP_HPP_
