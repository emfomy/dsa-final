////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// account_map.hpp                                                            //
// The header file of class AccountMap                                        //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef DSA_ACCOUNT_MAP_HPP_

#define DSA_ACCOUNT_MAP_HPP_

#include <memory>
#include <unordered_map>
#include "dsa.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

////////////////////////////////////////////////////////////////////////////////
// The unique pointer of Account                                              //
////////////////////////////////////////////////////////////////////////////////
typedef std::unique_ptr<class Account> AccountUnique;

////////////////////////////////////////////////////////////////////////////////
// The hash map of Account                                                    //
////////////////////////////////////////////////////////////////////////////////
typedef std::unordered_map<ID, AccountUnique> _AccountMap;

////////////////////////////////////////////////////////////////////////////////
// The class of a map of accounts                                             //
////////////////////////////////////////////////////////////////////////////////
class AccountMap : private _AccountMap {
 public:
  // Constructor
  AccountMap();

  // Destructor
  ~AccountMap();

  // Access account
  class Account* At( const ID& id );

  // Access account
  class Account* At( const ID& id, void** ppit );

  // Construct and insert account
  bool Emplace( const ID& id, const Plaintext plaintext );

  // Erase account
  void Erase( void* pit );

  // Display existing IDs
  void Existing( const ID& id );

  // Display unused IDs
  void Unused( const ID& id );

  // Find existing IDs
  void Find( const ID& id, const class Account* account );
};

}

#endif  // DSA_ACCOUNT_MAP_HPP_
