from machine import Pin, PWM, ADC
import time


### Input pins
# seq_trig = Pin(10, Pin.IN)
# ring_only = Pin(9, Pin.IN)
ext_trigger = Pin(9, Pin.IN, Pin.PULL_UP)
light_mode = Pin(10, Pin.IN, Pin.PULL_UP)



### Output pins
led1 = Pin(1, Pin.OUT)
led2 = Pin(2, Pin.OUT)
led3 = Pin(3, Pin.OUT)
led4 = Pin(4, Pin.OUT)
led5 = Pin(5, Pin.OUT)
led6 = Pin(6, Pin.OUT)
led7 = Pin(7, Pin.OUT)
led8 = Pin(8, Pin.OUT)

cam = Pin(11, Pin.OUT)



### Potentiometer
potentiometer = ADC(Pin(26))


### Configuring the LEDs
leds_pwm = [PWM(led1),
            PWM(led2),
            PWM(led3),
            PWM(led4),
            PWM(led5),
            PWM(led6),
            PWM(led7),
            PWM(led8)]

for i in range(len(leds_pwm)):
    leds_pwm[i].freq(1000) # set frequencies
    leds_pwm[i].duty_u16(0)



### While loop
while True:
    
    # MLIC sequence mode
    # If Mode switch is set to "I"
    if light_mode.value() == 0:
        
        # Turn off all lights before starting a sequence
        for i in range(len(leds_pwm)):
            leds_pwm[i].duty_u16(0)
        
        
        if ext_trigger.value() == 0:
            print("Trigger pressed")
             
            # Loop through the LEDs
            for i in range(len(leds_pwm)):
                
                # Exit option for when Light Mode is switched to Ringlight
                if light_mode.value() == 1:
                    break
                else:
                    pass
                
                # Get the desired intensity from the Potentiometer
                # The PWM duty values range between 0 and 65535
                pot_val = potentiometer.read_u16()/65535
                on_value = int(pot_val * 65535)
                print(pot_val * 100, "%")
                
                # Turn on the LED
                leds_pwm[i].duty_u16(on_value)
                # time.sleep(1)
                
                # Trigger the camera
                cam.value(1)
                time.sleep(0.5)
                cam.value(0)
                time.sleep(2)
                # Turn off the LED
                leds_pwm[i].duty_u16(0)
                time.sleep(1)
        
            print("Finished one MLIC sequence")
        else:
            pass
    
    
    # Ringlight mode
    else:
        pot_val = potentiometer.read_u16()/65535
        on_value = int(pot_val * 65535)
        for i in range(len(leds_pwm)):
            leds_pwm[i].duty_u16(on_value)
        time.sleep(0.5)

        
        
    
    

# while True:
#     if seq_trig.value() == 1:
#         print("start")
#         time.sleep(0.5)
















