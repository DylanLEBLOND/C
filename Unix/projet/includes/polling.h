/*
 * polling.h
 *
 * Copyright 2016/09 Michel Soto
 *
 */
#ifndef EXIT_H

    #define EXIT_H

    #include <unistd.h>
    #include <stdlib.h>

#endif

#define EVER (;;)
#define MAX_ST         5 // Nombre maximal de station

#define POLL_RX         SIGUSR1 // Arrivé d'une invitation à émettre des données
#define POLL_TX         SIGUSR1 // Envoi d'une invitation à émettre des données
#define DATA_RX         SIGUSR2 // Réception de données
#define DATA_TX         SIGUSR2 // Emission de données
#define ACK_RX          SIGPIPE // Réception acquittement de données émises
#define ACK_TX          SIGPIPE // Envoi acquittement de données émises
#define DATA_REQ_RX     SIGALRM // Arrivée d'une requête d'émission de données
#define DATA_REQ_TX     SIGALRM // Envoi d'une requête d'émission de données

// Valeur numériques associées aux états de automates
#define IDLE    1 // Aucune données à diffuser
#define W_REQ   2 // WAIT_REQUEST: Attente d'une demande d'émission
                  // de données de la part de la station i
#define W_POLL  3 // WAIT_POLL: Attente d'une invitation à émettre
                  // des données de la part de la station primaire
#define W_ACK   4 // WAIT_ACK: Attente d'un accquittement de données
                  // de la part de la station primaire
#define BC_DATA 5 // BROADCASTING_DATA: Diffusion de données
#define SD_DATA 6 // SENDING_DATA: Envoi d'une donnée
#define G_REQ   7 // GENERATING_REQUEST: Génération d'un requête
                  // d'envoi de donnée

// Chaînes de caractères associées aux états de automates
char *string_idle    = "IDLE";
char *string_g_req   = "G_REQ";
char *string_w_req   = "W_REQ";
char *string_w_ack   = "W_ACK";
char *string_w_poll  = "W_POLL";
char *string_bc_data = "BC_DATA";
char *string_sd_data = "SD_DATA";


// -----------------------------------------------------
    void erreur (char *message) {
// -----------------------------------------------------
    perror(message);
    exit (EXIT_FAILURE);
} // erreur
