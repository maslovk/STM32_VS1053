# STM32_VS1053
STM32 VS1053 Driver

Typical driver configuration:

main{


	VS1053_configure(&vs1053,&hspi1,GPIOA,GPIO_PIN_1,GPIOA,GPIO_PIN_3,GPIOA,GPIO_PIN_4,GPIOA,GPIO_PIN_2,1000);
	
	VS1053_sci_write_DMA(&vs1053,SCI_CLOCKF,0x8800);
	
  	VS1053_sci_setattenuation(&vs1053,60,60);//Range-0..254 0-Full volume 254-Silence
  
}
