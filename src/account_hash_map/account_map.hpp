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
#include <unordered_map>
#include <vector>
#include "dsa.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

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
  int L1 = id1.size();
  int L2 = id2.size();
  int L = (L1 < L2) ? L1 : L2;
  int dL = abs(L1 - L2);

  int s = dL * (dL + 1) / 2;
  for ( auto i = 0; i < L; ++i) {
    s += (id1[i] == id2[i] ? 0 : (L-i));
  }
  return s;
}

////////////////////////////////////////////////////////////////////////////////
// The compare function of IDs                                                //
//                                                                            //
// Input Parameters:                                                          //
// id1: an ID                                                                 //
// id2: another ID                                                            //
//                                                                            //
// Return Value:                                                              //
// the score of the IDs                                                       //
////////////////////////////////////////////////////////////////////////////////
class IDCompare {
 private:
  const ID* idptr_;

 public:
  IDCompare( const ID& id ){
    idptr_ = &id;
  };
  bool operator()( const ID* lhs, const ID* rhs ) const {
    auto score1 = IDScore(*idptr_, *lhs);
    auto score2 = IDScore(*idptr_, *rhs);
    return (score1 != score2) ? (score1 > score2) : (*lhs > *rhs);
  }
};

////////////////////////////////////////////////////////////////////////////////
// The unique pointer of Account                                              //
////////////////////////////////////////////////////////////////////////////////
typedef std::unique_ptr<class Account> _AccountUnique;

////////////////////////////////////////////////////////////////////////////////
// The hash map of Account                                                    //
////////////////////////////////////////////////////////////////////////////////
typedef std::unordered_map<ID, _AccountUnique> _AccountMap;

////////////////////////////////////////////////////////////////////////////////
// The hash map of Account                                                    //
////////////////////////////////////////////////////////////////////////////////
typedef std::priority_queue<
    const ID*, std::vector<const ID*>, IDCompare
> _AccountQueue;

////////////////////////////////////////////////////////////////////////////////
// The class of a map of accounts                                             //
////////////////////////////////////////////////////////////////////////////////
class AccountMap : private _AccountMap {
 private:
  _AccountQueue* queue_ = nullptr;

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
