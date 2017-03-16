/*
 *  dxl_hw.cpp
 *
 *  dynamixel hardware
 *
 *  Created on: 2016. 10. 21.
 *      Author: Baram
 */

#include "dxl_hw.h"









/*---------------------------------------------------------------------------
     TITLE   : dxl_hw_begin
     WORK    :
---------------------------------------------------------------------------*/
void dxl_hw_begin(uint8_t baud)
{
  uint32_t Baudrate = 0;


  pinMode( BDPIN_DXL_PWR_EN, OUTPUT );
  dxl_hw_power_disable();


  switch(baud)
  {
    case 0:
      Baudrate = 9600;        // 9600 BPS
      break;

    case 1:
      Baudrate = 57600;       // 57,600 BPS
      break;

    case 2:
      Baudrate = 115200;      // 115,200 BPS
      break;

    case 3:
      Baudrate = 1000000;     // 1M BPS
      break;

    case 4:
      Baudrate = 2000000;     // 2M BPS
      break;

    case 5:
      Baudrate = 3000000;     // 3M BPS
      break;

    case 6:
      Baudrate = 4000000;     // 4M BPS
      break;

    case 7:
      Baudrate = 4500000;     // 4.5M BPS
      break;

    default:
      Baudrate = 1000000;     // 1M BPS
      break;
  }


  DXL_PORT.begin(Baudrate);
}


/*---------------------------------------------------------------------------
     TITLE   : dxl_hw_tx_enable
     WORK    :
---------------------------------------------------------------------------*/
void dxl_hw_tx_enable(void)
{
  drv_dxl_tx_enable(TRUE);
}


/*---------------------------------------------------------------------------
     TITLE   : dxl_hw_tx_disable
     WORK    :
---------------------------------------------------------------------------*/
void dxl_hw_tx_disable(void)
{
  drv_dxl_tx_enable(FALSE);
}


/*---------------------------------------------------------------------------
     TITLE   : dxl_hw_power_enable
     WORK    :
---------------------------------------------------------------------------*/
void dxl_hw_power_enable(void)
{
  digitalWrite(BDPIN_DXL_PWR_EN, HIGH);
}


/*---------------------------------------------------------------------------
     TITLE   : dxl_hw_power_enable
     WORK    :
---------------------------------------------------------------------------*/
void dxl_hw_power_disable(void)
{
  digitalWrite(BDPIN_DXL_PWR_EN, LOW);
}


/*---------------------------------------------------------------------------
     TITLE   : dxl_hw_read
     WORK    :
---------------------------------------------------------------------------*/
uint8_t dxl_hw_read(void)
{
  return DXL_PORT.read();
}


/*---------------------------------------------------------------------------
     TITLE   : dxl_hw_write
     WORK    :
---------------------------------------------------------------------------*/
void dxl_hw_write(uint8_t value)
{
	DXL_PORT.write(value);
}


/*---------------------------------------------------------------------------
     TITLE   : dxl_hw_available
     WORK    :
---------------------------------------------------------------------------*/
uint32_t dxl_hw_available(void)
{
  return DXL_PORT.available();
}
