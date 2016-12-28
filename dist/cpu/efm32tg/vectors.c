/*
 * Copyright (C) 2015-2016 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     cpu_efm32tg
 * @{
 *
 * @file
 * @brief       Startup code and interrupt vector definition
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 * @author      Bas Stottelaar <basstottelaar@gmail.com>
 *
 * @}
 */

#include <stdint.h>
#include "vectors_cortexm.h"

/* get the start of the ISR stack as defined in the linkerscript */
extern uint32_t _estack;

/* define a local dummy handler as it needs to be in the same compilation unit
 * as the alias definition */
void dummy_handler(void) {
    dummy_handler_default();
}

/* Cortex-M3 common interrupt vectors */
WEAK_DEFAULT void isr_svc(void);
WEAK_DEFAULT void isr_pendsv(void);
WEAK_DEFAULT void isr_systick(void);

/* Silicon Labs specific interrupt vector */
WEAK_DEFAULT void isr_dma(void);
WEAK_DEFAULT void isr_gpio_even(void);
WEAK_DEFAULT void isr_timer0(void);
WEAK_DEFAULT void isr_usart0_rx(void);
WEAK_DEFAULT void isr_usart0_tx(void);
WEAK_DEFAULT void isr_acmp0(void);
WEAK_DEFAULT void isr_adc0(void);
WEAK_DEFAULT void isr_dac0(void);
WEAK_DEFAULT void isr_i2c0(void);
WEAK_DEFAULT void isr_gpio_odd(void);
WEAK_DEFAULT void isr_timer1(void);
WEAK_DEFAULT void isr_usart1_rx(void);
WEAK_DEFAULT void isr_usart1_tx(void);
WEAK_DEFAULT void isr_lesense(void);
WEAK_DEFAULT void isr_leuart0(void);
WEAK_DEFAULT void isr_letimer0(void);
WEAK_DEFAULT void isr_pcnt0(void);
WEAK_DEFAULT void isr_rtc(void);
WEAK_DEFAULT void isr_cmu(void);
WEAK_DEFAULT void isr_vcmp(void);
WEAK_DEFAULT void isr_lcd(void);
WEAK_DEFAULT void isr_msc(void);
WEAK_DEFAULT void isr_aes(void);

/* interrupt vector table */
ISR_VECTORS const void *interrupt_vector[] = {
    /* Exception stack pointer */
    (void*) (&_estack),             /* pointer to the top of the stack */

    /* Cortex M3 handlers */
    (void*) reset_handler_default,  /* entry point of the program */
    (void*) nmi_default,            /* non maskable interrupt handler */
    (void*) hard_fault_default,     /* hard fault exception */
    (void*) mem_manage_default,     /* memory manage exception */
    (void*) bus_fault_default,      /* bus fault exception */
    (void*) usage_fault_default,    /* usage fault exception */

    (void*) (0UL),                  /* Reserved */
    (void*) (0UL),                  /* Reserved */
    (void*) (0UL),                  /* Reserved */
    (void*) (0UL),                  /* Reserved */
    (void*) isr_svc,                /* system call interrupt, in RIOT used for
                                     * switching into thread context on boot */
    (void*) debug_mon_default,      /* debug monitor exception */
    (void*) (0UL),                  /* Reserved */
    (void*) isr_pendsv,             /* pendSV interrupt, in RIOT the actual
                                     * context switching is happening here */
    (void*) isr_systick,            /* SysTick interrupt, not used in RIOT */

    /* EFM32 specific peripheral handlers */
    (void*) isr_dma,                /* 0 - DMA */
    (void*) isr_gpio_even,          /* 1 - GPIO_EVEN */
    (void*) isr_timer0,             /* 2 - TIMER0 */
    (void*) isr_usart0_rx,          /* 3 - USART0_RX */
    (void*) isr_usart0_tx,          /* 4 - USART0_TX */
    (void*) isr_acmp0,              /* 5 - ACMP0 */
    (void*) isr_adc0,               /* 6 - ADC0 */
    (void*) isr_dac0,               /* 7 - DAC0 */
    (void*) isr_i2c0,               /* 8 - I2C0 */
    (void*) isr_gpio_odd,           /* 9 - GPIO_ODD */
    (void*) isr_timer1,             /* 10 - TIMER1 */
    (void*) isr_usart1_rx,          /* 11 - USART1_RX */
    (void*) isr_usart1_tx,          /* 12 - USART1_TX */
    (void*) isr_lesense,            /* 13 - LESENSE */
    (void*) isr_leuart0,            /* 14 - LEUART0 */
    (void*) isr_letimer0,           /* 15 - LETIMER0 */
    (void*) isr_pcnt0,              /* 16 - PCNT0 */
    (void*) isr_rtc,                /* 17 - RTC */
    (void*) isr_cmu,                /* 18 - CMU */
    (void*) isr_vcmp,               /* 19 - VCMP */
    (void*) isr_lcd,                /* 20 - LCD */
    (void*) isr_msc,                /* 21 - MSC */
    (void*) isr_aes,                /* 22 - AES */
};
