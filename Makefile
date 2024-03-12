obj-m += hello.o
KDIR = /usr/src/linux-headers-6.5.0-25-generic/

 
all: clean
	$(MAKE) -C $(KDIR)  M=$(shell pwd) modules
	$(MAKE) cleaner
 
clean:
	make -C $(KDIR)  M=$(shell pwd) clean

cleaner:
	rm -rf *.o *~ core .depend .*.cmd *.mod.c .tmp_versions *.mod *.symvers *.order