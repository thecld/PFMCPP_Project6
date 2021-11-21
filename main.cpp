/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(float v, const char* n) : value(v),  name(n) {} //1
    float value;//2
    std::string name;//3
};

struct F                                //4
{
    T* compare(T& a, T& b) //5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        return nullptr;
    }
};

struct U
{
    float valueA { 0.f }, valueB { 0.f };
    float updateValuesU(float& newValue)      //12
    {
        std::cout << "U's valueA value: " << valueA << std::endl;
        valueA = newValue;
        std::cout << "U's valueA updated value: " << valueA << std::endl;
        while( std::abs(valueB - valueA) > 0.001f )
        {
            valueB += 0.5f;
        }
        std::cout << "U's memberB updated value: " << valueB << std::endl;
        return valueB * valueA;
    }
};

struct L
{
    static float updateValuesL(U& that, float& newValue )        //10
    {
        std::cout << "U's valueA value: " << that.valueA << std::endl;
        that.valueA = newValue;
        std::cout << "U's valueA updated value: " << that.valueA << std::endl;
        while( std::abs(that.valueB - that.valueA) > 0.001f )
        {
            that.valueB += 0.5f;
        }
        std::cout << "U's memberB updated value: " << that.valueB << std::endl;
        return that.valueB * that.valueA;
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
    auto* smaller = f.compare( bucketA, bucketB );                              //8
    if (smaller != nullptr)
	    std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    else
        std::cout << "smaller is a nullptr because a or / and b from compare function is / are a nullptr.\n";
    
    U containerA;
    float newValue = 5.f;
    std::cout << "[static func] containerA's multiplied values: " << L::updateValuesL( containerA, newValue ) << std::endl;                  //11
    
    U containerB;
    std::cout << "[member func] containerB's multiplied values: " << containerB.updateValuesU( newValue ) << std::endl;
}
