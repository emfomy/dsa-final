////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// account_map.hpp                                                            //
// The interface of class AccountMap                                          //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef DSA_ACCOUNT_MAP_HPP_

#define DSA_ACCOUNT_MAP_HPP_

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
  // Insert an account                                                      //
  //                                                                        //
  // Parameters:                                                            //
  // account: target account                                                //
  ////////////////////////////////////////////////////////////////////////////
  void Insert( class Account* account );

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
};

}

#endif  // DSA_ACCOUNT_MAP_HPP_
