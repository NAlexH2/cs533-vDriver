#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Alex Harris <nharris@pdx.edu>");
MODULE_DESCRIPTION("Hello world! See my src comments on how to use me!");

/*
    The steps to see this are as follows:
        1. sudo dmesg -c (x2, it clears on the 2nd run)
        2. make all
        3. sudo insmod hello.ko
        4. sudo rmmod hello.ko
        5. sudo dmesg
*/

static int hello_world_init(void)
{
    printk(KERN_NOTICE "Hello, world!\n");
    return 0;
}

static void hello_world_exit(void)
{
    printk(KERN_NOTICE "Goodbye, kruel world..\n");
    printk(KERN_NOTICE "\nGet it? kruel as in k for kernel...? It's fine.\n");
}
 
module_init(hello_world_init);
module_exit(hello_world_exit);
 
