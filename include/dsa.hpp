////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// dsa.hpp                                                                    //
// The header file of namespace dsa                                           //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef DSA_DSA_HPP_

#define DSA_DSA_HPP_

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
typedef char* IDptr;
typedef char Plaintext[kPlaintextLength+1];
typedef __int128_t Ciphertext;
typedef int32_t Money;

}

#endif  // DSA_DSA_HPP_
