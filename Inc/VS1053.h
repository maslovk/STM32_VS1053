#include "stm32f4xx_hal_def.h"

#define SCI_MODE 0x00
#define SCI_STATUS 0x01
#define SCI_BASS 0x02
#define SCI_CLOCKF 0x03
#define SCI_DECODETIME 0x04
#define SCI_AUDATA 0x05
#define SCI_WRAM 0x06
#define SCI_WRAMADDR 0x07
#define SCI_HDAT0 0x08
#define SCI_HDAT1 0x09
#define SCI_VOL 0x0B



typedef struct
{
	SPI_HandleTypeDef* hspi;
	
  GPIO_TypeDef* DREQport;
  uint16_t DREQpin;
	
	GPIO_TypeDef* CSport;
  uint16_t CSpin;
	
	GPIO_TypeDef* DCSport;
  uint16_t DCSpin;
	
	GPIO_TypeDef* RSTport;
  uint16_t RSTpin;
	
	uint32_t timeout;
	
	uint8_t initialised;
	
__IO	uint8_t playback;
	
__IO	uint8_t datareq;
	
	
}VS1053_InitTypeDef;

void VS1053_configure(VS1053_InitTypeDef* vs1053,SPI_HandleTypeDef* hspi,GPIO_TypeDef* DREQport,uint16_t DREQpin,GPIO_TypeDef* CSport,uint16_t CSpin,
	GPIO_TypeDef* DCSport,uint16_t DCSpin,GPIO_TypeDef* RSTport,uint16_t RSTpin,uint32_t timeout);

void VS1053_sci_write(VS1053_InitTypeDef* vs1053,uint8_t addr,uint16_t data);
uint16_t VS1053_sci_read(VS1053_InitTypeDef* vs1053,uint8_t addr);
void VS1053_sdi_write(VS1053_InitTypeDef* vs1053,uint8_t* txbuff,uint16_t datasize);
void VS1053_sci_write_DMA(VS1053_InitTypeDef* vs1053,uint8_t addr,uint16_t data);
void VS1053_sdi_write_DMA(VS1053_InitTypeDef* vs1053,uint8_t* txbuff,uint16_t datasize);
void SPI_Set_Baud_Prescaler(SPI_HandleTypeDef *hspi,uint32_t baud);
void VS1053_sci_setattenuation(VS1053_InitTypeDef* vs1053,uint8_t l_chan,uint8_t r_chan);
