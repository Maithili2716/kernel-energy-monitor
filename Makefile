obj-m := energy_mon.o

# Path to the kernel build directory
KDIR := /lib/modules/$(shell uname -r)/build

# Default target (called when you run 'make')
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

# Target to clean up compiled files
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

