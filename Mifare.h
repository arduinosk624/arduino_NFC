#ifndef __MIFARE_INCLUDED__
#define __MIFARE_INCLUDED__

#include "PN532_Com.h"

#define MIFARE_ISO14443A              (0x00)

// Mifare Commands
#define MIFARE_CMD_AUTH_A                   (0x60)
#define MIFARE_CMD_AUTH_B                   (0x61)
#define MIFARE_CMD_READ                     (0x30)
#define MIFARE_CMD_WRITE                    (0xA0)
#define MIFARE_CMD_TRANSFER                 (0xB0)
#define MIFARE_CMD_DECREMENT                (0xC0)
#define MIFARE_CMD_INCREMENT                (0xC1)
#define MIFARE_CMD_STORE                    (0xC2)

#define MIFARE_CLASSIC      0x000408 /* ATQA 00 04	 SAK 08 */
#define MIFARE_ULTRALIGHT   0x004400 /* ATQA 00 44	 SAK 00 */

#define KEY_A	1
#define KEY_B	2


extern PN532 * board;

class Mifare{
  public:
	Mifare();
    
    static uint8_t keyA[6];
    static uint8_t keyB[6];
    static uint8_t useKey;
    static uint32_t cardType;
    
	boolean SAMConfig(void);
    uint8_t* readTarget(void);
    
    boolean readPayload();
    boolean writePayload(uint8_t * payload);
    
  private:
    boolean classic_authenticateBlock (uint32_t blockNumber);
    
    boolean classic_readPayload();
    boolean classic_writePayload(uint8_t * payload);
    boolean classic_readMemoryBlock(uint8_t blockaddress, uint8_t * block);
    boolean classic_writeMemoryBlock(uint8_t blockaddress, uint8_t * block);
    
    boolean ultralight_readPayload();
    boolean ultralight_writePayload(uint8_t * payload);
    boolean ultralight_readMemoryBlock(uint8_t blockaddress, uint8_t *block);
    boolean ultralight_writeMemoryBlock(uint8_t blockaddress, uint8_t *block);
    
};

#endif