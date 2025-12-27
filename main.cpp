// =============================================================================
// Project:         FunSAPE test project
// File:            main.cpp
// Author:          Leandro Schwarz
// Created:         2024-10-03
// Modified:        2024-10-03
// Version:         1.0
// Notes:           This project is used to test the FunSAPE AVR Library
//                      features.
// =============================================================================

// =============================================================================
// Precompiler constant defintions
// =============================================================================

#define F_CPU 16000000UL

// =============================================================================
// Dependencies
// =============================================================================

// #include "funsape/globalDefines.hpp"
// #include "funsape/peripheral/usart0.hpp"
// #include "funsape/util/circularBuffer.hpp"
// #include "funsape/util/parserApi.hpp"
// #include "funsape/peripheral/twi.hpp"
// #include "funsape/peripheral/timer0.hpp"
// #include <avr/pgmspace.h>

#include <avr/io.h>

// =============================================================================
// Constant definitions
// =============================================================================

// NONE

// =============================================================================
// New data types
// =============================================================================

// NONE

// =============================================================================
// Static function declarations
// =============================================================================

// NONE

// =============================================================================
// Global variables
// =============================================================================

// CircularBuffer<uint8_t, 20> usartRxCircBuffer;
// ParserApi parserApi;

// =============================================================================
// Main function
// =============================================================================

// const char usartOkString[] PROGMEM = "USART OK! %04X\r";
// volatile uint8_t couner = 0;

// timer0OverflowCallback()
// {
//     cplBit(PORTC, PC2);
// }

int main()
{
    DDRC = 0xFF;
    // timer0.init(Timer0::Mode::NORMAL, Timer0::ClockSource::PRESCALER_1024);
    // timer0.activateOverflowInterrupt();
    // Local variables
    // uint8_t auxFrameId                  = 0;
    // uint8_t auxFrameSourAddress         = 0;
    // uint8_t auxFrameDestAddress         = 0;
    // uint8_t auxFramePayloadLength       = 0;
    // uint8_t auxFramePayloadData[20];

    // USART0 configuration
    // usart0.enableReceiver();
    // usart0.enableTransmitter();
    // usart0.activateReceptionCompleteInterrupt();
    // usart0.init();
    // usart0.stdio();

    // twi.init();
    // printf_P(PSTR("USART OK! %04X\r"), 0x2205);

    // Parser API configuration
    // if(!parserApi.init(&usartRxCircBuffer, 20)) {
    //     // printf_P(PSTR("init() error: %04X!\r"), (uint16_t)parserApi.getLastError());
    //     systemHalt();
    // }

    // Enables global interrupts
    // sei();

    // uint8_t auxBuff[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // twi.setDevice(0x77);
    // twi.writeReg(90, auxBuff, 10);

    while(1) {
        // if(parserApi.isFrameReady()) {
        //     if(!parserApi.getFrameData(
        //                     &auxFrameId,
        //                     &auxFrameSourAddress,
        //                     &auxFrameDestAddress,
        //                     &auxFramePayloadLength,
        //                     auxFramePayloadData,
        //                     50
        //             )) {
        //         // printf_P(PSTR("getFrameData() error: %04X!\r"), (uint16_t)parserApi.getLastError());
        //         systemHalt();
        //     }
        //     // printf_P(PSTR("\r\r"));
        //     // printf_P(PSTR("ID: %02X\r"), auxFrameId);
        //     // printf_P(PSTR("SA: %02X\r"), auxFrameSourAddress);
        //     // printf_P(PSTR("DA: %02X\r"), auxFrameDestAddress);
        //     // printf_P(PSTR("PL: %02X\r"), auxFramePayloadLength);
        //     // printf_P(PSTR("PD: "));
        //     for(uint8_t i = 0; i < auxFramePayloadLength; i++) {
        //         // printf_P(PSTR("%02X "), auxFramePayloadData[i]);
        //     }
        //     // printf_P(PSTR("\r\r"));
        // } else {
        //     if(!parserApi.processFrame()) {
        //         // printf_P(PSTR("processFrame() error: %04X!\r"), (uint16_t)parserApi.getLastError());
        //         systemHalt();
        //     }
        // }
        // delayMs(1000);
        // parserApi.printDebug();
    }

    return 0;
}

// Com              Sem                 BC
// 11060            10202
// 964              973

// =============================================================================
// Static function definitions
// =============================================================================

// NONE

// =============================================================================
// Interrupt callback functions definitions
// =============================================================================

// void usart0ReceptionCompleteCallback()
// {
//     // usartRxCircBuffer.push(UDR0);
// }
