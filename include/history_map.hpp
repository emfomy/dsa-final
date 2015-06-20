////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// history_map.hpp                                                            //
// The interface of class HistoryMap                                          //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef DSA_HISTORY_MAP_HPP_

#define DSA_HISTORY_MAP_HPP_

#include "dsa.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

////////////////////////////////////////////////////////////////////////////////
// The class of a map of historys                                             //
////////////////////////////////////////////////////////////////////////////////
class HistoryMap {
 public:
  ////////////////////////////////////////////////////////////////////////////
  // The constructor of HistoryMap                                          //
  ////////////////////////////////////////////////////////////////////////////
  HistoryMap( const ID id );

  ////////////////////////////////////////////////////////////////////////////
  // The destructor of HistoryMap                                           //
  ////////////////////////////////////////////////////////////////////////////
  ~HistoryMap();

  ////////////////////////////////////////////////////////////////////////////
  // Insert a transfer history from this account to target account          //
  //                                                                        //
  // Parameters:                                                            //
  // that: the history map of target account                                //
  // money: the amount of money to transfer                                 //
  ////////////////////////////////////////////////////////////////////////////
  void Insert( HistoryMap* that, const Money money );

  ////////////////////////////////////////////////////////////////////////////
  // Merge with target history map                                          //
  //                                                                        //
  // Parameters:                                                            //
  // that: target history map                                               //
  ////////////////////////////////////////////////////////////////////////////
  void Merge( HistoryMap* that );

  ////////////////////////////////////////////////////////////////////////////
  // Display all history with target ID                                     //
  //                                                                        //
  // Parameters:                                                            //
  // id: target ID                                                          //
  //                                                                        //
  // Ensure:                                                                //
  // Display 'no record' if no record exists                                //
  // Display all history with target ID to standand output, line by line    //
  ////////////////////////////////////////////////////////////////////////////
  void Search( const ID id );
};

}

#endif  // DSA_ACCOUNT_MAP_HPP_
