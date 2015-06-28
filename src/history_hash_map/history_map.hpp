////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// history_map.hpp                                                            //
// The header file of class HistoryMap                                        //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef DSA_HISTORY_MAP_HPP_

#define DSA_HISTORY_MAP_HPP_

#include <memory>
#include <unordered_map>
#include "dsa.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

////////////////////////////////////////////////////////////////////////////////
// The unique pointer of HistoryNode                                          //
////////////////////////////////////////////////////////////////////////////////
typedef std::unique_ptr<class HistoryNode> HistoryNodeUnique;

////////////////////////////////////////////////////////////////////////////////
// The hash map of HistoryNode                                                //
////////////////////////////////////////////////////////////////////////////////
typedef std::unordered_map<ID, HistoryNodeUnique> _HistoryMap;

////////////////////////////////////////////////////////////////////////////////
// The class of a map of historys                                             //
////////////////////////////////////////////////////////////////////////////////
class HistoryMap : private _HistoryMap {
 private:
  // The ID
  ID id_;

 public:
  // The constructor
  HistoryMap( const ID& id );

  // The destructor
  ~HistoryMap();

  // Insert a transfer history
  void Insert( class HistoryMap* that, const Money money );

  // Merge with target history map
  void Merge( class HistoryMap* that );

  // Display all history
  void Search( const ID& id );
};

}

#endif  // DSA_HISTORY_MAP_HPP_
