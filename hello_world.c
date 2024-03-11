#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Alex Harris <nharris@pdx.edu>");
MODULE_DESCRIPTION("A simple hello world driver");

static int __init hello_world_init(void)
{
    printk(KERN_INFO "Hello, world!\n");
    return 0;
}

static void __exit hello_world_exit(void)
{
    printk(KERN_INFO "Goodbye, kruel world..\n");
    printk(KERN_INFO "\n Get it? kruel as in k for kernel...? It's fine.\n");
}
 
module_init(hello_world_init);
module_exit(hello_world_exit);
 
