#include <zephyr/init.h>
#include <zephyr/sys/printk.h>

static int board_my_board_init(void)
{
    printk("Initializing my_board\n");
    return 0;
}
SYS_INIT(board_my_board_init,
         PRE_KERNEL_1,
         CONFIG_KERNEL_INIT_PRIORITY_DEFAULT);
