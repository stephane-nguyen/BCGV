/**
 * \file        fsm.c
 * \author      Alexis Daley
 * \version     0.4
 * \date        08 otober 2023
 * \brief       This is a template file to create a Finite State Machine.
 * \details
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/* States */
typedef enum {
    INIT,
    TURNED_OFF,
    TURNED_ON,
    ERROR,
    ACQUITTED,
    ACTIVATED_AND_TURNED_OFF,
    ACTIVATED_AND_TURNED_ON
} warning_lights_state_t;


/* Events */
typedef enum {
    NONE,
    COMMAND_ZERO,
    COMMAND_ONE,
    ACQUITTED_RECEIVED,
    ACQUITTED_NOT_RECEIVED, /* event error */
} warning_lights_event_t;

// define tTransition
typedef struct {
    warning_lights_state_t state;
    warning_lights_event_t event;
    int (*callback)(void);
    warning_lights_state_t next_state;
} tTransition;


/* Transition table */
tTransition trans[] = {
    { TURNED_OFF, COMMAND_ONE, NULL, ACTIVATED_AND_TURNED_ON },
    { ACTIVATED_AND_TURNED_ON, ACQUITTED_NOT_RECEIVED, NULL, ERROR },
    { ERROR, ACQUITTED_RECEIVED, NULL, ACTIVATED_AND_TURNED_OFF },
    { ACTIVATED_AND_TURNED_OFF, COMMAND_ZERO, NULL, TURNED_OFF },
    { ACTIVATED_AND_TURNED_OFF, COMMAND_ONE, NULL, ACTIVATED_AND_TURNED_ON },
    { TURNED_ON, COMMAND_ZERO, NULL, ACTIVATED_AND_TURNED_OFF },
    { ACTIVATED_AND_TURNED_ON, COMMAND_ZERO, NULL, TURNED_ON },
    { ERROR, COMMAND_ZERO, NULL, TURNED_ON },
    { TURNED_ON, COMMAND_ONE, NULL, ACTIVATED_AND_TURNED_ON },
    { TURNED_OFF, COMMAND_ZERO, NULL, TURNED_OFF } /* Assumption: State remains the same if the same command is received */
};


#define TRANS_COUNT (sizeof(trans)/sizeof(*trans))

int get_next_event(warning_lights_state_t current_state)
{
    // Build all the events based on the current state and the input parameters
    switch(current_state) {
        case TURNED_OFF:
            // get next state from the tTransition table
            warning_lights_state_t nextState 

            break;
        case TURNED_ON:
            break;
        case ACTIVATED_AND_TURNED_ON:
            break;
        case ACTIVATED_AND_TURNED_OFF:

            break;
        case ERROR:
            break;
        default:
            break;
    }
    return event;
}


int main(void)
{
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
