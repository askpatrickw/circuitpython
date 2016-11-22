#include "shared-bindings/microcontroller/Pin.h"

#include "samd21_pins.h"

#define SERCOM(p_sercom, p_pad, p_pinmux) \
{ \
  .sercom = p_sercom, \
  .pad = p_pad, \
  .pinmux = p_pinmux \
}

#define NO_SERCOM SERCOM(0, 0, 0)

#define TIMER(p_tc, p_tcc, p_channel, p_wave_output, p_pin, p_mux) \
{ \
  .tc = p_tc, \
  .tcc = p_tcc, \
  .channel = p_channel, \
  .wave_output = p_wave_output, \
  .pin = p_pin, \
  .mux = p_mux \
}

#define NO_TIMER TIMER(0, 0, 0, 0, 0, 0)

// This macro is used to simplify pin definition in boards/<board>/pins.c
#define PIN(p_name, p_has_adc, p_adc_input, p_primary_timer, \
            p_secondary_timer, p_primary_sercom, p_secondary_sercom) \
const mcu_pin_obj_t pin_## p_name = { \
    { &mcu_pin_type }, \
    .name = MP_QSTR_ ## p_name, \
    .pin = (PIN_## p_name), \
    .has_adc = p_has_adc, \
    .adc_input = p_adc_input, \
    .primary_timer = p_primary_timer, \
    .secondary_timer =  p_secondary_timer, \
    .sercom = {p_primary_sercom, p_secondary_sercom}, \
}

#define NO_ADC_INPUT (0)

// Pins in datasheet order.
#ifdef PIN_PA00
PIN(PA00, false, NO_ADC_INPUT, \
    TIMER(0, TCC2, 0, 0, PIN_PA00E_TCC2_WO0, MUX_PA00E_TCC2_WO0),
    NO_TIMER,
    SERCOM(SERCOM1, 0, PINMUX_PA00D_SERCOM1_PAD0),
    NO_SERCOM);
#endif
#ifdef PIN_PA01
PIN(PA01, false, NO_ADC_INPUT,
    TIMER(0, TCC2, 1, 1, PIN_PA01E_TCC2_WO1, MUX_PA01E_TCC2_WO1),
    NO_TIMER,
    SERCOM(SERCOM1, 1, PINMUX_PA01D_SERCOM1_PAD1),
    NO_SERCOM);
#endif
#ifdef PIN_PA02
PIN(PA02, true, ADC_POSITIVE_INPUT_PIN0,
    NO_TIMER,
    NO_TIMER,
    NO_SERCOM,
    NO_SERCOM);
#endif
#ifdef PIN_PA03
PIN(PA03, true, ADC_POSITIVE_INPUT_PIN1,
    NO_TIMER,
    NO_TIMER,
    NO_SERCOM,
    NO_SERCOM);
#endif
#ifdef PIN_PB04
PIN(PB04, true, ADC_POSITIVE_INPUT_PIN12,
    NO_TIMER,
    NO_TIMER,
    NO_SERCOM,
    NO_SERCOM);
#endif
#ifdef PIN_PB05
PIN(PB05, true, ADC_POSITIVE_INPUT_PIN13,
    NO_TIMER,
    NO_TIMER,
    NO_SERCOM,
    NO_SERCOM);
#endif
#ifdef PIN_PB06
PIN(PB06, true, ADC_POSITIVE_INPUT_PIN14,
    NO_TIMER,
    NO_TIMER,
    NO_SERCOM,
    NO_SERCOM);
#endif
#ifdef PIN_PB07
PIN(PB07, true, ADC_POSITIVE_INPUT_PIN15,
    NO_TIMER,
    NO_TIMER,
    NO_SERCOM,
    NO_SERCOM);
#endif
#ifdef PIN_PB08
PIN(PB08, true, ADC_POSITIVE_INPUT_PIN2,
    TIMER(TC4, 0, 0, 0, PIN_PB08E_TC4_WO0, MUX_PB08E_TC4_WO0),
    NO_TIMER,
    NO_SERCOM,
    SERCOM(SERCOM4, 0, PINMUX_PB08D_SERCOM4_PAD0));
#endif
#ifdef PIN_PB09
PIN(PB09, true, ADC_POSITIVE_INPUT_PIN3,
    TIMER(TC4, 0, 1, 1, PIN_PB09E_TC4_WO1, MUX_PB09E_TC4_WO1),
    NO_TIMER,
    NO_SERCOM,
    SERCOM(SERCOM4, 1, PINMUX_PB09D_SERCOM4_PAD1));
#endif
#ifdef PIN_PA04
PIN(PA04, true, ADC_POSITIVE_INPUT_PIN4,
    TIMER(0, TCC0, 0, 0, PIN_PA04E_TCC0_WO0, MUX_PA04E_TCC0_WO0),
    NO_TIMER,
    NO_SERCOM,
    SERCOM(SERCOM0, 0, PINMUX_PA04D_SERCOM0_PAD0));
#endif
#ifdef PIN_PA05
PIN(PA05, true, ADC_POSITIVE_INPUT_PIN5,
    TIMER(0, TCC0, 1, 1, PIN_PA05E_TCC0_WO1, MUX_PA05E_TCC0_WO1),
    NO_TIMER,
    NO_SERCOM,
    SERCOM(SERCOM0, 1, PINMUX_PA05D_SERCOM0_PAD1));
#endif
#ifdef PIN_PA06
PIN(PA06, true, ADC_POSITIVE_INPUT_PIN6,
    TIMER(0, TCC1, 0, 0, PIN_PA06E_TCC1_WO0, MUX_PA06E_TCC1_WO0),
    NO_TIMER,
    SERCOM(SERCOM0, 2, PINMUX_PA06D_SERCOM0_PAD2),
    NO_SERCOM);
#endif
#ifdef PIN_PA07
PIN(PA07, true, ADC_POSITIVE_INPUT_PIN7,
    TIMER(0, TCC1, 1, 1, PIN_PA07E_TCC1_WO1, MUX_PA07E_TCC1_WO1),
    NO_TIMER,
    SERCOM(SERCOM0, 3, PINMUX_PA07D_SERCOM0_PAD3),
    NO_SERCOM);
#endif
#ifdef PIN_PA08
PIN(PA08, true, ADC_POSITIVE_INPUT_PIN17,
    TIMER(0, TCC0, 0, 0, PIN_PA08E_TCC0_WO0, MUX_PA08E_TCC0_WO0),
    TIMER(0, TCC1, 2, 2, PIN_PA08F_TCC1_WO2, MUX_PA08F_TCC1_WO2),
    SERCOM(SERCOM0, 0, PINMUX_PA08C_SERCOM0_PAD0),
    SERCOM(SERCOM2, 0, PINMUX_PA08D_SERCOM2_PAD0));
#endif
#ifdef PIN_PA09
PIN(PA09, true, ADC_POSITIVE_INPUT_PIN17,
    TIMER(0, TCC0, 1, 1, PIN_PA09E_TCC0_WO1, MUX_PA09E_TCC0_WO1),
    TIMER(0, TCC1, 3, 3, PIN_PA09F_TCC1_WO3, MUX_PA09F_TCC1_WO3),
    SERCOM(SERCOM0, 1, PINMUX_PA09C_SERCOM0_PAD1),
    SERCOM(SERCOM2, 1, PINMUX_PA09D_SERCOM2_PAD1));
#endif
#ifdef PIN_PA10
PIN(PA10, true, ADC_POSITIVE_INPUT_PIN18,
    TIMER(0, TCC1, 0, 0, PIN_PA10E_TCC1_WO0, MUX_PA10E_TCC1_WO0),
    TIMER(0, TCC0, 2, 2, PIN_PA10F_TCC0_WO2, MUX_PA10F_TCC0_WO2),
    SERCOM(SERCOM0, 2, PINMUX_PA10C_SERCOM0_PAD2),
    SERCOM(SERCOM2, 2, PINMUX_PA10D_SERCOM2_PAD2));
#endif
#ifdef PIN_PA11
PIN(PA11, true, ADC_POSITIVE_INPUT_PIN19,
    TIMER(0, TCC1, 1, 1, PIN_PA11E_TCC1_WO1, MUX_PA11E_TCC1_WO1),
    TIMER(0, TCC0, 3, 3, PIN_PA11F_TCC0_WO3, MUX_PA11F_TCC0_WO3),
    SERCOM(SERCOM0, 3, PINMUX_PA11C_SERCOM0_PAD3),
    SERCOM(SERCOM2, 3, PINMUX_PA11D_SERCOM2_PAD3));
#endif
#ifdef PIN_PB10
PIN(PB10, false, NO_ADC_INPUT,
    TIMER(TC5, 0, 0, 0, PIN_PB10E_TC5_WO0, MUX_PB10E_TC5_WO0),
    TIMER(0, TCC0, 0, 4, PIN_PB10F_TCC0_WO4, MUX_PB10F_TCC0_WO4),
    NO_SERCOM,
    SERCOM(SERCOM4, 2, PINMUX_PB10D_SERCOM4_PAD2));
#endif
#ifdef PIN_PB11
PIN(PB11, false, NO_ADC_INPUT,
    TIMER(TC5, 0, 1, 1, PIN_PB11E_TC5_WO1, MUX_PB11E_TC5_WO1),
    TIMER(0, TCC0, 1, 5, PIN_PB11F_TCC0_WO5, MUX_PB11F_TCC0_WO5),
    NO_SERCOM,
    SERCOM(SERCOM4, 3, PINMUX_PB11D_SERCOM4_PAD3));
#endif
#ifdef PIN_PB12
PIN(PB12, false, NO_ADC_INPUT,
    TIMER(TC4, 0, 0, 0, PIN_PB12E_TC4_WO0, MUX_PB12E_TC4_WO0),
    TIMER(0, TCC0, 2, 6, PIN_PB12F_TCC0_WO6, MUX_PB12F_TCC0_WO6),
    SERCOM(SERCOM4, 0, PINMUX_PB12C_SERCOM4_PAD0),
    NO_SERCOM);
#endif
#ifdef PIN_PB13
PIN(PB13, false, NO_ADC_INPUT,
    TIMER(TC4, 0, 1, 1, PIN_PB13E_TC4_WO1, MUX_PB13E_TC4_WO1),
    TIMER(0, TCC0, 3, 7, PIN_PB13F_TCC0_WO7, MUX_PB13F_TCC0_WO7),
    SERCOM(SERCOM4, 1, PINMUX_PB13C_SERCOM4_PAD1),
    NO_SERCOM);
#endif
#ifdef PIN_PB14
PIN(PB14, false, NO_ADC_INPUT,
    TIMER(TC5, 0, 0, 0, PIN_PB14E_TC5_WO0, MUX_PB14E_TC5_WO0),
    NO_TIMER,
    SERCOM(SERCOM4, 2, PINMUX_PB14C_SERCOM4_PAD2),
    NO_SERCOM);
#endif

// Second page.
#ifdef PIN_PB15
PIN(PB15, false, NO_ADC_INPUT,
    TIMER(TC5, 0, 1, 1, PIN_PB15E_TC5_WO1, MUX_PB15E_TC5_WO1),
    NO_TIMER,
    SERCOM(SERCOM4, 3, PINMUX_PB15C_SERCOM4_PAD3),
    NO_SERCOM);
#endif
#ifdef PIN_PA12
PIN(PA12, false, NO_ADC_INPUT,
    TIMER(0, TCC2, 0, 0, PIN_PA12E_TCC2_WO0, MUX_PA12E_TCC2_WO0),
    TIMER(0, TCC0, 2, 6, PIN_PA12F_TCC0_WO6, MUX_PA12F_TCC0_WO6),
    SERCOM(SERCOM2, 0, PINMUX_PA12C_SERCOM2_PAD0),
    SERCOM(SERCOM4, 0, PINMUX_PA12D_SERCOM4_PAD0));
#endif
#ifdef PIN_PA13
PIN(PA13, false, NO_ADC_INPUT,
    TIMER(0, TCC2, 1, 1, PIN_PA13E_TCC2_WO1, MUX_PA13E_TCC2_WO1),
    TIMER(0, TCC0, 3, 7, PIN_PA13F_TCC0_WO7, MUX_PA13F_TCC0_WO7),
    SERCOM(SERCOM2, 1, PINMUX_PA13C_SERCOM2_PAD1),
    SERCOM(SERCOM4, 1, PINMUX_PA13D_SERCOM4_PAD1));
#endif
#ifdef PIN_PA14
PIN(PA14, false, NO_ADC_INPUT,
    TIMER(TC3, 0, 0, 0, PIN_PA14E_TC3_WO0, MUX_PA14E_TC3_WO0),
    TIMER(0, TCC0, 0, 4, PIN_PA14F_TCC0_WO4, MUX_PA14F_TCC0_WO4),
    SERCOM(SERCOM2, 2, PINMUX_PA14C_SERCOM2_PAD2),
    #ifdef SERCOM4
    SERCOM(SERCOM4, 2, PINMUX_PA14D_SERCOM4_PAD2)
    #else
    NO_SERCOM
    #endif
    );
#endif
#ifdef PIN_PA15
PIN(PA15, false, NO_ADC_INPUT,
    TIMER(TC3, 0, 1, 1, PIN_PA15E_TC3_WO1, MUX_PA15E_TC3_WO1),
    TIMER(0, TCC0, 1, 5, PIN_PA15F_TCC0_WO5, MUX_PA15F_TCC0_WO5),
    SERCOM(SERCOM2, 3, PINMUX_PA15C_SERCOM2_PAD3),
    #ifdef SERCOM4
    SERCOM(SERCOM4, 3, PINMUX_PA15D_SERCOM4_PAD3)
    #else
    NO_SERCOM
    #endif
    );
#endif
#ifdef PIN_PA16
PIN(PA16, false, NO_ADC_INPUT,
    TIMER(0, TCC2, 0, 0, PIN_PA16E_TCC2_WO0, MUX_PA16E_TCC2_WO0),
    TIMER(0, TCC0, 2, 6, PIN_PA16F_TCC0_WO6, MUX_PA16F_TCC0_WO6),
    SERCOM(SERCOM1, 0, PINMUX_PA16C_SERCOM1_PAD0),
    SERCOM(SERCOM3, 0, PINMUX_PA16D_SERCOM3_PAD0));
#endif
#ifdef PIN_PA17
PIN(PA17, false, NO_ADC_INPUT,
  TIMER(0, TCC2, 1, 1, PIN_PA17E_TCC2_WO1, MUX_PA17E_TCC2_WO1),
  TIMER(0, TCC0, 3, 7, PIN_PA17F_TCC0_WO7, MUX_PA17F_TCC0_WO7),
  SERCOM(SERCOM1, 1, PINMUX_PA17C_SERCOM1_PAD1),
  SERCOM(SERCOM3, 1, PINMUX_PA17D_SERCOM3_PAD1));
#endif
#ifdef PIN_PA18
PIN(PA18, false, NO_ADC_INPUT,
  TIMER(TC3, 0, 0, 0, PIN_PA18E_TC3_WO0, MUX_PA18E_TC3_WO0),
  TIMER(0, TCC0, 2, 2, PIN_PA18F_TCC0_WO2, MUX_PA18F_TCC0_WO2),
  SERCOM(SERCOM1, 2, PINMUX_PA18C_SERCOM1_PAD2),
  SERCOM(SERCOM3, 2, PINMUX_PA18D_SERCOM3_PAD2));
#endif
#ifdef PIN_PA19
PIN(PA19, false, NO_ADC_INPUT,
  TIMER(TC3, 0, 1, 1, PIN_PA19E_TC3_WO1, MUX_PA19E_TC3_WO1),
  TIMER(0, TCC0, 3, 3, PIN_PA19F_TCC0_WO3, MUX_PA19F_TCC0_WO3),
  SERCOM(SERCOM1, 3, PINMUX_PA19C_SERCOM1_PAD3),
  SERCOM(SERCOM3, 3, PINMUX_PA19C_SERCOM1_PAD3));
#endif
#ifdef PIN_PB16
PIN(PB16, false, NO_ADC_INPUT,
    #ifdef _SAMD21_TC6_INSTANCE_
    TIMER(TC6, 0, 0, 0, PIN_PB16E_TC6_WO0, MUX_PB16E_TC6_WO0),
    #else
    NO_TIMER,
    #endif
    TIMER(0, TCC0, 0, 4, PIN_PB16F_TCC0_WO4, MUX_PB16F_TCC0_WO4),
    SERCOM(SERCOM5, 0, PINMUX_PB16C_SERCOM5_PAD0),
    NO_SERCOM);
#endif
#ifdef PIN_PB17
PIN(PB17, false, NO_ADC_INPUT,
    #ifdef _SAMD21_TC6_INSTANCE_
    TIMER(TC6, 0, 0, 0, PIN_PB17E_TC6_WO1, MUX_PB17E_TC6_WO1),
    #else
    NO_TIMER,
    #endif
    TIMER(0, TCC0, 1, 5, PIN_PB17F_TCC0_WO5, MUX_PB17F_TCC0_WO5),
    SERCOM(SERCOM5, 1, PINMUX_PB17C_SERCOM5_PAD1),
    NO_SERCOM);
#endif
#ifdef PIN_PA20
PIN(PA20, false, NO_ADC_INPUT,
    #ifdef _SAMD21_TC7_INSTANCE_
    TIMER(TC7, 0, 0, 0, PIN_PA20E_TC7_WO0, MUX_PA20E_TC7_WO0),
    #else
    NO_TIMER,
    #endif
    TIMER(0, TCC0, 2, 6, PIN_PA20F_TCC0_WO6, MUX_PA20F_TCC0_WO6),
    SERCOM(SERCOM5, 2, PINMUX_PA20C_SERCOM5_PAD2),
    SERCOM(SERCOM3, 2, PINMUX_PA20D_SERCOM3_PAD2));
#endif
#ifdef PIN_PA21
PIN(PA21, false, NO_ADC_INPUT,
    #ifdef _SAMD21_TC7_INSTANCE_
    TIMER(TC7, 0, 1, 1, PIN_PA21E_TC7_WO1, MUX_PA21E_TC7_WO1),
    #else
    NO_TIMER,
    #endif
    TIMER(0, TCC0, 3, 7, PIN_PA21F_TCC0_WO7, MUX_PA21F_TCC0_WO7),
    SERCOM(SERCOM5, 3, PINMUX_PA21C_SERCOM5_PAD3),
    SERCOM(SERCOM3, 3, PINMUX_PA21D_SERCOM3_PAD3));
#endif
#ifdef PIN_PA22
PIN(PA22, false, NO_ADC_INPUT,
    TIMER(TC4, 0, 0, 0, PIN_PA22E_TC4_WO0, MUX_PA22E_TC4_WO0),
    TIMER(0, TCC0, 0, 4, PIN_PA22F_TCC0_WO4, MUX_PA22F_TCC0_WO4),
    SERCOM(SERCOM3, 0, PINMUX_PA22C_SERCOM3_PAD0),
    #ifdef SERCOM5
    SERCOM(SERCOM5, 0, PINMUX_PA22D_SERCOM5_PAD0)
    #else
    NO_SERCOM
    #endif
    );
#endif
#ifdef PIN_PA23
PIN(PA23, false, NO_ADC_INPUT,
    TIMER(TC4, 0, 1, 1, PIN_PA23E_TC4_WO1, MUX_PA23E_TC4_WO1),
    TIMER(0, TCC0, 1, 5, PIN_PA23F_TCC0_WO5, MUX_PA23F_TCC0_WO5),
    SERCOM(SERCOM3, 1, PINMUX_PA23C_SERCOM3_PAD1),
    #ifdef SERCOM5
    SERCOM(SERCOM5, 1, PINMUX_PA23D_SERCOM5_PAD1)
    #else
    NO_SERCOM
    #endif
    );
#endif
#ifdef PIN_PA24
PIN(PA24, false, NO_ADC_INPUT,
    TIMER(TC5, 0, 0, 0, PIN_PA24E_TC5_WO0, MUX_PA24E_TC5_WO0),
    TIMER(0, TCC0, 2, 2, PIN_PA24F_TCC1_WO2, MUX_PA24F_TCC1_WO2),
    SERCOM(SERCOM3, 2, PINMUX_PA24C_SERCOM3_PAD2),
    #ifdef SERCOM5
    SERCOM(SERCOM5, 2, PINMUX_PA24D_SERCOM5_PAD2)
    #else
    NO_SERCOM
    #endif
    );
#endif
#ifdef PIN_PA25
PIN(PA25, false, NO_ADC_INPUT,
    TIMER(TC5, 0, 1, 1, PIN_PA25E_TC5_WO1, MUX_PA25E_TC5_WO1),
    TIMER(0, TCC1, 3, 3, PIN_PA25F_TCC1_WO3, MUX_PA25F_TCC1_WO3),
    SERCOM(SERCOM3, 3, PINMUX_PA25C_SERCOM3_PAD3),
    #ifdef SERCOM5
    SERCOM(SERCOM5, 3, PINMUX_PA25C_SERCOM3_PAD3)
    #else
    NO_SERCOM
    #endif
    );
#endif
#ifdef PIN_PB22
PIN(PB22, false, NO_ADC_INPUT,
    #ifdef _SAMD21_TC7_INSTANCE_
    TIMER(TC7, 0, 1, 1, PIN_PB22E_TC7_WO0, MUX_PB22E_TC7_WO0),
    #else
    NO_TIMER,
    #endif
    NO_TIMER,
    NO_SERCOM,
    SERCOM(SERCOM5, 2, PINMUX_PB22D_SERCOM5_PAD2));
#endif
#ifdef PIN_PB23
PIN(PB23, false, NO_ADC_INPUT,
    #ifdef _SAMD21_TC7_INSTANCE_
    TIMER(TC7, 0, 1, 1, PIN_PB23E_TC7_WO1, MUX_PB23E_TC7_WO1),
    #else
    NO_TIMER,
    #endif
    NO_TIMER,
    NO_SERCOM,
    SERCOM(SERCOM5, 3, PINMUX_PB23D_SERCOM5_PAD3));
#endif
#ifdef PIN_PA27
PIN(PA27, false, NO_ADC_INPUT,
    NO_TIMER,
    NO_TIMER,
    NO_SERCOM,
    NO_SERCOM);
#endif
#ifdef PIN_PA28
PIN(PA28, false, NO_ADC_INPUT,
    NO_TIMER,
    NO_TIMER,
    NO_SERCOM,
    NO_SERCOM);
#endif
#ifdef PIN_PA30
PIN(PA30, false, NO_ADC_INPUT,
    TIMER(0, TCC1, 0, 0, PIN_PA30E_TCC1_WO0, MUX_PA30E_TCC1_WO0),
    NO_TIMER,
    NO_SERCOM,
    SERCOM(SERCOM1, 2, PINMUX_PA30D_SERCOM1_PAD2));
#endif
#ifdef PIN_PA31
PIN(PA31, false, NO_ADC_INPUT,
    TIMER(0, TCC1, 1, 1, PIN_PA31E_TCC1_WO1, MUX_PA31E_TCC1_WO1),
    NO_TIMER,
    NO_SERCOM,
    SERCOM(SERCOM1, 3, PINMUX_PA31D_SERCOM1_PAD3));
#endif
#ifdef PIN_PB30
PIN(PB30, false, NO_ADC_INPUT,
    TIMER(TCC0, 0, 0, 0, PIN_PB30E_TCC0_WO0, MUX_PB30E_TCC0_WO0),
    TIMER(TCC1, 0, 2, 2, PIN_PB30F_TCC1_WO2, MUX_PB30F_TCC1_WO2),
    NO_SERCOM,
    SERCOM(SERCOM5, 0, PINMUX_PB30D_SERCOM5_PAD0));
#endif
#ifdef PIN_PB31
PIN(PB31, false, NO_ADC_INPUT,
    TIMER(TCC0, 0, 1, 1, PIN_PB31E_TCC0_WO1, MUX_PB31E_TCC0_WO1),
    TIMER(TCC1, 0, 3, 3, PIN_PB31F_TCC1_WO3, MUX_PB31F_TCC1_WO3),
    NO_SERCOM,
    SERCOM(SERCOM5, 1, PINMUX_PB31D_SERCOM5_PAD1));
#endif
#ifdef PIN_PB00
PIN(PB00, true, ADC_POSITIVE_INPUT_PIN8,
    #ifdef _SAMD21_TC7_INSTANCE_
    TIMER(TC7, 0, 0, 0, PIN_PB00E_TC7_WO0, MUX_PB00E_TC7_WO0),
    #else
    NO_TIMER,
    #endif
    NO_TIMER,
    NO_SERCOM,
    SERCOM(SERCOM5, 2, PINMUX_PB00D_SERCOM5_PAD2));
#endif
#ifdef PIN_PB01
PIN(PB01, true, ADC_POSITIVE_INPUT_PIN9,
    #ifdef _SAMD21_TC7_INSTANCE_
    TIMER(TC7, 0, 1, 1, PIN_PB01E_TC7_WO1, MUX_PB01E_TC7_WO1),
    #else
    NO_TIMER,
    #endif
    NO_TIMER,
    NO_SERCOM,
    SERCOM(SERCOM5, 3, PINMUX_PB01D_SERCOM5_PAD3));
#endif
#ifdef PIN_PB02
PIN(PB02, true, ADC_POSITIVE_INPUT_PIN10,
    #ifdef _SAMD21_TC6_INSTANCE_
    TIMER(TC6, 0, 0, 0, PIN_PB02E_TC6_WO0, MUX_PB02E_TC6_WO0),
    #else
    NO_TIMER,
    #endif
    NO_TIMER,
    NO_SERCOM,
    SERCOM(SERCOM5, 0, PINMUX_PB02D_SERCOM5_PAD0));
#endif
#ifdef PIN_PB03
PIN(PB03, true, ADC_POSITIVE_INPUT_PIN11,
    #ifdef _SAMD21_TC6_INSTANCE_
    TIMER(TC6, 0, 1, 1, PIN_PB03E_TC6_WO1, MUX_PB03E_TC6_WO1),
    #else
    NO_TIMER,
    #endif
    NO_TIMER,
    NO_SERCOM,
    SERCOM(SERCOM5, 1, PINMUX_PB03D_SERCOM5_PAD1));
#endif
