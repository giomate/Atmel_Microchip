/* 
* SerialTerminal_Class.cpp
*
* Created: 7/23/2020 6:43:18 PM
* Author: GMateusDP
*/


#include "SerialTerminal_Class.h"
#include "TimerSerial_Class.h"
#include "CDC_Class.h"

SerialTerminal_Class	*ptrSerialTerminalClass;

static void	USBTimeoutTask(const struct timer_task *const timer_task){
	ptrSerialTerminalClass->timeout=true;
	ptrSerialTerminalClass->plugged=false;
}

static void USBPlugged(void){
	if (gpio_get_pin_level(PIN_PA14))
	{
		ptrSerialTerminalClass->plugged=true;
	} 
	else
	{
		ptrSerialTerminalClass->plugged=false;
		ptrSerialTerminalClass->connected=false;
	}
	
}


// default constructor
SerialTerminal_Class::SerialTerminal_Class()
{
	ptrSerialTerminalClass=this;
	
} //SerialTerminal_Class

// default destructor
SerialTerminal_Class::~SerialTerminal_Class()
{
} //~SerialTerminal_Class

void	SerialTerminal_Class::OnInit(void){
		ext_irq_register(PIN_PA14, USBPlugged);
		if (usbTerminalTimer.Init())
		{
		//	usbTerminalTimer.Start_periodic_task((FUNC_PTR)USBTimerTicks,1);
		}
		vbusDetected=gpio_get_pin_level(PIN_PA14);
		if (vbusDetected)
		{
			timeout=false;
			plugged=true;
			usbTerminalTimer.Start_oneShot_task((FUNC_PTR)USBTimeoutTask,USB_TIMEOUT*60);
		
			//while ((!usb.IsEnabled())||(!plugged)){
			while ((!usb.IsEnabled())){
				if (timeout)
				{
					connected=false;
					return;
				}
				else
				{
				}
			}
			
			usbTerminalTimer.Stop();
		} 
		else
		{
			connected=false;
			plugged=false;
		}
		
}
void	SerialTerminal_Class::OnPlugged(void){
	usbTerminalTimer.Stop();
	usbTerminalTimer.Remove_task();
	usbTerminalTimer.Start_oneShot_task((FUNC_PTR)USBTimeoutTask,USB_TIMEOUT*40);

	while (!connected){
		if (timeout)
		{
			connected=false;
			plugged=false;
			return;
		}
		else
		{
		}
	}
	usbTerminalTimer.Stop();
	
}
bool	SerialTerminal_Class::CheckTerminal(void){
	if (plugged)
	{
		if (connected||usb.IsEnabled())
		{
			plugged=usbTerminalTimer.Start()==0;
		}
		else
		{
			plugged=false;
		}
	}
	else
	{
		return	plugged;
	}
	
	return	plugged;
}
bool	SerialTerminal_Class::CheckTerminal(uint32_t size){
	if (plugged)
	{
		if (connected||usb.IsEnabled())
		{
			usbTerminalTimer.Stop();
			usbTerminalTimer.Remove_task((FUNC_PTR)USBTimeoutTask);
			plugged=usbTerminalTimer.Start_oneShot_task((FUNC_PTR)USBTimeoutTask,USB_TIMEOUT*size)==0;
			
		}
		else
		{
			plugged=false;
		}
	}
	else
	{
		return	plugged;
	}
	
	return	plugged;
}