////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// history_map.cpp                                                            //
// The class HistoryMap                                                       //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "history_map.hpp"
#include <iostream>
#include "history.hpp"
#include "history_node.hpp"

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

////////////////////////////////////////////////////////////////////////////////
// The constructor of HistoryMap                                              //
//                                                                            //
// Parameters:                                                                //
// id: target ID                                                              //
////////////////////////////////////////////////////////////////////////////////
HistoryMap::HistoryMap( const IDptr id ) : _HistoryMap() {
  id_ = id;
  (*this)[id_].reset(new HistoryNode(this));
}

////////////////////////////////////////////////////////////////////////////////
// The destructor of HistoryMap                                               //
////////////////////////////////////////////////////////////////////////////////
HistoryMap::~HistoryMap() {
}

////////////////////////////////////////////////////////////////////////////////
// Insert a transfer history from this account to target account              //
//                                                                            //
// Parameters:                                                                //
// that: the history map of target account                                    //
// money: the amount of money to transfer                                     //
////////////////////////////////////////////////////////////////////////////////
void HistoryMap::Insert( HistoryMap* that, const Money money ) {
  // Insert node in this map
  auto& uniptr12 = (*this)[that->id_];
  if ( !uniptr12 ) {
    uniptr12.reset(new HistoryNode(this));
  }

  if ( !uniptr12->that_node_ ) {
    // Insert node in that map
    auto& uniptr21 = (*that)[this->id_];
    if ( !uniptr21 ) {
      uniptr21.reset(new HistoryNode(that));
    }

    // Link two nodes
    uniptr12->Link(uniptr21.get());
  }

  // Insert money
  uniptr12->Insert(money);
}

////////////////////////////////////////////////////////////////////////////////
// Merge with target history map                                              //
//                                                                            //
// Parameters:                                                                //
// that: target history map                                                   //
////////////////////////////////////////////////////////////////////////////////
void HistoryMap::Merge( HistoryMap* that ) {
  HistoryNode *node11 = nullptr, *node21 = nullptr;

  // Merge history
  for ( auto& it : *that ) {
    auto& uniptr23 = it.second;
    auto& uniptr13 = (*this)[it.first];
    if ( !uniptr13 ) {
      uniptr13.reset(new HistoryNode(this));
    }
    auto node32 = uniptr23->that_node_;
    auto node31 = uniptr13->that_node_;
    HistoryMap *map3 = nullptr;

    // Merge *-that history into *-this history
    if ( !node32 ) {
      map3 = node32->this_map_;
      if ( node31 ) {
        node31 = new HistoryNode(map3);
        (*map3)[this->id_].reset(node31);
        uniptr13->Link(node31);
      }
      node31->existing_.merge(node32->existing_);
      node32->that_node_ = nullptr;
    }

    // Merge that-* history into this-* history
    if ( map3 == this ) {
      node11 = uniptr13.get();
      node21 = uniptr23.get();
    } else {
      uniptr13->existing_.merge(uniptr23->existing_);
      uniptr13->deleted_.merge(uniptr23->deleted_);
      uniptr23->that_node_ = nullptr;
    }
  }

  // Merge that-this history into this-this history
  node11->existing_.merge(node21->existing_);
  node11->deleted_.merge(node21->deleted_);
  node21->that_node_ = nullptr;
}

////////////////////////////////////////////////////////////////////////////////
// Display all history with target ID                                         //
//                                                                            //
// Parameters:                                                                //
// id: target ID                                                              //
//                                                                            //
// Ensure:                                                                    //
// Display 'no record' if no record exists                                    //
// Display all history with target ID to standand output, line by line        //
////////////////////////////////////////////////////////////////////////////////
void HistoryMap::Search( const IDptr id ) {
  auto it = find(id);
  if ( it == end() ) {
    cout << "no record" << endl;
  } else {
    it->second->Display(id);
  }
}

}
