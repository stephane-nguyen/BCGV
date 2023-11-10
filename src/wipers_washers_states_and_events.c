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

/* États pour la machine à états des essuie-glaces et lave-glace */
typedef enum {
    INIT = -1;
    EG_LG_ALL_OFF,          // Tout éteints
    EG_ACTIVE,              // Essuie-glaces activés
    EG_LG_ACTIVE,           // Lave-glace et essuie-glaces activés
    EG_TIMER_LG_OFF,        // Timer essuie-glaces actif et lave-glace éteint
} eg_lg_state_t;

/* Événements pour la machine à états des essuie-glaces et lave-glace */
typedef enum {
    EG_LG_NONE,             // Aucun événement
    EG_LG_CMD_EG_0,         // Commande essuie-glaces = 0
    EG_LG_CMD_EG_1,         // Commande essuie-glaces = 1
    EG_LG_CMD_LG_0,         // Commande lave-glace = 0
    EG_LG_CMD_LG_1,         // Commande lave-glace = 1
    EG_LG_TIMER_EXPIRED,    // Le timer est expiré
} eg_lg_event_t;



// /* Callback functions called on transitions */
// static int callback1 (void) { ... };
// static int callback2 (void) { ... };
// static int callback3 (void) { ... };
// static int FsmError(void) { ... };

// /* Transition structure */
// typedef struct {
//     fsm_state_t state;
//     fsm_event_t event;
//     int (*callback)(void);
//     int next_state;
// } tTransition;


/* Table de transition pour les essuie-glaces et lave-glace */
tTransition eg_lg_trans[] = {
    { INIT, NONE, NULL, EG_LG_ALL_OFF },
    { EG_LG_ALL_OFF, EG_LG_CMD_EG_1, callbackActivateWipers, EG_ACTIVE },
    { EG_LG_ALL_OFF, EG_LG_CMD_LG_1, callbackActivateWashers, EG_LG_ACTIVE },
    { EG_ACTIVE, EG_LG_CMD_EG_0, callbackDeactivateWipers, EG_LG_ALL_OFF },
    { EG_ACTIVE, EG_LG_CMD_LG_1, callbackActivateWashers, EG_LG_ACTIVE },
    { EG_LG_ACTIVE, EG_LG_CMD_LG_0, callbackDeactivateWashers, EG_TIMER_LG_OFF },
    { EG_LG_ACTIVE, LG_CMD_LG_1, callbackDeactivateWashers, EG_TIMER_LG_OFF },
    { EG_TIMER_LG_OFF, EG_LG_TIMER_EXPIRED, callbackDeactivateWipers, EG_LG_ALL_OFF },
    { EG_TIMER_LG_OFF, EG_LG_CMD_EG_0, callbackDeactivateWipers, EG_LG_ALL_OFF },
    { EG_TIMER_LG_OFF, EG_LG_CMD_LG_1, callbackReactivateWashers, EG_LG_ACTIVE },
};



#define TRANS_COUNT (sizeof(trans)/sizeof(*trans))

// On suppose que vous ayez les fonctions suivantes pour obtenir l'état actuel des commandes
int get_eg_command_signal(); // Renvoie la commande pour les essuie-glaces
int get_lg_command_signal(); // Renvoie la commande pour le lave-glace
bool timer_expired(); // Renvoie vrai si le timer est expiré

int get_next_event(int current_state) {
    int event = EG_LG_NONE;

    int eg_command = get_eg_command_signal();
    int lg_command = get_lg_command_signal();
    bool timer_done = timer_expired();

    switch(current_state) {
        case EG_LG_ALL_OFF:
            if (eg_command == 1 && lg_command == 0) {
                event = EG_LG_CMD_EG_1;
            } else if (lg_command == 1) {
                event = EG_LG_CMD_LG_1;
            }
            break;
        case EG_ACTIVE:
            if (eg_command == 0) {
                event = EG_LG_CMD_EG_0;
            } else if (lg_command == 1) {
                event = EG_LG_CMD_LG_1;
            }
            break;
        case EG_LG_ACTIVE:
            if (lg_command == 0) {
                event = EG_LG_CMD_LG_0;
            }
            break;
        case EG_TIMER_LG_OFF:
            if (timer_done && lg_command == 0) {
                event = EG_LG_TIMER_EXPIRED;
            } else if (lg_command == 1) {
                event = EG_LG_CMD_LG_1;
            }
            break;
        default:
            event = EG_LG_ERR;
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
