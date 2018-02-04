#ifndef __SOC_H
#define __SOC_H

#include <stdint.h>

#ifdef RPI2
    #define PERIPHERAL_BASE     0x3F000000UL
#else
    #define PERIPHERAL_BASE     0x20000000UL
#endif

#define AUX_BASE    (PERIPHERAL_BASE + 0x215000)

#define AUX_ENA_MINIUART            (1 << 0)
#define AUX_ENA_SPI1                (1 << 1)
#define AUX_ENA_SPI2                (1 << 2)

#define AUX_IRQ_SPI2                (1 << 2)
#define AUX_IRQ_SPI1                (1 << 1)
#define AUX_IRQ_MU                  (1 << 0)

#define AUX_MULCR_8BIT_MODE         (3 << 0)  /* See errata for this value */
#define AUX_MULCR_BREAK             (1 << 6)
#define AUX_MULCR_DLAB_ACCESS       (1 << 7)

#define AUX_MUMCR_RTS               (1 << 1)

#define AUX_MULSR_DATA_READY        (1 << 0)
#define AUX_MULSR_RX_OVERRUN        (1 << 1)
#define AUX_MULSR_TX_EMPTY          (1 << 5)
#define AUX_MULSR_TX_IDLE           (1 << 6)

#define AUX_MUMSR_CTS               (1 << 5)

#define AUX_MUCNTL_RX_ENABLE        (1 << 0)
#define AUX_MUCNTL_TX_ENABLE        (1 << 1)
#define AUX_MUCNTL_RTS_FLOW         (1 << 2)
#define AUX_MUCNTL_CTS_FLOW         (1 << 3)
#define AUX_MUCNTL_RTS_FIFO         (3 << 4)
#define AUX_MUCNTL_RTS_ASSERT       (1 << 6)
#define AUX_MUCNTL_CTS_ASSERT       (1 << 7)

#define AUX_MUSTAT_SYMBOL_AV        (1 << 0)
#define AUX_MUSTAT_SPACE_AV         (1 << 1)
#define AUX_MUSTAT_RX_IDLE          (1 << 2)
#define AUX_MUSTAT_TX_IDLE          (1 << 3)
#define AUX_MUSTAT_RX_OVERRUN       (1 << 4)
#define AUX_MUSTAT_TX_FIFO_FULL     (1 << 5)
#define AUX_MUSTAT_RTS              (1 << 6)
#define AUX_MUSTAT_CTS              (1 << 7)
#define AUX_MUSTAT_TX_EMPTY         (1 << 8)
#define AUX_MUSTAT_TX_DONE          (1 << 9)
#define AUX_MUSTAT_RX_FIFO_LEVEL    (7 << 16)
#define AUX_MUSTAT_TX_FIFO_LEVEL    (7 << 24)

typedef struct {
    volatile unsigned int IRQ;
    volatile unsigned int ENABLES;

    volatile unsigned int reserved1[((0x40 - 0x04) / 4) - 1];

    volatile unsigned int MU_IO;
    volatile unsigned int MU_IER;
    volatile unsigned int MU_IIR;
    volatile unsigned int MU_LCR;
    volatile unsigned int MU_MCR;
    volatile unsigned int MU_LSR;
    volatile unsigned int MU_MSR;
    volatile unsigned int MU_SCRATCH;
    volatile unsigned int MU_CNTL;
    volatile unsigned int MU_STAT;
    volatile unsigned int MU_BAUD;

    volatile unsigned int reserved2[(0x80 - 0x68) / 4];

    volatile unsigned int SPI0_CNTL0;
    volatile unsigned int SPI0_CNTL1;
    volatile unsigned int SPI0_STAT;
    volatile unsigned int SPI0_IO;
    volatile unsigned int SPI0_PEEK;

    volatile unsigned int reserved3[(0xC0 - 0x94) / 4];

    volatile unsigned int SPI1_CNTL0;
    volatile unsigned int SPI1_CNTL1;
    volatile unsigned int SPI1_STAT;
    volatile unsigned int SPI1_IO;
    volatile unsigned int SPI1_PEEK;
} aux_t;

typedef volatile uint32_t rpi_reg_rw_t;
typedef volatile const uint32_t rpi_reg_ro_t;
typedef volatile uint32_t rpi_reg_wo_t;

typedef volatile uint64_t rpi_wreg_rw_t;
typedef volatile const uint64_t rpi_wreg_ro_t;

#endif // __SOC_H