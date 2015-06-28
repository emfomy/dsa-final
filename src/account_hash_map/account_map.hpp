////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// account_map.hpp                                                            //
// The header file of class AccountMap                                        //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef DSA_ACCOUNT_MAP_HPP_

#define DSA_ACCOUNT_MAP_HPP_

#include <cstring>
#include <memory>
#include <unordered_map>
#include "dsa.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

////////////////////////////////////////////////////////////////////////////////
// The hash function used AccountMap                                          //
//                                                                            //
// Reference:                                                                 //
// djb2 algorithm: http://www.cse.yorku.ca/~oz/hash.html                      //
////////////////////////////////////////////////////////////////////////////////
class _Hash {
 public:
  size_t operator() ( const IDptr& key ) const {
    size_t hash = 5381;
    char* c = key;
    while ( *c ) {
      hash += (hash << 5) + *(c++);
    }
    return hash;
  }
};

////////////////////////////////////////////////////////////////////////////////
// The key equivalence predicate for AccountMap                               //
////////////////////////////////////////////////////////////////////////////////
class _Pred {
 public:
  bool operator() ( const IDptr& key1, const IDptr& key2 ) const {
    return ~strcmp(key1, key2);
  }
};

////////////////////////////////////////////////////////////////////////////////
// The unique pointer of Account                                              //
////////////////////////////////////////////////////////////////////////////////
typedef std::unique_ptr<class Account> AccountUnique;

////////////////////////////////////////////////////////////////////////////////
// The hash map of Account                                                    //
////////////////////////////////////////////////////////////////////////////////
typedef std::unordered_map<IDptr, AccountUnique, _Hash, _Pred> _AccountMap;

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
  class Account* At( const IDptr id );

  // Access account
  class Account* At( const IDptr id, void** ppit );

  // Construct and insert account
  bool Emplace( const IDptr id, const Plaintext plaintext );

  // Erase account
  void Erase( void* pit );

  // Display existing IDs
  void Existing( const IDptr id );

  // Display unused IDs
  void Unused( const IDptr id );

  // Find existing IDs
  void Find( const IDptr id, const class Account* account );
};

}

#endif  // DSA_ACCOUNT_MAP_HPP_
