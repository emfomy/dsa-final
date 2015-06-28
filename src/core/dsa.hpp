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
#include <string>

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

// The number of recommend IDs
const int kNumRecommend = 10;

// Define types
typedef std::string ID;
typedef std::string Plaintext;
typedef __int128_t Ciphertext;
typedef int32_t Money;

}

#endif  // DSA_DSA_HPP_
