////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// core.hpp                                                                   //
// The header file of core functions                                          //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef DSA_CORE_CORE_HPP_

#define DSA_CORE_CORE_HPP_

#include <cstdint>

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

// The maximum length of ID/Plaintext
const int kIDLength = 100;
const int kPlaintextLength = 100;

// The number of recommend IDs
const int kNumRecommend = 10;

// Define types
typedef char ID[kIDLength+1];
typedef char Plaintext[kPlaintextLength+1];
typedef __int128_t Ciphertext;
typedef int32_t Money;

}

#endif  // DSA_CORE_CORE_HPP_
