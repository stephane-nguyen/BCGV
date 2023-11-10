// #include <stdlib.h>
// #include <stdio.h>
// #include <stdint.h>

// #include "../headers/utils.h"

// typedef enum {
//     INIT = -1,
//     ALL_TURNED_OFF,
//     WIPER_ACTIVATED,
//     ALL_ACTIVATED,
//     TIMERS_TURNED_OFF
// } wiper_washer_state_t;

// typedef enum {
//     NONE,
//     COMMAND_ZERO_WIPER,
//     COMMAND_ZERO_WASHER,
//     COMMAND_ONE_WIPER,
//     COMMAND_ONE_WASHER,
//     COMMAND_ZERO_WIPER_WASHER,
//     COMMAND_ONE_WIPER_WASHER,
//     TIME_INFERIOR_TO_2,
//     TIME_SUPERIOR_TO_2
// } wiper_washer_event_t;

// typedef struct {
//     wiper_washer_state_t state;
//     wiper_washer_event_t event;
//     int (*callback)(void);
//     int next_state;
// } wiper_washer_transition_table;

// wiper_washer_transition_table wiper_washer_trans[] = {
//     { INIT, NONE, NULL, ALL_TURNED_OFF},
//     { ALL_TURNED_OFF, COMMAND_ZERO_WIPER_WASHER, NULL, ALL_TURNED_OFF},
//     { ALL_TURNED_OFF, COMMAND_ONE_WIPER, NULL, WIPER_ACTIVATED},
//     { ALL_TURNED_OFF, COMMAND_ONE_WASHER, NULL, ALL_ACTIVATED},
//     { WIPER_ACTIVATED, COMMAND_ONE_WASHER, NULL, ALL_ACTIVATED},
//     { ALL_ACTIVATED, COMMAND_ONE_WASHER, NULL, ALL_ACTIVATED},
//     { ALL_ACTIVATED, COMMAND_ZERO_WIPER, NULL, TURNED_OFF}
// };

// #define TRANS_COUNT (sizeof(trans)/sizeof(*trans))

// int get_next_event(int current_state)
// {
//     int event = NONE;

//     /* Here, you can get the parameters of your FSM */

//     /* Build all the events */

//     /* Example code : 
//     if (PARAM1 == ...) {
//         event = EV_EVENT1
//     }
//     else if (PARAM2 == ... && PARAM3 == ...) {
//         event = EV_EVENT2
//     }
//     ...
//     */
//     return event;
// }

// int main(void)
// {


//     state_t washer_state;
//     state_t wiper_state;
//     state_t light_state;
//     state_t activated_state;




//     int i = 0;
//     int ret = 0; 
//     int event = EV_NONE;
//     int state = ST_INIT;
    
//     /* While FSM hasn't reach end state */
//     while (state != ST_TERM) {
        
//         /* Get event */
//         event = get_next_event(state);
        
//         /* For each transitions */
//         for (i = 0; i < TRANS_COUNT; i++) {
//             /* If State is current state OR The transition applies to all states ...*/
//             if ((state == trans[i].state) || (ST_ANY == trans[i].state)) {
//                 /* If event is the transition event OR the event applies to all */
//                 if ((event == trans[i].event) || (EV_ANY == trans[i].event)) {
//                     /* Apply the new state */
//                     state = trans[i].next_state;
//                     if (trans[i].callback != NULL) {
//                         /* Call the state function */
//                         ret = (trans[i].callback)();
//                     }
//                     break;
//                 }
//             }
//         }
//     }

//     return ret;
// }
