📌 Overview
This project demonstrates how to use the Function Call Operator () overloading to create a "Functor." A Functor is an object that acts like a function but maintains its own internal state. In this example, we build an Adder class that "remembers" a base value and adds it to any input provided.

🛠 Key Features
Operator Overloading: Overloading () to make an object callable.

Stateful Logic: Unlike a regular function, the Adder object keeps track of its base variable.

Input Validation: robust std::cin error handling using cin.clear() and cin.ignore().

STL Integration: Using std::vector to store results and a Range-based for loop for clean output.

💻 How to Run
Ensure you have a C++ compiler (GCC/Clang/MSVC).

Compile: g++ -o adder_tool main.cpp

Run: ./adder_tool

📝 Notes 

1. What is a Functor?
In C++, when you overload the () operator, you create a Functor.

Why use it? Regular functions are "stateless." Once they finish, they forget everything. A Functor is a class, so it can have private variables (like our base).

Syntax Rule: The operator() must be a member function. It cannot be a friend.

2. The const at the end of operator()

Notice the signature: int operator()(int x) const.
The const tells the compiler: "Calling this object like a function will NOT change the internal data of the object." This makes your code safer and allows you to pass Adder objects to other functions as const references.

3. Robust Input Handling

When users type "ABC" instead of a number, std::cin enters a "fail state."

cin.clear(): Resets the "fail" flag so the program can talk to the user again.

cin.ignore(...): Flushes the "garbage" characters out of the input buffer so they don't cause an infinite loop.

4. Modern Looping

Instead of the old for(int i=0; i<vec.size(); i++), we use the Range-based for loop:

C++
for (auto x : vec) {
    cout << x << endl;
}

This is the "Modern" way. It’s harder to make mistakes (like "off-by-one" errors) and much easier to read.

💡 Pro-Tip for the Code:

If you want to make this even more "Professional," you can change the for loop at the end to:
for (const auto& x : vec)
Even though an int is small, using const auto& is a best practice in C++ because it prevents unnecessary copying of data, which is vital when your vectors start holding massive amounts of data or complex robotic sensor objects.

Summary for your followers:
"Think of a Functor as a function with a memory. It’s the bridge between Object-Oriented Programming and Functional Programming."