/*
 * File:          u3_exam_gonzalez_julio.c
 * Date:
 * Description:
 * Author:
 * Modifications:
 */

/*
 * You may need to add include files like <webots/distance_sensor.h> or
 * <webots/differential_wheels.h>, etc.
 */
#include <webots/robot.h>
#include <webots/motor.h>
#include <webots/keyboard.h>
//#include <webots/position_sensor.h>
//#include <webots/distance_sensor.h>

#include <stdio.h>

/*
 * You may want to add macros here.
 */
#define TIME_STEP 64
//#define pi 3.1416

/*
 * This is the main program.
 * The arguments of the main function can be specified by the
 * "controllerArgs" field of the Robot node
 */
int main(int argc, char **argv)
{
  /* necessary to initialize webots stuff */
  wb_robot_init();
  wb_keyboard_enable(TIME_STEP);
  
  double vel = 0;

  /*
   * You should declare here WbDeviceTag variables for storing
   * robot devices like this:
   *  WbDeviceTag my_sensor = wb_robot_get_device("my_sensor");
   *  WbDeviceTag my_actuator = wb_robot_get_device("my_actuator");
   */

     WbDeviceTag wheel1 = wb_robot_get_device("Wheel_1");
     WbDeviceTag wheel2 = wb_robot_get_device("Wheel_2");
     WbDeviceTag wheel3 = wb_robot_get_device("Wheel_3");
   
  /* main loop
   * Perform simulation steps of TIME_STEP milliseconds
   * and leave the loop when the simulation is over
   */
   
     wb_motor_set_position(wheel1, INFINITY);
     wb_motor_set_velocity(wheel1, vel);   
     wb_motor_set_position(wheel2, INFINITY);
     wb_motor_set_velocity(wheel2, vel);
     wb_motor_set_position(wheel3, INFINITY);
     wb_motor_set_velocity(wheel3, vel);
   
   
  while (wb_robot_step(TIME_STEP) != -1) {


     int key = wb_keyboard_get_key(); 
     int stop; 
    /*
     * Read the sensors :
     * Enter here functions to read sensor data, like:
     *  double val = wb_distance_sensor_get_value(my_sensor);
     */
     if (key==WB_KEYBOARD_UP){
     
         stop=key; 
         vel = 2.0; 
    
         wb_motor_set_position(wheel1, INFINITY);
         wb_motor_set_velocity(wheel1, 0);
         wb_motor_set_position(wheel2, INFINITY);
         wb_motor_set_velocity(wheel2, vel);
         wb_motor_set_position(wheel3, INFINITY);
         wb_motor_set_velocity(wheel3, -vel);
     }
     
     if (stop != key){
      
         wb_motor_set_position(wheel1, INFINITY);
         wb_motor_set_velocity(wheel1, 0);
         wb_motor_set_position(wheel2, INFINITY);
         wb_motor_set_velocity(wheel2, 0);
         wb_motor_set_position(wheel3, INFINITY);
         wb_motor_set_velocity(wheel3, 0);
     }  
     
     if (key==WB_KEYBOARD_DOWN){
     
         vel = 2.0; 
           
         wb_motor_set_position(wheel1, INFINITY);
         wb_motor_set_velocity(wheel1, 0);
         wb_motor_set_position(wheel2, INFINITY);
         wb_motor_set_velocity(wheel2, -vel);
         wb_motor_set_position(wheel3, INFINITY);
         wb_motor_set_velocity(wheel3, vel);
     }
     /*
     if (key==WB_KEYBOARD_LEFT){
     
         vel= 80; 
     
         wb_motor_set_position(wheel1, INFINITY);
         wb_motor_set_velocity(wheel1, vel);
         wb_motor_set_position(wheel2, INFINITY);
         wb_motor_set_velocity(wheel2, vel);
         wb_motor_set_position(wheel3, INFINITY);
         wb_motor_set_velocity(wheel3, 0);
     }
     
     if (key==WB_KEYBOARD_RIGHT){
     
         vel= 80; 
     
         wb_motor_set_position(wheel1, INFINITY);
         wb_motor_set_velocity(wheel1, -vel);
         wb_motor_set_position(wheel2, INFINITY);
         wb_motor_set_velocity(wheel2, 0);
         wb_motor_set_position(wheel3, INFINITY);
         wb_motor_set_velocity(wheel3, -vel);
     }
     */
     if (key==WB_KEYBOARD_PAGEUP){
     
         vel= 2.0; 
     
         wb_motor_set_position(wheel1, INFINITY);
         wb_motor_set_velocity(wheel1, -vel);
         wb_motor_set_position(wheel2, INFINITY);
         wb_motor_set_velocity(wheel2, -vel);
         wb_motor_set_position(wheel3, INFINITY);
         wb_motor_set_velocity(wheel3, 0);
     }
     
     if (key==WB_KEYBOARD_PAGEDOWN){
     
         vel= 2.0; 
     
         wb_motor_set_position(wheel1, INFINITY);
         wb_motor_set_velocity(wheel1, vel);
         wb_motor_set_position(wheel2, INFINITY);
         wb_motor_set_velocity(wheel2, 0);
         wb_motor_set_position(wheel3, INFINITY);
         wb_motor_set_velocity(wheel3, vel);
     }
     
     if (key==WB_KEYBOARD_LEFT){
     
         vel= 2.0; 
     
         wb_motor_set_position(wheel1, INFINITY);
         wb_motor_set_velocity(wheel1, vel);
         wb_motor_set_position(wheel2, INFINITY);
         wb_motor_set_velocity(wheel2, -vel);
         wb_motor_set_position(wheel3, INFINITY);
         wb_motor_set_velocity(wheel3, -vel);
     }
     
     if (key==WB_KEYBOARD_RIGHT){
     
         vel= 2.0; 
     
         wb_motor_set_position(wheel1, INFINITY);
         wb_motor_set_velocity(wheel1, -vel);
         wb_motor_set_position(wheel2, INFINITY);
         wb_motor_set_velocity(wheel2, vel);
         wb_motor_set_position(wheel3, INFINITY);
         wb_motor_set_velocity(wheel3, vel);
     }

    /* Process sensor data here */

    /*
     * Enter here functions to send actuator commands, like:
     * wb_differential_wheels_set_speed(100.0,100.0);
     */
  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}
