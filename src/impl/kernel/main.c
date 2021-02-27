#include "print.h"
#include "interrupt.h"

void kernel_main() {
    idt_init();
    print_clear();
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str("Huhu Made Stiefsohn Peppi wau i kau fü schreim :D");
}