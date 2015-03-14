Summary: 
The goal is to simulate a real time scheduling system supporting (1) different types of processes and (2) scheduling implementations. We will be using C++.

(1): As discussed in class, there are different kinds of process that schedulers have to handle. We intend to support simulation of both periodic and aperiodic tasks with varying levels of blocking IO, runtime, and priority. 

(2): Determining the different efficiencies of various scheduling implementations including, but not limited to, Earliest Deadline First, First-In First-Out, Round Robin, and Shortest Job First.

The idea is to create a main scheduler process which has access to a list of tasks. These tasks’ running times will be known within the task class. We plan to simulate preemption and manage priority and deadlines, while also keeping track of the status tasks. We want to be able to simulate different types of blocking from the various i/o operations that can be encountered in a system.

Information to gather:

From Individual Tasks: 
Time First Run
Time Last Run
Did the task meet the deadline
Priority of the task
Time Arrival
Turnaround Time 
Response Time

Overall Information: 
Average Response Time
Average Turnaround Time
Tasks that did not meet deadline
