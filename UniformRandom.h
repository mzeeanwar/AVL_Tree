#ifndef UNIFORM_RANDOM
#define UNIFORM_RANDOM

//#include <ctime>
//using namespace std;
#include <iostream>
#include <chrono>
#include <cmath>
#include <random>
#include <functional>
using namespace std;

// UniformRandom class
//
// CONSTRUCTION: with (a) no initializer or (b) a long
//     that specifies the initial state of the generator.
//     This random number generator is similar to 
//     drand48 in C/C++.
//
// ******************PUBLIC OPERATIONS*********************
//     Return a random number according to some distribution:
// int nextInt( )                          --> Uniform
// int nextDouble( )                       --> Uniform, [0 to 1)
// int nextInt( int high )                 --> Uniform [0..high)
// int nextInt( int low, int high )        --> Uniform [low..high)
// long nextLong( )                        --> Uniform

/**
 * Uniform Random Number generator class, using a 48-bit
 * linear congruential generator.
 */
class Random48
{
  private:
    static long long currentTimeMicroSeconds( )
    {
        auto now = chrono::high_resolution_clock::now( ).time_since_epoch( );       
        return (chrono::duration_cast<chrono::microseconds>( now ) ).count( );
    }
    
  public:
    /**
     * Construct this Random object with specified initial state
     */
    Random48( long long initialValue = currentTimeMicroSeconds( ) )
    {
        state = initialValue & MASK;
    }


    /**
     * Return a pseudorandom int, and change the
     * internal state.
     */
    int nextInt( )
    {
        return next( 32 );
    }
