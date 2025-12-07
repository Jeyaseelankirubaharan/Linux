#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL"); // Specifies the license of the module
MODULE_AUTHOR("Jeyaseelan"); // Specifies the author of the module
MODULE_DESCRIPTION("A simple Hello World kernel module."); // Provides a brief description

static int __init my_kernel_init(void)
{
	printk (KERN_INFO "Jeyaseelan - Hello World  module initialized");
	return 0;
}

static void __exit  my_kernel_exit(void)
{
	printk (KERN_INFO "Jeyaseelan - Hello World  module exited");
}

module_init(my_kernel_init); 
module_exit(my_kernel_exit);
