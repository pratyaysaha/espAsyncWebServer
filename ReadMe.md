## Hosting a webpage by File System in NodeMcu
Serial Peripheral Interface Flash File System (SPIFFS) is a light weight file system in microcontrollers that uses SPI flash chip. NodeMCU comes with 1MB, 2MB, 3MB option of data upload. 
In NodeMCU there are two types of starage :
- The existing __EEPROM__ has infinite write cycles which is used for storing the code for the microcontroller to run. 
- The __SPIFFS__ chip has is used for storing data like webpages, Wifi config files, etc.

