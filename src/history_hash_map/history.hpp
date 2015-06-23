////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// history.hpp                                                                //
// The header file of class History                                           //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef DSA_HISTORT_HPP_

#define DSA_HISTORT_HPP_

#include <cstddef>
#include "dsa.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

// Define types
typedef size_t Time;

////////////////////////////////////////////////////////////////////////////////
// The class of a transfer history                                            //
////////////////////////////////////////////////////////////////////////////////
class History {
  friend class HistoryNode;

 private:
  // The counter
  static Time counter_;

  // The amount of money changes
  Money money_;

  // The time order
  Time time_;

 public:
  // Constructor
  History( const Money money );

  // Destructor
  ~History();

  // Get the amount of money changes
  Money money();
};

}

#endif  // DSA_HISTORY_HPP_
