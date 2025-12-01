**#KERNEL ENERGY MONTIOR**
A proof of concept Linux kernel module, desined to measure and accumulate the energy consumption (in joules) , of specific user space processes by hooking into the 
CPU's Intel RAPL(Running average power limit) interface.

This tool is the foundation for calculating the "Intelligence per watt" metric(IPW), for ai/ml workloads.


**Project Status**
1. Currently in its phase1, measures the global energy consumption.
2. Next phase is Process Tracking via the sched_switch hook.


**Pre-requisites**
1. Ubuntu/Debian based destribution (for kernel module development)
2. build essentials: GCC compiles , Make
3. linux-headers-$(uname-r):kernel headers matching the running kernel
4. msr-tools (for checking hardware compatibility): use command- "sudo modprobe msr" followed by "sudo rdmsr 0x611-d" in your terminal,if the output is a large number, the hardware is compatible.
5. Intel CPU with RAPL.


**Usage and Testing (phase1)**
1. clone the repository : "git clone
