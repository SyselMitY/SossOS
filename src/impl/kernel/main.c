#include "print.h"
#include "interrupt.h"

void kernel_main() {
    print_clear();
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    idt_init();
    print_str("Huhu Made Stiefsohn Peppi wau i kau fü schreim :D");
}