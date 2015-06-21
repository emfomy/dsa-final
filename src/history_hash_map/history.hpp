////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// history.hpp                                                           //
// The header file of class History                                           //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef DSA_HISTORT_HPP_

#define DSA_HISTORT_HPP_

#include <cstdint>
#include "dsa.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

// Define types
typedef uint64_t Time;

////////////////////////////////////////////////////////////////////////////////
// The class of a transfer history                                            //
////////////////////////////////////////////////////////////////////////////////
class History {
 private:
  // The counter
  static Time counter_;

  // The amount of money
  Money money_;

  // The time order
  Time time_;

 public:
  // Constructor
  History( const Money money );

  // Destructor
  ~History();
};

}

#endif  // DSA_HISTORT_HPP_
