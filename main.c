/*
 * File:   main.c
 * Author: Abdoulaye Doumbouya
 *
 * Created on April 7, 2024, 6:51 PM
 */
#include "head.h"
#include "I2C.h"
#include <stdio.h>

#define TRIGGER_PIN     RD1
#define ECHO_PIN        RD0
#define LED_PIN         RA0
#define LED_ON          1
#define LED_OFF         0
#define TRIGGER_DELAY   10
#define DIST_THRESHOLD  5
#define PWM_PERIOD      255
#define PWM_DUTY_50     128
#define PWM_DUTY_25     64
#define BRIGHTNESS_MAX  100

#define GREEN_LED       LATAbits.LATA2
#define YELLOW_LED      LATAbits.LATA1
#define RED_LED         LATAbits.LATA0
#define LED_ON          1
#define LED_OFF         0



unsigned int distance_Calc(void)
{
    unsigned int distance = 0;
    TMR1 = 0;
    TRIGGER_PIN = 1; // Send Trigger Pulse To The Sensor
    __delay_us(TRIGGER_DELAY);
    TRIGGER_PIN = 0;
    while(!ECHO_PIN); // Wait For The Echo Pulse From The Sensor
    T1CONbits.TMR1ON = 1; // Turn ON Timer Module
    while(ECHO_PIN); // Wait Until The Pulse Ends
    T1CONbits.TMR1ON = 0; // Turn OFF The Timer
    distance = (TMR1) / 58.82; // Calculate The Distance Using The Equation
    TMR1H = 0; // Timer 1 Register High byte
    TMR1L = 0; // Timer 1 Register Low byte
    return distance;
}


void main(void) 
{
    I2C__Init();
    LCD_Init(0X4E);
    LCD_Clear();
    LCD_Set_Cursor(1,1);
    LCD_Write_String("Distance: ");

    TRISCbits.RC2 = 0; // Configure RC2 as output for LED
    TRISDbits.RD1 = 0; // Configure RD1 as output for trigger
    TRISDbits.RD0 = 1; // Configure RD0 as input for echo
    TRISDbits.RD2 = 0; // Configure RD0 as input for echo
    
    TRISAbits.RA2 = 0; // Set RA2 as output for green LEDs
    TRISAbits.RA1 = 0; // Set RA1 as output for yellow LEDs
    TRISAbits.RA0 = 0; // Set RA0 as output for red LEDs

    
    
    

    // PWM Configuration
    PR2 = PWM_PERIOD; // Set the period register
    CCP1CONbits.CCP1M3 = 1; // Set the CCP1CON register for PWM mode
    CCP1CONbits.CCP1M2 = 1;
    CCP1CONbits.CCP1M1 = 0;
    CCP1CONbits.CCP1M0 = 0;
    T2CONbits.T2CKPS0 = 0; // Set the T2CON register for 1:1 prescaler and start Timer2
    T2CONbits.T2CKPS1 = 0;
    T2CONbits.TMR2ON = 1;

    // Set the initial duty cycle to 50%
    CCPR1L = PWM_DUTY_50;

    while(1)
    {
        unsigned int dist = distance_Calc();
     
       
       //PORTAbits.RA0 = 1;
       
        
        CCPR1L = ((dist*(10)) * PWM_PERIOD) / BRIGHTNESS_MAX;
        // Convert the distance to a string
        char dist_str[16];
        sprintf(dist_str, "%d cm ", dist);

        // Display the distance on the LCD
        LCD_Set_Cursor(2,1);
        LCD_Write_String(dist_str);
    
        if (dist < DIST_THRESHOLD)
        {
            // If too close, turn on red LED and turn off green and yellow LEDs
            RED_LED = LED_ON;
            YELLOW_LED = LED_OFF;
            GREEN_LED = LED_OFF;
        }
        else if (dist < 2 * DIST_THRESHOLD)
        {
            // If close, turn on yellow LED and turn off red and green LEDs
            YELLOW_LED = LED_ON;
            RED_LED = LED_OFF;
            GREEN_LED = LED_OFF;
        }
        else
        {
            // If not too close, turn on green LED and turn off red and yellow LEDs
            GREEN_LED = LED_ON;
            RED_LED = LED_OFF;
            YELLOW_LED = LED_OFF;
        }
        
}

}
FooterIndiana University
