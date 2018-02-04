#include "plaidconfig.h"
#include "uart.h"

void __attribute__((interrupt("SWI"))) software_interrupt_vector(void) {
    while(1) {
        /* Do Nothing! */
    }
}

void __attribute__((interrupt("IRQ"))) interrupt_vector(void) {
    while(1) {
        /* Do Nothing! */
    }
}

void __attribute__((interrupt("FIQ"))) fast_interrupt_vector(void) {
    while(1) {
        /* Do Nothing! */
    }
}

void __attribute__((interrupt("UNDEF"))) undefined_instruction_vector(void) {
    while(1) {
        /* Do Nothing! */
    }
}

void __attribute__((interrupt("ABORT"))) prefetch_abort_vector(void) {
    while(1) {
        /* Do Nothing! */
    }
}

void __attribute__((interrupt("ABORT"))) data_abort_vector(void) {
    while(1) {
        /* Do Nothing! */
    }
}

void kernel_main(unsigned int r0, unsigned int r1, unsigned int atags) {
    uart_init(115200, 8);

    uart_write('H');
    uart_write('e');
    uart_write('l');
    uart_write('l');
    uart_write('o');
    uart_write('\r');
    uart_write('\n');

    while(1) {
        /* Do Nothing! */
    }
}