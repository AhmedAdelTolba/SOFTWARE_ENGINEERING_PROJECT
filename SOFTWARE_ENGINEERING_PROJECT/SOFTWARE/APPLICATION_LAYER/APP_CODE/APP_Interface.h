/*
 * APP.h
 *
 *  Created on: Mar 26, 2016
 *      Author: Ahmed
 */

#ifndef SOFTWARE_APPLICATION_LAYER_APP_CODE_APP_INTERFACE_H_
#define SOFTWARE_APPLICATION_LAYER_APP_CODE_APP_INTERFACE_H_

/*Comment!: States of State Machine  */

#define APP_TIMER              0

#define APP_STOP_WATCH_STANDBY 1

#define APP_STOP_WATCH         2

#define APP_EDIT_TIME          3

#define APP_STOP_WATCH_PAUSE   4

#define APP_RESUME_STAND_BY   5

    /*Comment!: initialize all MCAL and HAL modules   */
extern void APP_voidInit(void);

/*Comment!: special function to implement APP_u8Timer state  */
extern u8 APP_u8Timer(void);

/*Comment!: special function to implement APP_u8APP_STOP_WATCH_STANDBY state  */
extern u8 APP_u8APP_STOP_WATCH_STANDBY(void);

/*Comment!: special function to implement APP_u8APP_STOP_WATCH state  */
extern u8 APP_u8APP_STOP_WATCH(void);

/*Comment!: special function to implement APP_u8APP_STOP_WATCH_PAUSE state  */
extern u8 APP_u8APP_STOP_WATCH_PAUSE(void);

/*Comment!: special function to implement APP_u8APP_RESUME_STAND_BY state  */
extern u8 APP_u8APP_RESUME_STAND_BY(void);

/*Comment!: special function to implement APP_u8APP_EDIT_TIME state  */
extern u8 APP_u8APP_EDIT_TIME(void);

#endif /* SOFTWARE_APPLICATION_LAYER_APP_CODE_APP_INTERFACE_H_ */
