# Philosepher_42  :tada:
In this repository u will see he basics of threading a process and how to work on the same memory space

# What is MultiThreads? 🧵

    Multithreading is a specialized form of multitasking
    and a multitasking is the feature that allows your computer 
    to run two or more programs concurrently.
    
 # What Are Threads? :clipboard:	
    A thread is a small sequence of programmed instructions.
    Threads refer to the highest level of code your processor can execute.
  
# What The point of mutex ? :dart:	

    the point of a mutex is to synchronize two threads. 
    When you have two threads attempting to access a single resource, the general pattern is to have the first block of code attempting access to set the mutex         before entering the code. 
    When the second code block attempts access, it sees that the mutex is set and waits until the first block of code is complete (and unsets the mutex),
    then  continues.
 
 # What is semaphores
 
   Semaphore is simply a variable that is non-negative and shared between threads. 
   This variable is used to solve the critical section problem and to achieve process synchronization in the multiprocessing environment. 
