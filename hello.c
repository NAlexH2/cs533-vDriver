#include <linux/kernel.h> // Following includes are Required for loading
#include <linux/init.h>   //   into the kernel and using printk.
#include <linux/module.h> // printk is for printing to kernel log.

// GPL is the most open, best to use in this example. Linux uses it by default.
MODULE_LICENSE("GPL");

// Best to let who know made this thing!
MODULE_AUTHOR("Alex Harris <nharris@pdx.edu>");

// Just a description someone can see with `modinfo hello.ko` after we add it
MODULE_DESCRIPTION("Hello world! See my src comments on how to use me!");

/*
    The steps to see this are as follows:
        1. sudo dmesg -c (it runs, then clears the kernel history)
        2. make all
        3. sudo insmod hello.ko
        4. sudo rmmod hello.ko
        5. sudo dmesg
*/

// What happens the moment the virtual device is added to the system.
static int hello_world_init(void)
{
    printk(KERN_ALERT "Hello, world!\n");
    return 0;
}

// What happens the moment the virtual device is removed from the system.
static void hello_world_exit(void)
{
    printk(KERN_ALERT "Goodbye, kruel world...\n");
    printk(KERN_ALERT ".........\n");
    printk(KERN_ALERT "Get it? kruel as in k for kernel...? It's fine.\n");
}
 
module_init(hello_world_init);
module_exit(hello_world_exit);
 
