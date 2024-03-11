obj-m += hello_world.o
KDIR = /usr/src/linux-headers-6.5.0-25-generic/

 
all: clean
	make -C $(KDIR)  M=$(shell pwd) modules
 
clean:
	make -C $(KDIR)  M=$(shell pwd) clean