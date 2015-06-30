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
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
#include "dsa.hpp"

#include <iostream>

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

////////////////////////////////////////////////////////////////////////////////
// The unique pointer of Account                                              //
////////////////////////////////////////////////////////////////////////////////
typedef std::unique_ptr<class Account> _AccountUnique;

////////////////////////////////////////////////////////////////////////////////
// The hash map of Account                                                    //
////////////////////////////////////////////////////////////////////////////////
typedef std::unordered_map<ID, _AccountUnique> _AccountMap;

////////////////////////////////////////////////////////////////////////////////
// The score function of IDs                                                  //
//                                                                            //
// Input Parameters:                                                          //
// id1: an ID                                                                 //
// id2: another ID                                                            //
//                                                                            //
// Return Value:                                                              //
// the score of the IDs                                                       //
////////////////////////////////////////////////////////////////////////////////
static int IDScore( const ID& id1, const ID& id2 ) {
  int len1 = id1.size();
  int len2 = id2.size();
  int len = (len1 < len2) ? len1 : len2;
  int len_dif = abs(len1 - len2);

  int s = len_dif * (len_dif + 1) / 2;
  for ( auto i = 0; i < len; ++i) {
    s += ((id1[i] == id2[i]) ? 0 : (len-i));
  }
  return s;
}

////////////////////////////////////////////////////////////////////////////////
// The compare class of existing IDs                                          //
//                                                                            //
// Input Parameters:                                                          //
// id1: an ID                                                                 //
// id2: another ID                                                            //
//                                                                            //
// Return Value:                                                              //
// the score of the IDs                                                       //
////////////////////////////////////////////////////////////////////////////////
class IDExistingCompare {
 private:
  const ID*& idptr_;

 public:
  IDExistingCompare( const ID*& idptr ) : idptr_(idptr) {
  };

  bool operator()( const ID* lhs, const ID* rhs ) const {
    auto score1 = IDScore(*idptr_, *lhs);
    auto score2 = IDScore(*idptr_, *rhs);
    return (score1 != score2) ? (score1 < score2) : (*lhs < *rhs);
  }
};

////////////////////////////////////////////////////////////////////////////////
// The compare class of wildcard IDs                                          //
//                                                                            //
// Input Parameters:                                                          //
// id1: an ID                                                                 //
// id2: another ID                                                            //
//                                                                            //
// Return Value:                                                              //
// the score of the IDs                                                       //
////////////////////////////////////////////////////////////////////////////////
class IDWildcardCompare {
 public:
  IDWildcardCompare() {
  };

  bool operator()( const ID* lhs, const ID* rhs ) const {
    return (*lhs > *rhs);
  }
};

////////////////////////////////////////////////////////////////////////////////
// The priority queue of existing ID                                          //
////////////////////////////////////////////////////////////////////////////////
typedef std::priority_queue<
    const ID*, std::vector<const ID*>, IDExistingCompare
> _AccountExistingQueue;

////////////////////////////////////////////////////////////////////////////////
// The priority queue of wildcard ID                                          //
////////////////////////////////////////////////////////////////////////////////
typedef std::priority_queue<
    const ID*, std::vector<const ID*>, IDWildcardCompare
> _AccountWildcardQueue;

////////////////////////////////////////////////////////////////////////////////
// The stack of ID                                                            //
////////////////////////////////////////////////////////////////////////////////
typedef std::stack<const ID*> _AccountSrack;

////////////////////////////////////////////////////////////////////////////////
// The class of a map of accounts                                             //
////////////////////////////////////////////////////////////////////////////////
class AccountMap : private _AccountMap {
 private:
  // The pointer of ID for compare
  const ID* idptr_ = nullptr;

  // The priority queue of existing ID
  _AccountExistingQueue existing_queue_;

  // The priority queue of wildcard ID
  _AccountWildcardQueue wildcard_queue_;

  // The stack of ID
  _AccountSrack stack_;

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

  // Display an ID
  bool Display( const ID& id, int& num );

  // Display an ID
  bool Match( const ID& id, const ID& wildcard );

  // Display an ID
  bool Match( const char* id, const char* wildcard );
};

}

#endif  // DSA_ACCOUNT_MAP_HPP_
