#include <linux/module.h> 
#include <linux/kernel.h> 
#include <linux/init.h>   
#include <asm/msr.h>      
#include <linux/types.h>  


static u64 energy_status = 0;

static int __init energy_mon_init(void)
{
    rdmsrl(MSR_PKG_ENERGY_STATUS, energy_status);
    printk(KERN_INFO "EnergyMonitor: Initial MSR reading (0x%lx) = %llu\n", 
           (unsigned long)MSR_PKG_ENERGY_STATUS, energy_status);
           
    printk(KERN_INFO "EnergyMonitor: Module Loaded successfully.\n");

    return 0;
}
static void __exit energy_mon_exit(void)
{
    rdmsrl(MSR_PKG_ENERGY_STATUS, energy_status);

    printk(KERN_INFO "EnergyMonitor: Final MSR reading = %llu\n", energy_status);
    printk(KERN_INFO "EnergyMonitor: Module Unloaded.\n");
}

// =================================================================
// 4. MODULE METADATA 
// =================================================================
module_init(energy_mon_init);
module_exit(energy_mon_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Maithili wagh");
MODULE_DESCRIPTION("A RAPL energy monitor for AI workloads.");