/*
 Project 6: Part 1 / 2
 Video: Chapter 3 Part 2

Create a branch named Part1

Purpose:  This project will show you the difference between member functions and static class functions, as well as the difference between pointers and references and the code semantics that accompany pointers and references.

 Pointers

 Please look at the screenshot in the files to see what happens if you paste this assignment into an existing cpp file in an xcode project
 
 Task: replace all of the <#place holder#> placeholders with proper names and types that will make this program compile and run.
 
 press the Compile, link and run... button and work your way through all of the error messages.
 

 steps:
 
 1) finish implementing the constructor for T. the constructor parameters need to initialize 2) and 3)
 
 2) provide a member variable in T of a type of your choosing that works with the compare function below T
         note the name of the variable used in the compare function
 
 3) provide a member variable of type std::string in T that works with the *first* cout statement in main().
         note the name of the variable used in the *first* cout statement in main()
 
 4) finish defining the struct with the compare function
 5) provide proper types for the arguments to compare, and a proper return value
         be sure to make it work with the pointer semantics being used in the if statements.
         see 8) for a hint about what type to use.
 
 6) finish instantiating the two T instances being declared in main(), based on the constructor you finished implementing in T
     Their names (line 105,106) are different than the member variables names (line 77), even tho the placeholders share the same name.
     Don't let this confuse you.
 
 7) Declare 'f' with the proper type so the call to f.compare works
 
 8) call f.compare() with the correct arguments, based on 2) and 5)
 
 9) correct the cout that uses smaller's member variable with some safe pointer usage.
         the possible return values of the compare() function should give you a hint.
 
 10) complete the implementation for the static function in <structName2>
 
 11) call the <structName2> static function correctly in main()
 
 12) replicate the functionality of <structName2>'s static function by implementing a member function in U that does the same thing.
 
 13) remember the rules for using pointers!  What is the one thing we always do before we use a pointer?
 
 After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

#include <iostream>
#include <string>
struct T
{
    T(float v, const char* n) : value(v),  name(n) {} //1
    float value;//2
    std::string name;//3 -> (A) Why there's char* in the T constructor and std::string here? I thought char is just for one letter?
};

struct F                                //4
{
    T* compare(T* a, T* b) //5 -> (B) So here struct F is used strictly as a class for comparirng 2 values of class T, right? Thanks to the use of pointers it won't copy any values from T, it'll just compare them without the need of additional memory, except for the addresses? Also I don't fully understand why the function type also needs to be a pointer.
    {
        if( a->value < b->value ) return a;
        if( a->value > b->value ) return b;
        return nullptr;
    }
};

struct U
{
    float valueA { 0.f }, valueB { 0.f };
    float updateValuesU(* newValue)      //12 (C) what type should I use here? Float? But why it's a pointer?
    {
        
    }
};

struct L
{
    static float updateValuesL(U* that, U* newValue )        //10
    {
        std::cout << "U's valueA value: " << that->valueA << std::endl;
        that->valueA = newValue->valueB;
        std::cout << "U's valueA updated value: " << that->valueA << std::endl;
        while( std::abs(that->valueB - that->valueA) > 0.001f )
        {
            /*
             write something that makes the distance between that-><#name2#> and that->name1 get smaller
             */
            that->valueB += 0.5f;
        }
        std::cout << "U's memberB updated value: " << that->valueB << std::endl;
        return that->valueB * that->valueA;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already:
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T bucketA( 5, "Bucket A" );                                             //6
    T bucketB( 7, "Bucket B" );                                             //6
    
    F f;                                            //7
    auto* smaller = f.compare( &bucketA, &bucketB );                              //8
    if (smaller != nullptr)
		std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    
    U containerA;
    float newValue = 5.f;
    std::cout << "[static func] containerA's multiplied values: " << L::updateValuesL( , ) << std::endl;                  //11
    
    U containerB;
    std::cout << "[member func] containerB's multiplied values: " << containerB.updateValuesU( &newValue ) << std::endl;
}
