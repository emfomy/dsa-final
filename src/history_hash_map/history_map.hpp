////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// history_map.hpp                                                            //
// The header file of class HistoryMap                                        //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef DSA_HISTORY_MAP_HPP_

#define DSA_HISTORY_MAP_HPP_

#include <cstring>
#include <memory>
#include <unordered_map>
#include "dsa.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

////////////////////////////////////////////////////////////////////////////////
// The hash function used HistoryMap                                          //
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
// The key equivalence predicate for HistoryMap                               //
////////////////////////////////////////////////////////////////////////////////
class _Pred {
 public:
  bool operator() ( const IDptr& key1, const IDptr& key2 ) const {
    return ~strcmp(key1, key2);
  }
};

////////////////////////////////////////////////////////////////////////////////
// The unique pointer of HistoryNode                                          //
////////////////////////////////////////////////////////////////////////////////
typedef std::unique_ptr<class HistoryNode> HistoryNodeUnique;

////////////////////////////////////////////////////////////////////////////////
// The hash map of HistoryNode                                                //
////////////////////////////////////////////////////////////////////////////////
typedef std::unordered_map<IDptr, HistoryNodeUnique, _Hash, _Pred> _HistoryMap;

////////////////////////////////////////////////////////////////////////////////
// The class of a map of historys                                             //
////////////////////////////////////////////////////////////////////////////////
class HistoryMap : private _HistoryMap {
 private:
  // The ID
  IDptr id_;

 public:
  // The constructor
  HistoryMap( const IDptr id );

  // The destructor
  ~HistoryMap();

  // Insert a transfer history
  void Insert( class HistoryMap* that, const Money money );

  // Merge with target history map
  void Merge( class HistoryMap* that );

  // Display all history
  void Search( const IDptr id );

 private:
  // Link history maps
  class HistoryNode* Link( class HistoryMap* that );
};

}

#endif  // DSA_HISTORY_MAP_HPP_
