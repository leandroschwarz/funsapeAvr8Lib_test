/**
 *******************************************************************************
 * @file            globalDefines.hpp
 * @author          Leandro Schwarz (bladabuska+funsapeavr8lib@gmail.com)
 * @brief           Global definitions file.
 * @details         This file provides new data types, constants and other basic
 *                      elements that are usefull throughout all other modules
 *                      of the FunSAPE++ AVR8 Library.
 * @date            2025-08-08
 * @version         25.08
 * @copyright       MIT License
 * @note            No notes at this time.
 * @todo            No itens in todo list yet.
 * @bug             No bugs detected yet.
 *
 *******************************************************************************
 * @attention
 *
 * MIT License
 *
 * Copyright (c) 2025 Leandro Schwarz
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 *      of this software and associated documentation files (the "Software"), to
 *      deal in the Software without restriction, including without limitation
 *      the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *      and/or sell copies of the Software, and to permit persons to whom the
 *      Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 *      all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *      IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *      FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *      THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 *      OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 *      ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *      OTHER DEALINGS IN THE SOFTWARE.
 *
 *******************************************************************************
*/

// =============================================================================
// Include guard (START)
// =============================================================================

#ifndef __GLOBAL_DEFINES_HPP
#define __GLOBAL_DEFINES_HPP            2508

// =============================================================================
// Basic definitions
// =============================================================================

#ifndef F_CPU
#   define F_CPU    16000000UL
#endif

// =============================================================================
// Dependencies
// =============================================================================

//     //////////////////     LIBRARY DEPENDENCIES     //////////////////     //

#include "parts/mcuDevice.hpp"
#ifndef __MCU_DEVICE_HPP
#   error [funsapeLibGlobalDefines.hpp] Error 1 - Header file (mcuDevice.hpp) is missing or corrupted!
#elif __MCU_DEVICE_HPP != __GLOBAL_DEFINES_HPP
#   error [funsapeLibGlobalDefines.hpp] Error 2 - Build mismatch between file (mcuDevice.hpp) and global definitions file (globalDefines.hpp)!
#endif

//     //////////////////     AVR STANDARD LIBRARY     //////////////////     //

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <util/atomic.h>

//     ///////////////////     STANDARD C LIBRARY     ///////////////////     //

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

//     //////////////////     LIBRARY DEPENDENCIES     //////////////////     //

// NONE

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Doxygen: Start main group "Global_Definitions"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * @addtogroup      Global_Definitions
 * @brief           System global definitions.
 * @{
*/

// =============================================================================
// Undefining previous definitions
// =============================================================================

// NONE

// =============================================================================
// Constant definitions
// =============================================================================

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Doxygen: Start subgroup "Global_Definitions/Alias"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * @addtogroup      Alias
 * @brief           Alias definitions.
 * @{
*/

/**
 * @details         Alias to shorten unused attribute.
*/
#define ignored                         __attribute__((unused))
/**
 * @details         Alias to shorten inline attribute.
*/
#define inlined                         inline __attribute__((always_inline))
/**
 * @details         Alias to shorten weak attribute.
*/
#define weakened                        __attribute__((weak))

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Doxygen: End subgroup "Global_Definitions/Alias"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * @}
*/

// =============================================================================
// Macro functions
// =============================================================================

//     //////////////////////     DATA VALIDITY    //////////////////////     //

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Doxygen: Start subgroup "Global_Definitions/Data_Validity"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * @addtogroup      Data_Validity
 * @brief           Data validation macro-functions.
 * @{
*/

/**
 * @def             isGpioAddressValid(gpioPort)
 * @details         Checks if the given parameter @a gpioPort is a valid GPIO
 *                      port address. Valid GPIO addresses are @c DDRx, @c PORTx
 *                      and @c PINx register addresses.
 * @param[in]       gpioPort            GPIO port address
 * @retval          true                if GPIO address is valid
 * @retval          false               if GPIO address is not valid
*/
#define isGpioAddressValid(gpioPort)    (       \
        (IS_GPIO_ALL_INSTANCE(gpioPort))        \
        ? (bool_t)true                          \
        : (bool_t)false                         \
)

/**
 * @def             isGpioPinIndexValid(gpioPin)
 * @details         Checks if the given parameter @a gpioPin is a valid GPIO
 *                      pin index.
 * @param[in]       gpioPin             GPIO pin index
 * @retval          true                if GPIO pin index is valid
 * @retval          false               if GPIO pin index is not valid
*/
#define isGpioPinIndexValid(gpioPin)    (       \
        (IS_GPIO_ALL_PIN_NUMBER(gpioPin))       \
        ? (bool_t)true                          \
        : (bool_t)false                         \
)

/**
 * @def             isPointerValid(ptr)
 * @details         Checks if the given parameter @a ptr is a valid pointer
 *                      address.
 * @param[in]       ptr                 pointer address
 * @retval          true                if pointer address is valid
 * @retval          false               if pointer address is not valid
*/
#define isPointerValid(ptr)             (       \
        ((void *)(ptr))                         \
        ? (bool_t)true                          \
        : (bool_t)false                         \
)

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Doxygen: End subgroup "Global_Definitions/Data_Validity"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * @}
*/

//     //////////////////////     BIT HANDLING     //////////////////////     //

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Doxygen: Start subgroup "Global_Definitions/Bit_Handling"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * @addtogroup      Bit_Handling
 * @details         Performs bitwise operations in one bit of a variable or
 *                      register.
 * @{
*/

#ifndef clrBit
/**
 * @def             clrBit(reg, pos)
 * @details         Clears the bit at position @a pos of the register or
 *                      variable @a reg.
 * @param[in,out]   reg                 register or variable
 * @param[in]       pos                 position of the bit to be cleared
*/
#   define clrBit(reg, pos)             do{(reg) &= ~(1 << (pos));}while(0)
#endif

#ifndef cplBit
/**
 * @def             cplBit(reg, pos)
 * @details         Complements (invert) the bit at position @a pos of the
 *                      register or variable @a reg.
 * @param[in,out]   reg                 register or variable
 * @param[in]       pos                 position of the bit to be complemented
*/
#   define cplBit(reg, pos)             do{(reg) ^= (1 << (pos));}while(0)
#endif

#ifndef setBit
/**
 * @def             setBit(reg, pos)
 * @details         Sets the bit at position @a pos of the register or variable
 *                      @a reg.
 * @param[in,out]   reg                 register or variable
 * @param[in]       pos                 position of the bit to be set
*/
#   define setBit(reg, pos)             do{(reg) |= (1 << (pos));}while(0)
#endif

//     ///////////////////////     BIT TESTING    ///////////////////////     //

#ifndef isBitClr
/**
 * @def             isBitClr(reg, pos)
 * @details         Verifies if the bit at position @a pos at the register or
 *                      variable @a reg is cleared.
 * @param[in]       reg                 register or variable
 * @param[in]       pos                 position of the bit to be evaluated
 * @retval          true                if the bit is cleared
 * @retval          false               if the bit is set
*/
#   define isBitClr(reg, pos)           (!isBitSet(reg,pos))
#endif

#ifndef isBitSet
/**
 * @def             isBitSet(reg, pos)
 * @details         Verifies if the bit at position @a pos at the register or
 *                      variable @a reg is set.
 * @param[in]       reg                 register or variable
 * @param[in]       pos                 position of the bit to be evaluated
 * @retval          true                if the bit is set
 * @retval          false               if the bit is cleared
*/
#   define isBitSet(reg, pos)           (((reg) >> (pos)) & 1)
#endif

//     ///////////////////////     BIT LOOPING    ///////////////////////     //

#ifndef waitUntilBitIsClear
/**
 * @def             waitUntilBitIsClear(reg, pos)
 * @details         Blocks the code execution while the bit in position @a pos
 *                      in register or variable @a reg is set.
 * @param[in]       reg                 register or variable
 * @param[in]       pos                 position of the bit to be evaluated
*/
#   define waitUntilBitIsClear(reg, pos)        do{     \
        doNothing();                                    \
    }while(isBitSet((reg), (pos)))
#endif

#ifndef waitUntilBitIsSet
/**
 * @def             waitUntilBitIsSet(reg, pos)
 * @details         Blocks the code execution while the bit in position @a pos
 *                      in register or variable @a reg is cleared.
 * @param[in]       reg                 register or variable
 * @param[in]       pos                 position of the bit to be evaluated
*/
#   define waitUntilBitIsSet(reg, pos)  do{     \
        doNothing();                            \
    } while (isBitClr((reg), (pos)))
#endif

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Doxygen: End subgroup "Global_Definitions/Bit_Handling"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * @}
*/

//     ////////////////////     BIT MASK HANDLING    ////////////////////     //

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Doxygen: Start subgroup "Global_Definitions/Mask_Handling"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * @addtogroup      Mask_Handling
 * @details         Performs bitwise operations in a set of 'one' bits of a
 *                      variable or register.
 * @attention       The desired bits of the mask must be always marked as '1',
 *                      even when the mask is used in a clear operation.
 * @{
*/

#ifndef clrMask
/**
 * @def             clrMask(reg, mask)
 * @details         Clears the bits of the register or variable @a reg that are
 *                      set on the supplied mask @a mask.
 * @param[in,out]   reg                 register or variable
 * @param[in]       mask                one-mask of the bits to be cleared
*/
#   define clrMask(reg, mask)           do{(reg) &= ~(mask);}while(0)
#endif

#ifndef cplMask
/**
 * @def             cplMask(reg, mask)
 * @details         Complements (inverts) the bits of the register or variable
 *                      @a reg that are set on the supplied mask @a mask.
 * @param[in,out]   reg                 register or variable
 * @param[in]       mask                one-mask of the bits to be complemented
*/
#   define cplMask(reg, mask)                   do{(reg) ^= (mask);}while(0)
#endif

#ifndef setMask
/**
 * @def             setMask(reg, mask)
 * @details         Sets the bits of the register or variable @a reg that are
 *                      set on the supplied mask @a mask.
 * @param[in,out]   reg                 register or variable
 * @param[in]       mask                one-mask of the bits to be set
*/
#   define setMask(reg, mask)                   do{(reg) |= (mask);}while(0)
#endif

//     ////////////////     BIT MASK OFFSET HANDLING     ////////////////     //

#ifndef clrMaskOffset
/**
 * @def             clrMaskOffset(reg, mask, offset)
 * @details         Clears the bits of the register or variable @a reg that are
 *                      set on the supplied mask @a mask. The mask is first
 *                      left-shifted by the value given in @a offset.
 * @param[in,out]   reg                 register or variable
 * @param[in]       mask                one-mask of the bits to be cleared
 * @param[in]       offset              left-shift offset value
*/
#   define clrMaskOffset(reg, mask, offset)     do{(reg) &= ~((mask) << (offset));}while(0)
#endif

#ifndef cplMaskOffset
/**
 * @def             cplMaskOffset(reg, mask, offset)
 * @details         Complements (inverts) the bits of the register or variable
 *                      @a reg that are set on the supplied mask @a mask. The
 *                      mask is first left-shifted by the value given in
 *                      @a offset.
 * @param[in,out]   reg                 register or variable
 * @param[in]       mask                one-mask of the bits to be complemented
 * @param[in]       offset              left-shift offset value
*/
#   define cplMaskOffset(reg, mask, offset)     do{(reg) ^= ((mask) << (offset));}while(0)
#endif

#ifndef setMaskOffset
/**
 * @def             setMaskOffset(reg, mask, offset)
 * @details         Sets the bits of the register or variable @a reg that are
 *                      set on the supplied mask @a mask. The mask is first
 *                      left-shifted by the value given in @a offset.
 * @param[in,out]   reg                 register or variable
 * @param[in]       mask                one-mask of the bits to be set
 * @param[in]       offset              left-shift offset value
*/
#   define setMaskOffset(reg, mask, offset)     do{(reg) |= ((mask) << (offset));}while(0)
#endif

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Doxygen: End subgroup "Global_Definitions/Mask_Handling"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * @}
 */

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Doxygen: Start subgroup "Global_Definitions/Data_Handling"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * @addtogroup      Data_Handling
 * @details         Performs general data handling, shifting and swapping a
 *                      variable data.
 * @{
*/

//     /////////////     DATA MANIPULATION (8-BITS WIDE)    /////////////     //

/**
 * @def             byteGetNibble1(dataByte)
 * @details         Returns the nibble 1 of the given @a dataByte byte.
 * @param[in]       dataByte            variable
 * @return          @a dataByte nibble 1, shifted to bit position 0
*/
#define byteGetNibble1(dataByte)        (       \
        ((dataByte) >> 4) & 0x0F                \
)

/**
 * @def             byteGetNibble0(dataByte)
 * @details         Returns the nibble 0 of the given @a dataByte byte.
 * @param[in]       dataByte            variable
 * @return          @a dataByte nibble 0
*/
#define byteGetNibble0(dataByte)        (       \
        (dataByte) & 0x0F                       \
)

/**
 * @def             byteSwitchNibbles(dataByte)
 * @details         Switches the nibbles of the given @a dataByte byte.
 * @param[in]       dataByte            variable
 * @return          @a dataByte with nibbles switched
*/
#define byteSwitchNibbles(dataByte)     (       \
        (byteGetNibble0(dataByte) << 4) |       \
        (byteGetNibble1(dataByte))              \
)

//     ////////////     DATA MANIPULATION (16-BITS WIDE)     ////////////     //

/**
 * @def             hwordGetByte1(dataHword)
 * @details         Returns the byte 1 of the given @a dataHword half-word.
 * @param[in]       dataHword           variable
 * @return          @a dataHword byte 1, shifted to bit position 0
*/
#define hwordGetByte1(dataHword)        (       \
        ((dataHword) >> 8) & 0x00FF             \
)

/**
 * @def             hwordGetByte0(dataHword)
 * @details         Returns the byte 0 of the given @a dataHword half-word.
 * @param[in]       dataHword           variable
 * @return          @a dataHword byte 0
*/
#define hwordGetByte0(dataHword)        (       \
        (dataHword) & 0x00FF                    \
)

/**
 * @def             hwordSwitchBytes(dataHword)
 * @details         Switches the bytes of the given @a dataHword half-word.
 * @param[in]       dataHword           variable
 * @return          @a dataHword with bytes switched
*/
#define hwordSwitchBytes(dataHword)     (       \
        (hwordGetByte0(dataHword) << 8) |       \
        (hwordGetByte1(dataHword))              \
)

//     ////////////     DATA MANIPULATION (32-BITS WIDE)     ////////////     //

/**
 * @def             wordGetByte3(dataWord)
 * @details         Returns the byte 3 of the given @a dataWord word.
 * @param[in]       dataWord            variable
 * @return          @a dataWord byte 3, shifted to bit position 0
*/
#define wordGetByte3(dataWord)          (       \
        ((dataWord) >> 24) & 0x000000FF         \
)

/**
 * @def             wordGetByte2(dataWord)
 * @details         Returns the byte 2 of the given @a dataWord word.
 * @param[in]       dataWord            variable
 * @return          @a dataWord byte 2, shifted to bit position 0
*/
#define wordGetByte2(dataWord)          (       \
        ((dataWord) >> 16) & 0x000000FF         \
)

/**
 * @def             wordGetByte1(dataWord)
 * @details         Returns the byte 1 of the given @a dataWord word.
 * @param[in]       dataWord            variable
 * @return          @a dataWord byte 1, shifted to bit position 0
*/
#define wordGetByte1(dataWord)          (       \
        ((dataWord) >> 8) & 0x000000FF          \
)

/**
 * @def             wordGetByte0(dataWord)
 * @details         Returns the byte 0 of the given @a dataWord word.
 * @param[in]       dataWord            variable
 * @return          @a dataWord byte 0
*/
#define wordGetByte0(dataWord)          (       \
        (dataWord) & 0x000000FF                 \
)

/**
 * @def             wordSwitchBytes(dataWord)
 * @details         Switches the bytes of the given @a dataWord word.
 * @param[in]       dataWord            variable
 * @return          @a dataWord with bytes switched
*/
#define wordSwitchBytes(dataWord)       (       \
        (wordGetByte0(dataWord) << 24)  |       \
        (wordGetByte1(dataWord) << 16) |        \
        (wordGetByte2(dataWord) << 8)  |        \
        (wordGetByte3(dataWord))                \
)

/**
 * @def             wordGetHword1(dataWord)
 * @details         Returns the half word 1 of the given @a dataWord word.
 * @param[in]       dataWord            variable
 * @return          @a dataWord half word 1, shifted to bit position 0
*/
#define wordGetHword1(dataWord)         (       \
        ((dataWord) >> 16) & 0x0000FFFF         \
)

/**
 * @def             wordGetHword0(dataWord)
 * @details         Returns the half word 0 of the given @a dataWord word.
 * @param[in]       dataWord            variable
 * @return          @a dataWord half word 0
*/
#define wordGetHword0(dataWord)         (       \
        (dataWord) & 0x0000FFFF                 \
)

/**
 * @def             wordSwitchHwords(dataWord)
 * @details         Switches the half words of the given @a dataWord word.
 * @param[in]       dataWord            variable
 * @return          @a dataWord with half words switched
*/
#define wordSwitchHwords(dataWord)      (       \
        (wordGetHword0(dataWord) << 16) |       \
        (wordGetHword1(dataWord))               \
)

//     ////////////     DATA MANIPULATION (64-BITS WIDE)     ////////////     //

/**
 * @def             dwordGetByte7(dataDword)
 * @details         Returns the byte 7 of the given @a dataDword double word.
 * @param[in]       dataDword           variable
 * @return          @a dataDword byte 7, shifted to bit position 0
*/
#define dwordGetByte7(dataDword)        (               \
        ((dataDword) >> 56) & 0x00000000000000FF        \
)

/**
 * @def             dwordGetByte6(dataDword)
 * @details         Returns the byte 6 of the given @a dataDword double word.
 * @param[in]       dataDword           variable
 * @return          @a dataDword byte 6, shifted to bit position 0
*/
#define dwordGetByte6(dataDword)        (               \
        ((dataDword) >> 48) & 0x00000000000000FF        \
)

/**
 * @def             dwordGetByte5(dataDword)
 * @details         Returns the byte 5 of the given @a dataDword double word.
 * @param[in]       dataDword           variable
 * @return          @a dataDword byte 5, shifted to bit position 0
*/
#define dwordGetByte5(dataDword)        (               \
        ((dataDword) >> 40) & 0x00000000000000FF        \
)

/**
 * @def             dwordGetByte4(dataDword)
 * @details         Returns the byte 4 of the given @a dataDword double word.
 * @param[in]       dataDword           variable
 * @return          @a dataDword byte 4, shifted to bit position 0
*/
#define dwordGetByte4(dataDword)        (               \
        ((dataDword) >> 32) & 0x00000000000000FF        \
)

/**
 * @def             dwordGetByte3(dataDword)
 * @details         Returns the byte 3 of the given @a dataDword double word.
 * @param[in]       dataDword           variable
 * @return          @a dataDword byte 3, shifted to bit position 0
*/
#define dwordGetByte3(dataDword)        (               \
        ((dataDword) >> 24) & 0x00000000000000FF        \
)

/**
 * @def             dwordGetByte2(dataDword)
 * @details         Returns the byte 2 of the given @a dataDword double word.
 * @param[in]       dataDword           variable
 * @return          @a dataDword byte 2, shifted to bit position 0
*/
#define dwordGetByte2(dataDword)        (               \
        ((dataDword) >> 16) & 0x00000000000000FF        \
)

/**
 * @def             dwordGetByte1(dataDword)
 * @details         Returns the byte 1 of the given @a dataDword double word.
 * @param[in]       dataDword           variable
 * @return          @a dataDword byte 1, shifted to bit position 0
*/
#define dwordGetByte1(dataDword)        (               \
        ((dataDword) >> 8) & 0x00000000000000FF     \
)

/**
 * @def             dwordGetByte0(dataDword)
 * @details         Returns the byte 0 of the given @a dataDword double word.
 * @param[in]       dataDword           variable
 * @return          @a dataDword byte 0
*/
#define dwordGetByte0(dataDword)        (               \
        (dataDword) & 0x00000000000000FF        \
)

/**
 * @def             dwordSwitchBytes(dataDword)
 * @details         Switches the bytes of the given @a dataDWord double word.
 * @param[in]       dataDword           variable
 * @return          @a dataDword with bytes switched
*/
#define dwordSwitchBytes(dataDword)     (       \
        (dwordGetByte0(dataDword) << 56) |      \
        (dwordGetByte1(dataDword) << 48) |      \
        (dwordGetByte2(dataDword) << 40) |      \
        (dwordGetByte3(dataDword) << 32) |      \
        (dwordGetByte4(dataDword) << 24) |      \
        (dwordGetByte5(dataDword) << 16) |      \
        (dwordGetByte6(dataDword) << 8)  |      \
        (dwordGetByte7(dataDword))              \
)

/**
 * @def             dwordGetHword3(dataDword)
 * @details         Returns the half word 3 of the given @a dataDword double
 *                      word.
 * @param[in]       dataDword           variable
 * @return          @a dataDword half word 3, shifted to bit position 0
*/
#define dwordGetHword3(dataDword)       (               \
        ((dataDword) >> 48) & 0x000000000000FFFF        \
)

/**
 * @def             dwordGetHword2(dataDword)
 * @details         Returns the half word 2 of the given @a dataDword double
 *                      word.
 * @param[in]       dataDword           variable
 * @return          @a dataDword half word 2, shifted to bit position 0
*/
#define dwordGetHword2(dataDword)       (               \
        ((dataDword) >> 32) & 0x000000000000FFFF        \
)

/**
 * @def             dwordGetHword1(dataDword)
 * @details         Returns the half word 1 of the given @a dataDword double
 *                      word.
 * @param[in]       dataDword           variable
 * @return          @a dataDword half word 1, shifted to bit position 0
*/
#define dwordGetHword1(dataDword)       (               \
        ((dataDword) >> 16) & 0x000000000000FFFF        \
)

/**
 * @def             dwordGetHword0(dataDword)
 * @details         Returns the half word 0 of the given @a dataDword double
 *                      word.
 * @param[in]       dataDword           variable
 * @return          @a dataDword half word 0
*/
#define dwordGetHword0(dataDword)       (               \
        ((dataDword) >> 0) & 0x000000000000FFFF         \
)

/**
 * @def             dwordSwitchHwords(dataDword)
 * @details         Switches the half words of the given @a dataDWord double
 *                      word.
 * @param[in]       dataDword           variable
 * @return          @a dataDword with half words switched
*/
#define dwordSwitchHwords(dataDword)    (       \
        (dwordGetHword0(dataDword) << 48) |     \
        (dwordGetHword1(dataDword) << 32) |     \
        (dwordGetHword2(dataDword) << 16) |     \
        (dwordGetHword3(dataDword))             \
)

/**
 * @def             dwordGetWord1(dataDword)
 * @details         Returns the word 1 of the given @a dataDword double word.
 * @param[in]       dataDword           variable
 * @return          @a dataDword word 1, shifted to bit position 0
*/
#define dwordGetWord1(dataDword)         (              \
        ((dataDword) >> 32) & 0x00000000FFFFFFFF        \
)

/**
 * @def             dwordGetWord0(dataDword)
 * @details         Returns the word 0 of the given @a dataDword double word.
 * @param[in]       dataDword           variable
 * @return          @a dataDword word 1
*/
#define dwordGetWord0(dataDword)         (      \
        (dataDword) & 0x00000000FFFFFFFF        \
)

/**
 * @def             dwordSwitchWords(dataDword)
 * @details         Switches the words of the given @a dataDWord double word.
 * @param[in]       dataDword           variable
 * @return          @a dataDword with words switched
*/
#define dwordSwitchWords(dataDword)     (       \
        (dwordGetWord0(dataDword) << 32) |      \
        (dwordGetWord1(dataDword))              \
)

//     /////////////////////     TRUNCATE VALUES    /////////////////////     //

/**
 * @def             getMaximumOf(var1, var2)
 * @details         Returns the greater value between @a var1 and @a var2.
 * @param[in]       var1                first value
 * @param[in]       var2                second value
 * @return          the greater value between @a var1 and @a var2
*/
#define getMaximumOf(var1, var2)        (       \
        ((var1) > (var2))                       \
        ? (var1)                                \
        : (var2)                                \
)

/**
 * @def             getMinimumOf(var1, var2)
 * @details         Returns the lower value between @a var1 and @a var2.
 * @param[in]       var1                first value
 * @param[in]       var2                second value
 * @return          the lower value between @a var1 and @a var2
*/
#define getMinimumOf(var1, var2)        (       \
        ((var1) < (var2))                       \
        ? (var1)                                \
        : (var2)                                \
)

/**
 * @def             truncateBetween(var, min, max)
 * @details         Truncates (trims) the value between maximum and minimum
 *                      values.
 * @warning         The macro-function will not work correctly if @a min is
 *                      greater than @a max.
 * @param[in]       var                 value to be truncated
 * @param[in]       max                 maximum allowed value
 * @param[in]       min                 minumum allowed value
 * @return          @a min              if the value is lower than @a min
 * @return          @a max              if the value is greater than @a max
 * @return          @a var              if the value is placed between @a min
 *                                          and @a max
*/
#define truncateBetween(var, min, max)  (       \
        ((var) < (min))                         \
        ? (min)                                 \
        : (((var) > (max))                      \
                ? (max)                         \
                : (var)                         \
        )                                       \
)

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Doxygen: End subgroup "Global_Definitions/Data_Handling"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * @}
*/

// =============================================================================
// New data types
// =============================================================================

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Doxygen: Start subgroup "Global_Definitions/Data_Types"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * @addtogroup      Data_Types
 * @brief           Definition of new data types.
 * @{
*/

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Doxygen: Start subgroup "Global_Definitions/Data_Types/Single_Types"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * @addtogroup      Single_Types
 * @details         Single variables renaming or shortening names.
 * @{
*/

//     ////////////////////     BASIC VARIABLES     /////////////////////     //

/**
 * @typedef         bool_t
 * @details         Renamed to ensure code standardization.
*/
typedef bool                            bool_t;

/**
 * @typedef         char_t
 * @details         Renamed to ensure code standardization.
*/
typedef char                            char_t;

//     ///////////////////     CONSTANT VARIABLES    ////////////////////     //

/**
 * @typedef         cbool_t
 * @details         Short for <b><tt>const bool</tt></b>.
*/
typedef const bool_t                    cbool_t;

/**
 * @typedef         cchar_t
 * @details         Short for <b><tt>const char</tt></b>.
*/
typedef const char_t                    cchar_t;

/**
 * @typedef         cint8_t
 * @details         Short for <b><tt>const int8_t</tt></b>.
*/
typedef const int8_t                    cint8_t;

/**
 * @typedef         cint16_t
 * @details         Short for <b><tt>const int16_t</tt></b>.
*/
typedef const int16_t                   cint16_t;

/**
 * @typedef         cint32_t
 * @details         Short for <b><tt>const int32_t</tt></b>.
*/
typedef const int32_t                   cint32_t;

/**
 * @typedef         cint64_t
 * @details         Short for <b><tt>const int64_t</tt></b>.
*/
typedef const int64_t                   cint64_t;

/**
 * @typedef         cuint8_t
 * @details         Short for <b><tt>const uint8_t</tt></b>.
*/
typedef const uint8_t                   cuint8_t;

/**
 * @typedef         cuint16_t
 * @details         Short for <b><tt>const uint16_t</tt></b>.
*/
typedef const uint16_t                  cuint16_t;

/**
 * @typedef         cuint32_t
 * @details         Short for <b><tt>const uint32_t</tt></b>.
*/
typedef const uint32_t                  cuint32_t;

/**
 * @typedef         cuint64_t
 * @details         Short for <b><tt>const uint64_t</tt></b>.
*/
typedef const uint64_t                  cuint64_t;

//     ///////////////////     VOLATILE VARIABLES    ////////////////////     //

/**
 * @typedef         vbool_t
 * @details         Short for <b><tt>volatile bool</tt></b>.
*/
typedef volatile bool_t                 vbool_t;

/**
 * @typedef         vchar_t
 * @details         Short for <b><tt>volatile char</tt></b>.
*/
typedef volatile char_t                 vchar_t;

/**
 * @typedef         vint8_t
 * @details         Short for <b><tt>volatile int8_t</tt></b>.
*/
typedef volatile int8_t                 vint8_t;

/**
 * @typedef         vint16_t
 * @details         Short for <b><tt>volatile int16_t</tt></b>.
*/
typedef volatile int16_t                vint16_t;

/**
 * @typedef         vint32_t
 * @details         Short for <b><tt>volatile int32_t</tt></b>.
*/
typedef volatile int32_t                vint32_t;

/**
 * @typedef         vint64_t
 * @details         Short for <b><tt>volatile int64_t</tt></b>.
*/
typedef volatile int64_t                vint64_t;

/**
 * @typedef         vuint8_t
 * @details         Short for <b><tt>volatile uint8_t</tt></b>.
*/
typedef volatile uint8_t                vuint8_t;

/**
 * @typedef         vuint16_t
 * @details         Short for <b><tt>volatile uint16_t</tt></b>.
*/
typedef volatile uint16_t               vuint16_t;

/**
 * @typedef         vuint32_t
 * @details         Short for <b><tt>volatile uint32_t</tt></b>.
*/
typedef volatile uint32_t               vuint32_t;

/**
 * @typedef         vuint64_t
 * @details         Short for <b><tt>volatile uint64_t</tt></b>.
*/
typedef volatile uint64_t               vuint64_t;

//     /////////////////     AVR PLATFORM VARIABLES    //////////////////     //

/**
 * @typedef         int_t
 * @details         Standard <b><tt>int</tt></b> data size (16-bit in AVR processors).
*/
typedef int16_t                         int_t;

/**
 * @typedef         uint_t
 * @details         Standard <b><tt>unsigned int</tt></b> data size (16-bit in AVR processors).
*/
typedef uint16_t                        uint_t;

/**
 * @typedef         cint_t
 * @details         Standard <b><tt>const int</tt></b> data size (16-bit in AVR processors).
*/
typedef cint16_t                        cint_t;

/**
 * @typedef         cuint_t
 * @details         Standard <b><tt>const unsigned int</tt></b> data size (16-bit in AVR processors).
*/
typedef cuint16_t                       cuint_t;

/**
 * @typedef         vint_t
 * @details         Standard <b><tt>volatile int</tt></b> data size (16-bit in AVR processors).
*/
typedef vint16_t                        vint_t;

/**
 * @typedef         vuint_t
 * @details         Standard <b><tt>volatile unsigned int</tt></b> data size (16-bit in AVR processors).
*/
typedef vuint16_t                       vuint_t;

/**
 * @typedef         ioPinIndex_t
 * @details         Alias to handle a GPIO pin index.
*/
typedef uint8_t                         ioPinIndex_t;

/**
 * @typedef         ioPinMask_t
 * @details         Alias to handle a GPIO pin mask.
*/
typedef uint8_t                         ioPinMask_t;

/**
 * @typedef         ioRegAddress_t
 * @details         Alias to handle a GPIO register address.
*/
typedef vuint8_t                       *ioRegAddress_t;

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Doxygen: End subgroup "Global_Definitions/Data_Types/Single_Types"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * @}
*/

//     //////////////////     BINARY ENUMERATIONS     ///////////////////     //

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Doxygen: Start subgroup "Global_Definitions/Data_Types/Binary_Enumerations"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * @addtogroup      Binary_Enumerations
 * @details         Enumerations with only two possible values.
 * @{
*/

/**
 * @enum            Activation
 * @details         Used to refer to the activation state of an peripheral.
*/
enum class Activation : cbool_t {
    OFF                                 = false,        //!< Deactivated
    ON                                  = true          //!< Activated
};

/**
 * @enum            DisplayOrientation
 * @details         Used to refer to the orientation of a display screen.
*/
enum class DisplayOrientation : cbool_t {
    LANDSCAPE                           = false,        //!< Display is on landscape orientation
    PORTRAIT                            = true          //!< Display is on portrait orientation
};

/**
 * @enum            DriverMode
 * @details         Used to refer to the GPIO Pin output driver mode.
*/
enum class DriverMode : cbool_t {
    PUSH_PULL                           = false,        //!< Push-pull driver
    OPEN_DRAIN                          = true,         //!< Open-drain driver
};

/**
 * @enum            Edge
 * @details         Used to specify the edge of a signal.
*/
enum class Edge : cbool_t {
    FALLING                             = false,        //!< Falling edge of the signal
    RISING                              = true          //!< Rising edge of the signal
};

/**
 * @enum            IoOperation
 * @details         Used to specify the GPIO or communications operation.
*/
enum class IoOperation : cbool_t {
    WRITE                               = false,        //!< Write operation
    READ                                = true          //!< Read operation
};

/**
 * @enum            LogicLevel
 * @details         Used to specify the logic level of a signal.
*/
enum class LogicLevel : cbool_t {
    LOW                                 = false,        //!< Low level
    HIGH                                = true          //!< High level
};

/**
 * @enum            PinDirection
 * @details         Used to specify the direction of a GPIO pin.
*/
enum class PinDirection : cbool_t {
    INPUT                               = false,        //!< Pin is an input
    OUTPUT                              = true,         //!< Pis is an output
};

/**
 * @enum            Rotation
 * @details         Used to specify a rotation direction.
*/
enum class Rotation : cbool_t {
    CLOCKWISE                           = false,        //!< Clockwise direction
    COUNTERCLOCKWISE                    = true          //!< Counter-clockwise direction
};

/**
 * @enum            State
 * @details         Used to generically refer to an state or status. For
 *                      example, the state of a LED.
*/
enum class State : cbool_t {
    OFF                                 = false,        //!< State is OFF
    ON                                  = true          //!< State is ON
};

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Doxygen: End subgroup "Global_Definitions/Data_Types/Binary_Enumerations"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * @}
*/

//     ///////////////////     PLAIN ENUMERATIONS    ////////////////////     //

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Doxygen: Start subgroup "Global_Definitions/Data_Types/Plain_Enumerations"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * @addtogroup      Plain_Enumerations
 * @details         Enumerations with multiple possible values.
 * @{
*/

/**
 * @enum            Axis
 * @details         Used to specify the 3D Cartesian axes.
*/
enum class Axis : cuint8_t {
    //                                     Z-AXIS     Y-AXIS     X-AXIS
    NONE                                = (0 << 2) | (0 << 1) | (0 << 0),       //!< No axis selected
    X                                   = (0 << 2) | (0 << 1) | (1 << 0),       //!< X axis selected
    Y                                   = (0 << 2) | (1 << 1) | (0 << 0),       //!< Y axis selected
    XY                                  = (0 << 2) | (1 << 1) | (1 << 0),       //!< X and Y axes selected
    Z                                   = (1 << 2) | (0 << 1) | (0 << 0),       //!< Z axis selected
    XZ                                  = (1 << 2) | (0 << 1) | (1 << 0),       //!< X and Z axes selected
    YZ                                  = (1 << 2) | (1 << 1) | (0 << 0),       //!< Y and Z axes selected
    ALL                                 = (1 << 2) | (1 << 1) | (1 << 0)        //!< X, Y and Z axes selected
};

/**
 * @cond
*/

Axis inlined operator|(Axis a, Axis b)
{
    return static_cast<Axis>(static_cast<uint8_t>(a) | static_cast<uint8_t>(b));
}

Axis inlined &operator|=(Axis &a, Axis b)
{
    return a = static_cast<Axis>(static_cast<uint8_t>(a) | static_cast<uint8_t>(b));
}

Axis inlined operator&(Axis a, Axis b)
{
    return static_cast<Axis>(static_cast<uint8_t>(a) & static_cast<uint8_t>(b));
}

Axis inlined &operator&=(Axis &a, Axis b)
{
    return a = static_cast<Axis>(static_cast<uint8_t>(a) & static_cast<uint8_t>(b));
}

/**
 * @endcond
*/

/**
 * @enum            Direction
 * @details         Used to specify 2D plain directions.
*/
enum class Direction : cuint8_t {
    LEFT                                = 0,            //!< Left planar direction
    RIGHT                               = 1,            //!< Right planar direction
    UP                                  = 2,            //!< Up planar direction
    DOWN                                = 3             //!< Down planar direction
};

/**
 * @enum            InterfaceMode
 * @details         Used to specify the access mode to the peripheral.
*/
enum class InterfaceMode : cuint8_t {
    BLOCKING_MODE                       = 0,            //!< Do not use interrupt or DMA
    INTERRUPT_MODE                      = 1,            //!< Use the peripheral interrupt
    DMA_MODE                            = 2             //!< Use the DMA interrupt
};

/**
 * @enum            ThermometricScale
 * @details         Used to specify a Thermometric scale.
*/
enum class ThermometricScale : cuint8_t {
    CELSIUS                             = 0,            //!< Celsius thermometric scale
    DELISLE                             = 1,            //!< Delisle thermometric scale
    FAHRENHEIT                          = 2,            //!< Fahrenheit thermometric scale
    KELVIN                              = 3,            //!< Kelvin absolute temperature
    NEWTON                              = 4,            //!< Newton thermometric scale
    RANKINE                             = 5,            //!< Rankine thermometric scale
    REAUMUR                             = 6,            //!< Reaumur thermometric scale
    ROMER                               = 7             //!< Romer thermometric scale
};

/**
 * @enum            Error
 * @details         Funsape error codes.
*/
enum class Error : cuint16_t {
    // General error codes
    NONE                                                = 0x0000,   //!< Success - No errors occurred.

    DEVICE_DISABLED                                     = 0x0001,   //!< Device disabled
    FEATURE_NOT_SUPPORTED                               = 0x0002,   //!< Unsupported feature or configuration.
    LOCKED                                              = 0x0003,   //!< Accessed a locked device
    MEMORY_ALLOCATION_FAILED                            = 0x0004,   //!< Memory allocation failed.
    MODE_NOT_SUPPORTED                                  = 0x0005,   //!< This operation mode is not supported by the module.
    NOT_IMPLEMENTED                                     = 0x0006,   //!< This feature is not implemented yet, but is marked for future implementation.
    NOT_INITIALIZED                                     = 0x0007,   //!< The module was not initialized.
    READ_PROTECTED                                      = 0x0008,   //!< Tried to read a read protected device
    WRITE_PROTECTED                                     = 0x0009,   //!< Tried to write a write protected device
    // UNDER_DEVELOPMENT                                   = 0x000A,   //!< This part of the code is still under development
    // BUSY                                                = 0x000B,   //!< TODO: Describe parameter
    // DEVICE_NOT_SUPPORTED                                = 0x000C,   //!< Device is not currently supported
    FUNCTION_POINTER_NULL                               = 0x000D,   //!< TODO: Describe parameter
    // INSTANCE_INVALID                                    = 0x000E,   //!< Invalid instance
    NOT_READY                                           = 0x000F,   //!< TODO: Describe parameter

    // Function arguments related error codes
    ARGUMENT_CANNOT_BE_ZERO                             = 0x0010,   //!< The argument value must not be zero (0).
    ARGUMENT_POINTER_NULL                               = 0x0011,   //!< NULL pointer was passed as an argument to function.
    ARGUMENT_VALUE_INVALID                              = 0x0012,   //!< The argument value is not valid.
    // ARGUMENTS_MISMATCH                                  = 0x0013,   //!< A function was called with dubious argument values
    // ARGUMENTS_WRONG_NUMBER                              = 0x0014,   //!< A function was called with wrong number of arguments

    // Buffer related error codes
    BUFFER_EMPTY                                        = 0x0020,   //!< Buffer is empty
    BUFFER_FULL                                         = 0x0021,   //!< Buffer is full
    BUFFER_NOT_ENOUGH_ELEMENTS                          = 0x0022,   //!< Not enough space in buffer to perform operation
    BUFFER_NOT_ENOUGH_SPACE                             = 0x0023,   //!< Not enough space in buffer to perform operation
    BUFFER_SIZE_TOO_LARGE                               = 0x0024,   //!< Buffer size was set to a large value.
    BUFFER_SIZE_TOO_SMALL                               = 0x0025,   //!< Buffer size was set to a very small value.
    // BUFFER_POINTER_NULL                                 = 0x0024,   //!< Buffer size was set to zero
    // BUFFER_SIZE_ZERO                                    = 0x0027,   //!< Buffer size was set to zero

    // Clock configuration related error codes
    CLOCK_PRESCALER_CHANGE_FAILED                       = 0x0030,   //!< Clock prescaler change failed.
    CLOCK_PRESCALER_NOT_SUPPORTED                       = 0x0031,   //!< Clock prescaler configuration unsupported.
    CLOCK_SPEED_TOO_HIGH                                = 0x0032,   //!< The clock speed is too high.
    CLOCK_SPEED_TOO_LOW                                 = 0x0033,   //!< The clock speed is too low.

    // GPIO related error codes
    GPIO_BUS_SIZE_INVALID                               = 0x0040,
    GPIO_PIN_OUT_OF_BOUNDARIES                          = 0x0041,   //!< Gpio pin index was out of bounds after processing.
    GPIO_PORT_INVALID                                   = 0x0042,   //!< Gpio port address is invalid.
    // GPIO_DATA_PORT_NOT_SET                              = 0x00D1,   //!< Gpio data port was not set before use
    // GPIO_CONTROL_PORT_NOT_SET                           = 0x00D2,   //!< Gpio control port was not set before use
    // GPIO_DATA_PORT_INVALID                              = 0x00D4,   //!< Gpio data port address is invalid.
    // GPIO_CONTROL_PORT_INVALID                           = 0x00D5,   //!< Gpio control port address is invalid.
    // GPIO_PIN_INDEX_INVALID                              = 0x00D6,   //!< Invalid GPIO Pin.
    // GPIO_NO_PIN_SET                                     = 0x00D8,   //!< No pin selected at Gpio peripheral
    // GPIO_ADDRESS_INVALID                                = 0x00D9,   //!< Invalid GPIO Port
    // GPIO_PORT_LOGIC_CONTENTION                          = 0x00DA,   //!< TODO: Describe parameter
    GPIO_NOT_INITIALIZED                                = 0x0043,
    GPIO_PORT_NOT_SET                                   = 0x0044,   //!< Gpio port was not set before use.

    // USART related error codes
    USART_BAUD_RATE_NOT_SUPPORTED                       = 0x0050,   //!< The baud rate value is not supported.
    USART_DATA_SIZE_NOT_SUPPORTED                       = 0x0051,   //!< The number of data bits is invalid.
    USART_FRAME_FORMAT_NOT_SUPPORTED                    = 0x0052,   //!< The format of the frame is not supported.
    USART_PARITY_NOT_SUPPORTED                          = 0x0053,   //!< Parity mode not supported.
    USART_STOP_BIT_NOT_SUPPORTED                        = 0x0054,   //!< Invalid number of stop bits.
    // USART_CONFIGURATION_PARAMETER_WRONG                 = 0x00B1,   //!< TODO: Describe parameter

    // Communication related error codes
    COMMUNICATION_FAILED                                = 0x0060,   //!< The communication has failed.
    DEVICE_NOT_SELECTED                                 = 0x0061,   //!< No communication device was selected.
    TIMED_OUT                                           = 0x0062,   //!< The operation timed out.
    CHECKSUM_ERROR                                      = 0x0045,   //!< TODO: Describe parameter
    // COMMUNICATION_PORT_NOT_SET                          = 0x0042,   //!< TODO: Describe parameter
    DEVICE_ID_MATCH_FAILED                              = 0x0044,   //!< TODO: Describe parameter
    // FRAME_ERROR                                         = 0x0046,   //!< TODO: Describe parameter
    // PACKAGE_AWAITING                                    = 0x0047,   //!< Try to write data to a ready package
    // PACKAGE_NOT_READY                                   = 0x0048,   //!< Try to read data from a not ready package

    // DateTime class related error codes
    // DATE_INVALID                                        = 0x000E,   //!< The date value is invalid.
    // DATE_NOT_INITIALIZED                                = 0x000F,   //!< The date was not initialized.
    // HOUR_INVALID                                        = 0x0051,   //!< TODO: Describe parameter
    // MILLISECOND_INVALID                                 = 0x0052,   //!< TODO: Describe parameter
    // MINUTE_INVALID                                      = 0x0053,   //!< TODO: Describe parameter
    // MONTH_DAY_INVALID                                   = 0x0054,   //!< TODO: Describe parameter
    // MONTH_INVALID                                       = 0x0055,   //!< TODO: Describe parameter
    // SECOND_INVALID                                      = 0x0056,   //!< TODO: Describe parameter
    // TIME_INVALID                                        = 0x001C,   //!< The time value is invalid.
    // TIME_NOT_INITIALIZED                                = 0x001D,   //!< The time was not initialized.
    // TIMEZONE_INVALID                                    = 0x0058,   //!< TODO: Describe parameter
    // YEAR_INVALID                                        = 0x0059,   //!< TODO: Describe parameter

    // Handler related error codes
    BUS_HANDLER_NOT_SUPPORTED                           = 0x0060,   //!< The specified bus handler type is not supported by this module.
    BUS_HANDLER_POINTER_NULL                            = 0x0061,   //!< The bus handler pointer cannot be null.
    BUS_HANDLER_INVALID                                 = 0x0062,   //!< The bus handler pointer cannot be null.

    // External interrupts related error codes
    // INTERRUPT_NOT_AVAILABLE                             = 0x0070,   //!< TODO: Describe parameter
    // INTERRUPT_PORT_OUTPUT_MODE_NOT_SUPPORTED            = 0x0071,   //!< TODO: Describe parameter
    // INTERRUPT_SENSE_MODE_NOT_SUPPORTED                  = 0x0072,   //!< TODO: Describe parameter

    // Package API class related error codes
    // PACKAGE_API_PACKAGE_DATA_FULL                       = 0x0080,   //!< TODO: Describe parameter
    // PACKAGE_API_PACKAGE_NOT_READY                       = 0x0081,   //!< TODO: Describe parameter
    // PACKAGE_API_PAYLOAD_DATA_NULL                       = 0x0082,   //!< TODO: Describe parameter
    PARSER_API_PAYLOAD_SIZE_ZERO                        = 0x0083,   //!< TODO: Describe parameter
    PARSER_API_SOURCE_ADDRESS_INVALID                   = 0x0084,   //!< TODO: Describe parameter

    // SPI related error codes
    // SPI_BUSY_FLAG                                       = 0x0090,   //!< TODO: Describe parameter
    // SPI_CRC                                             = 0x0091,   //!< TODO: Describe parameter
    // SPI_DMA                                             = 0x0092,   //!< TODO: Describe parameter
    // SPI_MODE_FAULT                                      = 0x0093,   //!< TODO: Describe parameter
    // SPI_OVERRUN                                         = 0x0094,   //!< TODO: Describe parameter

    // TWI related error codes
    // TWI_AF_FLAG                                         = 0x00A0,   //!< TWI AF flag error
    // TWI_ARBITRATION_LOST                                = 0x00A1,   //!< TWI bus arbitration lost
    // TWI_BUS_ERROR                                       = 0x00A2,   //!< TWI bus error
    // TWI_DMA                                             = 0x00A3,   //!< DMA parameter error
    // TWI_DMA_PARAM                                       = 0x00A4,   //!< DMA transfer error
    // TWI_OVERRUN                                         = 0x00A5,   //!< TWI overrun
    // TWI_SIZE_MANAGEMENT_ERROR                           = 0x00A6,   //!< Size management error
    // TWI_INVALID_DEVICE_ADDRESS                          = 0x00A7,   //!< TODO: Describe parameter

    // LCD related error codes
    // LCD_CONTROL_PIN_E_INVALID                           = 0x00C1,   //!< TODO: Describe parameter
    // LCD_CONTROL_PIN_RS_INVALID                          = 0x00C2,   //!< TODO: Describe parameter
    // LCD_CONTROL_PIN_RW_INVALID                          = 0x00C3,   //!< TODO: Describe parameter
    // LCD_CONTROL_PORT_NOT_SET                            = 0x00C0,   //!< TODO: Describe parameter
    // LCD_DATA_PIN_INDEX_OUT_OF_BOUNDARIES                = 0x00C5,   //!< TODO: Describe parameter
    // LCD_DATA_PORT_NOT_SET                               = 0x00C4,   //!< TODO: Describe parameter
    // LCD_OUT_OF_BOUNDARIES                               = 0xFFF1,   //!< TODO: Describe parameter

    // System related error codes
    // SYSTEM_US_TIMER_HANDLER_NULL                        = 0x00F0,   //!< TODO: Describe parameter

    // FatFs related error codes
    // FAT_FS_UNKNOWN_ERROR                                = 0x0100,   //!< TODO: Describe parameter
    // FAT_FS_DRIVE_UNSUPPORTED                            = 0x0101,   //!< TODO: Describe parameter
    // FAT_FS_DISK_NOT_INSERTED                            = 0x0102,   //!< TODO: Describe parameter
    // FAT_FS_INITIALIZATION_FAILED                        = 0x0103,   //!< TODO: Describe parameter

    // Uncategorized error codes
    // CONTROLLER_NOT_SUPPORTED                            = 0xFFF2,   //!< Unsupported controller
    // DMA_NOT_SUPPORTED                                   = 0xFFF4,   //!< DMA interface mode is not supported for this module
    // DMA_TRANSFER_ERROR                                  = 0xFFF5,   //!< DMA transfer error
    // MESSAGE_TOO_LONG                                    = 0xFFF6,   //!< Message is to long to be stored inside buffer
    // VALID_DATA_NOT_AVAILABLE                            = 0xFFF7,   //!< Valid data was unavailable
    // PERIPHERAL_NOT_READY                                = 0xFFF8,   //!< TODO: Describe parameter
    // STOPWATCH_NOT_STARTED                               = 0xFFF9,   //!< TODO: Describe parameter
    // NMEA_SENTENCE_UNKNOWN                               = 0xFFFC,
    // KEYPAD_TYPE_UNSUPPORTED                             = 0xFFFD,       //!< This keypad is not supported.
    // KEY_VALUES_NOT_SET                                  = 0xFFFE,       //!< The values of the keys was not configured.

    AXIS_INVALID                                        = 0xFFC0,
    // "I don't have the slightest idea" error code
    UNKNOWN                                             = 0xFFFF,   // Unknown error - Ops!!!!
};

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Doxygen: End subgroup "Global_Definitions/Data_Types/Plain_Enumerations"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * @}
*/

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Doxygen: End subgroup "Global_Definitions/Data_Types"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * @}
*/

// =============================================================================
// Extern global variables
// =============================================================================

// NONE

// =============================================================================
// Inline functions declaration
// =============================================================================

//     ///////////////////     CHARACTER HANDLING    ////////////////////     //

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Doxygen: Start subgroup "Global_Definitions/String_Handling"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * @addtogroup      String_Handling
 * @details         Performs general handling on @c char and @c strings.
 * @{
*/

/**
 * @brief           Returns the lowercase version of a character.
 * @details         This funcion returns the lowercase version of the given
 *                      character @a character_p. If @a character_p is not an
 *                      uppercase letter, the function will return
 *                      @a character_p without change.
 * @param[in]       character_p         character to be lowercased
 * @return          the lowercase version of @a character_p
*/
char_t inlined toLowerCase(cchar_t character_p);

/**
 * @brief           Returns the uppercase version of a character.
 * @details         This funcion returns the uppercase version of the given
 *                      character @a character_p. If @a character_p is not a
 *                      lowercase letter, the function will return
 *                      @a character_p without change.
 * @param[in]       character_p         character to be uppercased
 * @return          the uppercase version of @a character_p
*/
char_t inlined toUpperCase(cchar_t character_p);

//     /////////////////////     DATA VALIDITY     //////////////////////     //

/**
 * @brief           Verifies if a character is an ASCII lowercase letter.
 * @details         This function verifies if the given character @a character_p
 *                      is an ASCII lowercase letter.
 * @param[in]       character_p         character to be evaluated
 * @retval          true                if @a character_p is an ASCII lowercase
 *                                          letter
 * @retval          false               if @a character_p is not an ASCII
 *                                          lowercase letter
*/
bool_t inlined isAsciiLowerCaseLetter(cchar_t character_p);

/**
 * @brief           Verifies if a character is an ASCII uppercase letter.
 * @details         This function verifies if the given character @a character_p
 *                      is an ASCII uppercase letter.
 * @param[in]       character_p         character to be evaluated
 * @retval          true                if @a character_p is an ASCII uppercase
 *                                          letter
 * @retval          false               if @a character_p is not an ASCII
 *                                          uppercase letter
*/
bool_t inlined isAsciiUpperCaseLetter(cchar_t character_p);

/**
 * @brief           Verifies if a character is an ASCII command character.
 * @details         This function verifies if the given character @a character_p
 *                      is an ASCII command character.
 * @param[in]       character_p         character to be evaluated
 * @retval          true                if @a character_p is an ASCII command
 *                                          character
 * @retval          false               if @a character_p is not an ASCII
 *                                          command character
*/
bool_t inlined isAsciiCommand(cchar_t character_p);

/**
 * @brief           Verifies if a character is an ASCII letter character.
 * @details         This function verifies if the given character @a character_p
 *                      is an ASCII letter character.
 * @param[in]       character_p         character to be evaluated
 * @retval          true                if @a character_p is an ASCII letter
 *                                          character
 * @retval          false               if @a character_p is not an ASCII
 *                                          letter character
*/
bool_t inlined isAsciiLetter(cchar_t character_p);

/**
 * @brief           Verifies if a character is an ASCII number character.
 * @details         This function verifies if the given character @a character_p
 *                      is an ASCII number character.
 * @param[in]       character_p         character to be evaluated
 * @retval          true                if @a character_p is an ASCII number
 *                                          character
 * @retval          false               if @a character_p is not an ASCII
 *                                          number character
*/
bool_t inlined isAsciiNumber(cchar_t character_p);

/**
 * @brief           Verifies if a character is an ASCII symbol character.
 * @details         This function verifies if the given character @a character_p
 *                      is an ASCII symbol character.
 * @param[in]       character_p         character to be evaluated
 * @retval          true                if @a character_p is an ASCII symbol
 *                                          character
 * @retval          false               if @a character_p is not an ASCII
 *                                          symbol character
*/
bool_t inlined isAsciiSymbol(cchar_t character_p);

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Doxygen: End subgroup "Global_Definitions/String_Handling"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * @}
*/

//     /////////////////////     SYSTEM ACTIONS    //////////////////////     //

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Doxygen: Start subgroup "Global_Definitions/System_Functions"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * @addtogroup      System_Functions
 * @details         General system functions.
 * @{
*/

/**
 * @brief           Halts system execution printing a formatted string.
 * @details         This function halts system execution and prints a formatted
 *                      string with the error code provided by @a errorCode_p.
 * @param[in]       errorCode_p         @ref Error enumeration
*/
void inlined die(Error errorCode_p);

/**
 * @brief           Executes a @c NOP assembly instruction.
 * @details         This function executes a @c NOP assembly instruction.
 * @attention       This function takes one clock cycle of program execution. Do
 *                      not mistake with @ref doNothing() function, that is not
 *                      physically implemented after compilation.
*/
void inlined doNop(void);

/**
 * @brief           Do nothing placeholder.
 * @details         This function does nothing and do not generate any code.
 *                      Must be used as a placeholder (code standardization).
 * @attention       This function is not physically implemented after
 *                      compilation. Do not mistake with @ref doNop() function,
 *                      that takes one clock cycle of program execution.
*/
void inlined doNothing(void);

/**
 * @brief           Halts system execution calling a function.
 * @details         This function halts system execution and calls the given
 *                      @a callBack_p function.
 * @param[in]       callBack_p          function to be called
*/
void inlined systemHalt(void (*callBack_p)(void) = nullptr);

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Doxygen: End subgroup "Global_Definitions/System_Functions"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * @}
*/

/**
 * @cond
*/

// =============================================================================
// Inline functions definitions
// =============================================================================

//     ///////////////////     CHARACTER HANDLING    ////////////////////     //

char_t inlined toLowerCase(cchar_t character_p)
{
    return ((isAsciiUpperCaseLetter(character_p)) ? (character_p + 0x20) : character_p);
}

char_t inlined toUpperCase(cchar_t character_p)
{
    return ((isAsciiLowerCaseLetter(character_p)) ? (character_p - 0x20) : character_p);
}

//     /////////////////////     DATA VALIDITY     //////////////////////     //

bool_t inlined isAsciiLowerCaseLetter(cchar_t character_p)
{
    return ((bool_t)(((character_p >= 'a') && (character_p <= 'z')) ? true : false));
}

bool_t inlined isAsciiUpperCaseLetter(cchar_t character_p)
{
    return ((bool_t)(((character_p >= 'A') && (character_p <= 'Z')) ? true : false));
}

bool_t inlined isAsciiCommand(cchar_t character_p)
{
    return ((bool_t)((character_p < ' ') ? true : false));
}

bool_t inlined isAsciiLetter(cchar_t character_p)
{
    return ((bool_t)((isAsciiLowerCaseLetter(character_p) || (isAsciiUpperCaseLetter(character_p)) ? true : false)));
}

bool_t inlined isAsciiNumber(cchar_t character_p)
{
    return ((bool_t)(((character_p >= '0') && (character_p <= '9')) ? true : false));
}

bool_t inlined isAsciiSymbol(cchar_t character_p)
{
    return ((bool_t)(((!isAsciiNumber(character_p)) && (!isAsciiCommand(character_p)) &&
                                    (!isAsciiLetter(character_p))) ? true : false));
}

//     /////////////////////     SYSTEM ACTIONS    //////////////////////     //

void inlined die(Error errorCode_p)
{
    printf_P(PSTR("Failed with error=%u (0x%04x).\r"), (cuint16_t)errorCode_p, (cuint16_t)errorCode_p);
    systemHalt();

    return;
}

void inlined doNop(void)
{
    asm volatile("nop");

    return;
}

void inlined doNothing(void)
{
    return;
}

void inlined systemHalt(void (*function_p)(void))
{
    cli();
    if(isPointerValid(function_p)) {
        function_p();
    }
    while(1) {
        doNothing();
    }

    return;
}

/**
 * @endcond
*/

// =============================================================================
// Public functions weakly defined
// =============================================================================

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Doxygen: Start subgroup "Global_Definitions/System_Functions"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * @addtogroup      System_Functions
 * @details         General system functions.
 * @{
*/

/**
 * @def             delayMs(time)
 * @details         Alias of the millisecond delay function.
*/
#define delayMs(time)                   _delay_ms(time)

/**
 * @def             delayMs(time)
 * @details         Alias of the microsecond delay function.
*/
#define delayUs(time)                   _delay_us(time)

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Doxygen: End subgroup "Global_Definitions/System_Functions"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * @}
*/

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Doxygen: End main group "Global_Definitions"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * @}
*/

// =============================================================================
// Include guard (END)
// =============================================================================

#endif  // __GLOBAL_DEFINES_HPP

// =============================================================================
// End of file (globalDefines.hpp)
// =============================================================================
