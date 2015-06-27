////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// history_map_interface.hpp                                                  //
// The interface of class HistoryMap                                          //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef DSA_HISTORY_MAP_INTERFACE_HPP_

#define DSA_HISTORY_MAP_INTERFACE_HPP_

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
  //                                                                        //
  // Parameters:                                                            //
  // id: target ID                                                          //
  ////////////////////////////////////////////////////////////////////////////
  HistoryMap( const IDptr id );

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
  void Insert( class HistoryMap* that, const Money money );

  ////////////////////////////////////////////////////////////////////////////
  // Merge with target history map                                          //
  //                                                                        //
  // Parameters:                                                            //
  // that: target history map                                               //
  ////////////////////////////////////////////////////////////////////////////
  void Merge( class HistoryMap* that );

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
  void Search( const IDptr id );
};

}

#endif  // DSA_HISTORY_MAP_INTERFACE_HPP_
