#include "print.h"
#include "interrupt.h"

void kernel_main() {
    print_clear();
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    idt_init();
    print_str("Huhu Made Stiefsohn Peppi wau i kau wos schreim :D");
    print_newline();
    print_str("Taste druecken fuer Keymap");
}