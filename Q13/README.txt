🛡️ Modern C++: Mastering the mutable Keyword

📌 Overview
This tutorial introduces the mutable keyword a powerful tool for maintaining Logical Constness. We demonstrate how to create a CallCounter that tracks how many times a message has been sent, even when the "calling" function is strictly marked as const.

🛠 Key Features
The mutable Specifier: Allows specific member variables to be modified inside const member functions.

Logical Constness: Differentiating between "changing the object's data" and "changing the object's performance/metadata."

Const-Correct API: Designing classes that look "Read-Only" to the user but perform "Housekeeping" internally.

🎯 Learning Outcomes
By the end of this tutorial, you will understand:

When to break the const rule: Using mutable for counters, caches, or mutexes.

Class Design: How to build a "Silent Monitor" that tracks usage without needing to make every function "Write-enabled."

Hardware Context: Why mutable is essential for thread safety (mutexes) in embedded systems and robotics.

📝 Notes 
1. What is "Logical Constness"?
In C++, a const function like void call() const promises the user: "This function will not change the personality of this object." * To the user, printing a message shouldn't "change" the CallCounter.

However, we (the developers) want to track how many times it was called.

mutable allows us to track this "behind the scenes" metadata without breaking the const promise to the user.

2. The mutable Syntax
In the private section, we declare:
mutable int count;
This tells the compiler: "Even if this object is a const CallCounter, you are allowed to increment this specific integer."

3. Real-World Application: The "Silent Monitor"
In a real robotic system, you might have a const Sensor object. You want to keep track of how many times the sensor was read (for maintenance logs).

The user should see a const sensor so they don't accidentally change the calibration.

The mutable counter allows the system to log usage statistics automatically in the background.

4. Code Breakdown
C++
void call(string msg) const {
    count += 1; // This only works because 'count' is mutable!
    cout << "[" << count << "] " << msg << endl;
}

If you remove the mutable keyword from the class definition, this code will fail to compile. This is the core proof of the tutorial.

💡 Pro-Tip:
Always ask yourself: "Does changing this variable change what the object IS, or just what the object DOES?"

If it changes what the object is (like changing a Motor's target speed), do NOT use mutable.

If it's just "housekeeping" (like counting calls or logging time), mutable is the professional choice.