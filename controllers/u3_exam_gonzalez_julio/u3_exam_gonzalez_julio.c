/*
 * File:          u3_exam_gonzalez_julio.c
 * Date:
 * Description:
 * Author:
 * Modifications:
 */

#include <webots/robot.h>
#include <webots/motor.h>
#include <webots/keyboard.h>
#include <webots/position_sensor.h>
#include <webots/distance_sensor.h>

#include <stdio.h>

#define TIME_STEP 64
//#define pi 3.1416

 
double sn; 
double sn2; 
double dis;
double dis2; 
double encoder; 
int paraR, paraL = 0;
float Comparador = 0;
 
int main(int argc, char **argv)
{
 
  wb_robot_init();
 
  double vel = 2.0;


     WbDeviceTag wheel1 = wb_robot_get_device("Wheel_1");
     WbDeviceTag wheel2 = wb_robot_get_device("Wheel_2");
     WbDeviceTag wheel3 = wb_robot_get_device("Wheel_3");
     
     WbDeviceTag sen1= wb_robot_get_device("sen_1");
     WbDeviceTag sen2 = wb_robot_get_device("sen_2");
     
     wb_distance_sensor_enable(sen1,TIME_STEP);
     wb_distance_sensor_enable(sen2,TIME_STEP);
     
     WbDeviceTag enco_1 = wb_robot_get_device("encoder_1");
     WbDeviceTag enco_2 = wb_robot_get_device("encoder_2");
     WbDeviceTag enco_3 = wb_robot_get_device("encoder_3");
     
     wb_position_sensor_enable(enco_1, TIME_STEP);
     wb_position_sensor_enable(enco_2, TIME_STEP);
     wb_position_sensor_enable(enco_3, TIME_STEP);
     
        
   
  while (wb_robot_step(TIME_STEP) != -1) {
   
    
       wb_motor_set_position(wheel1, INFINITY);
       wb_motor_set_velocity(wheel1, 0);
       wb_motor_set_position(wheel2, INFINITY);
       wb_motor_set_velocity(wheel2, -vel);
       wb_motor_set_position(wheel3, INFINITY);
       wb_motor_set_velocity(wheel3, vel);
     
     sn = wb_distance_sensor_get_value(sen1);
     dis = (sn*0.2)/65535;
     
     sn2 = wb_distance_sensor_get_value(sen2);
     dis2 = (sn2*0.2)/65535;
     
     encoder = wb_position_sensor_get_value(enco_3);
     
     if((dis <= 0.17 && dis>dis2) && paraR == 0){
       Comparador = encoder + (2.35619); //.75 = 45 degrees to the left
       paraR = 1;
     }

     if(paraR == 1){

     if(encoder <= Comparador){
       wb_motor_set_velocity(wheel1, 5);
       wb_motor_set_velocity(wheel2, 5);
       wb_motor_set_velocity(wheel3, 5);
     }
     else{
       wb_motor_set_velocity(wheel1, 0);
       wb_motor_set_velocity(wheel2, 0);
       wb_motor_set_velocity(wheel3, 0);
       paraR = 0;
     }       
     }

     if((dis2 <= 0.17 && dis<dis2) && paraL == 0){
       Comparador = encoder - (2.35619); //.75 = 45 degrees to the left
       paraL = 1;
     }

     if(paraL == 1){

     if(encoder >= Comparador){
       wb_motor_set_velocity(wheel1, -5);
       wb_motor_set_velocity(wheel2, -5);
       wb_motor_set_velocity(wheel3, -5);
     }
     else{
       wb_motor_set_velocity(wheel1, 0);
       wb_motor_set_velocity(wheel2, 0);
       wb_motor_set_velocity(wheel3, 0);
       paraL = 0;
     }   
     
     }     
    
    
     printf("sensor: %f\n", dis);
     printf("sensor2: %f\n", dis2);
     printf("Encoder: %f\n", encoder);
     printf("flag: %f\n", Comparador);
     
     
  };

  wb_robot_cleanup();

  return 0;
}
