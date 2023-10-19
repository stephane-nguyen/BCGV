#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "../headers/utils.h"

typedef enum {
    INIT = -1,
    TURNED_OFF,
    TURNED_ON,
    ERROR,
    ACQUITTED
} classic_light_state_t;

typedef enum {
    NONE,
    COMMAND_ZERO=0,
    COMMAND_ONE=1,
    ACQUITTED_RECEIVED,
    ACQUITTED_NOT_RECEIVED, /* event error */
} classic_light_event_t;

typedef struct {
    classic_light_state_t state;
    classic_light_event_t event;
    int (*callback)(void);
    int next_state;
} classic_light_transition_table;

classic_light_transition_table trans[] = {
    { INIT, NONE, NULL, TURNED_OFF},
    { TURNED_OFF, COMMAND_ONE, NULL, TURNED_ON},
    { TURNED_ON, COMMAND_ZERO, NULL, TURNED_OFF},
    { TURNED_ON, ACQUITTED_NOT_RECEIVED, NULL, ERROR},
    { TURNED_ON, ACQUITTED, NULL, ACQUITTED},
    { ACQUITTED, COMMAND_ZERO, NULL, TURNED_OFF}
};

#define TRANS_COUNT (sizeof(trans)/sizeof(*trans))

int get_next_event(int current_state)
{
    int event = NONE;

    /* Here, you can get the parameters of your FSM */

    /* Build all the events */

    /* Example code : 
    if (PARAM1 == ...) {
        event = EV_EVENT1
    }
    else if (PARAM2 == ... && PARAM3 == ...) {
        event = EV_EVENT2
    }
    ...
    */
    return event;
}

int main(void)
{


    state_t washer_state;
    state_t wiper_state;
    state_t light_state;
    state_t activated_state;




    int i = 0;
    int ret = 0; 
    int event = EV_NONE;
    int state = ST_INIT;
    
    /* While FSM hasn't reach end state */
    while (state != ST_TERM) {
        
        /* Get event */
        event = get_next_event(state);
        
        /* For each transitions */
        for (i = 0; i < TRANS_COUNT; i++) {
            /* If State is current state OR The transition applies to all states ...*/
            if ((state == trans[i].state) || (ST_ANY == trans[i].state)) {
                /* If event is the transition event OR the event applies to all */
                if ((event == trans[i].event) || (EV_ANY == trans[i].event)) {
                    /* Apply the new state */
                    state = trans[i].next_state;
                    if (trans[i].callback != NULL) {
                        /* Call the state function */
                        ret = (trans[i].callback)();
                    }
                    break;
                }
            }
        }
    }

    return ret;
}
