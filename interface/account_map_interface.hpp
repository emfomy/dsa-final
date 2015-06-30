////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// account_map_interface.hpp                                                  //
// The interface of class AccountMap                                          //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef DSA_ACCOUNT_MAP_INTERFACE_HPP_

#define DSA_ACCOUNT_MAP_INTERFACE_HPP_

#include "dsa.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

////////////////////////////////////////////////////////////////////////////////
// The class of a map of accounts                                             //
////////////////////////////////////////////////////////////////////////////////
class AccountMap {
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
  class Account* At( const ID& id );

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
  class Account* At( const ID& id, void** pit );

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
  bool Emplace( const ID& id, const Plaintext& plaintext );

  ////////////////////////////////////////////////////////////////////////////
  // Erase an account of target iterator                                    //
  //                                                                        //
  // Parameters:                                                            //
  // it: the iterator                                                       //
  ////////////////////////////////////////////////////////////////////////////
  void Erase( void* it );

  ////////////////////////////////////////////////////////////////////////////
  // Display existing IDs                                                   //
  //                                                                        //
  // Input Parameters:                                                      //
  // id: the ID                                                             //
  //                                                                        //
  // Ensure:                                                                //
  // Display best satisfying IDs to standand output, separated by ','       //
  ////////////////////////////////////////////////////////////////////////////
  void Existing( const ID& id );

  ////////////////////////////////////////////////////////////////////////////
  // Display unused IDs                                                     //
  //                                                                        //
  // Input Parameters:                                                      //
  // id: the ID                                                             //
  //                                                                        //
  // Ensure:                                                                //
  // Display best satisfying IDs to standand output, separated by ','       //
  ////////////////////////////////////////////////////////////////////////////
  void Unused( const ID& id );

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
  void Find( const ID& id, const class Account* account );
};

}

#endif  // DSA_ACCOUNT_MAP_INTERFACE_HPP_
