/*
 * params.h
 *
 *  Created on: 5 Mar 2020
 *      Author: hinchr
 */

#ifndef PARAMS_H_
#define PARAMS_H_

#include "constant.h"
#include "structure.h"

/************************************************************************/
/****************************** Structures  *****************************/
/************************************************************************/

typedef struct{
	long rng_seed; 					// number used to seed the GSL RNG
	char input_param_file[INPUT_CHAR_LEN];	// path to input parameter file
    char hospital_input_param_file[INPUT_CHAR_LEN];	// path to input parameter file
	char input_household_file[INPUT_CHAR_LEN]; //path to input household demographics file
	char output_file_dir[INPUT_CHAR_LEN];	// path to output directory
	int param_line_number;			// line number to be read from parameter file
    int hospital_param_line_number;			// line number to be read from parameter file
	long param_id;					// id of the parameter set
	long n_total;  					// total number of people
	int days_of_interactions;		// the number of days of interactions to keep
	int end_time;				    // maximum end time
	int n_seed_infection;			// number of people seeded with the infections

	double mean_random_interactions[N_AGE_TYPES]; // mean number of random interactions each day
	double sd_random_interactions[N_AGE_TYPES];   // sd number of random interactions each day
	int random_interaction_distribution;          // distribution from which each person random interactions are drawn
	double mean_work_interactions[N_WORK_NETWORKS];// mean number of regular work interactions
	double daily_fraction_work;      			// fraction of daily work interactions without social-distancing
	double daily_fraction_work_used[N_WORK_NETWORKS];  // fraction of daily work interactions with social-distancing
	double child_network_adults;				// fraction of adults in the child network
	double elderly_network_adults;				// fraction of adults in the elderly network

	double mean_infectious_period;  // mean period in days that people are infectious
	double sd_infectious_period;	// sd of period in days that people are infectious
	double infectious_rate;         // mean total number of people infected for a mean person

	double relative_susceptibility[N_AGE_GROUPS]; // relative susceptibility of an age group
	double adjusted_susceptibility[N_AGE_GROUPS]; // adjusted susceptibility of an age group (normalising for interactions)

	double relative_transmission_by_type[N_INTERACTION_TYPES]; 		// relative transmission rate by the type of interactions (e.g. household/workplace/random) w/o social distance
	double relative_transmission_by_type_used[N_INTERACTION_TYPES]; // relative transmission rate by the type of interactions (e.g. household/workplace/random)

	double mean_time_to_symptoms;   // mean time from infection to symptoms
	double sd_time_to_symptoms;		// sd time from infection to symptoms

	double hospitalised_fraction[N_AGE_GROUPS];   // fraction of symptomatic patients requiring hospitalisation
	double critical_fraction[N_AGE_GROUPS];  	  // fraction of hospitalised patients who require ICU treatment
	double fatality_fraction[N_AGE_GROUPS];  	  // fraction of ICU patients who die

	double mean_time_to_hospital;   // mean time from symptoms to hospital
	double mean_time_to_critical;   // mean time from hospitalised to critical care

	double mean_time_to_recover;	// mean time to recover after hospital
	double sd_time_to_recover;  	// sd time to recover after hospital
	double mean_time_to_death;		// mean time to death after hospital
	double sd_time_to_death;		// sd time to death after hospital

	double household_size[N_HOUSEHOLD_MAX];// ONS UK number of households with 1-6 person (in thousands)
	double population_group[N_AGE_GROUPS];		// ONS stratification of population (in millions)
	double population_type[N_AGE_TYPES];		// ONS stratification of population (in millions)

	double fraction_asymptomatic[N_AGE_GROUPS]; // faction who are asymptomatic
	double asymptomatic_infectious_factor;  // relative infectiousness of asymptomatics

	double mild_fraction[N_AGE_GROUPS]; 	// faction who just have mild symptoms
	double mild_infectious_factor;  		// relative infectiousness of people with mild symptoms

	double mean_asymptomatic_to_recovery;   // mean time to recovery for asymptomatics
	double sd_asymptomatic_to_recovery;     // sd of time to recovery for asymptomatics

	int quarantined_daily_interactions; 	// number of interactions a quarantined person has
	int hospitalised_daily_interactions; 	// number of interactions a hopsitalised person has

	int quarantine_days;					// number of days of previous contacts to quarantine
	double self_quarantine_fraction;		// fraction of people who self-quarantine when show symptoms

	int trace_on_symptoms; // contract trace on symptoms
	int trace_on_positive; // contract trace on positive result

	int quarantine_length_self;				// max length of quarantine if self-quarantine on symptoms
	int quarantine_length_traced;			// max length of quarantine if contact-traced
	int quarantine_length_positive;			// max length of quarantine if receive positive test result
	double quarantine_dropout_self;			// daily dropout rate if self-quarantined
	double quarantine_dropout_traced;		// daily dropout rate if contact-traced
	double quarantine_dropout_positive;     // daily dropout rate if receive positive test result
	int quarantine_on_traced;				// immediately quarantine those who are contact traced
	int quarantine_smart_release_day;		// number of days until smart release on no contacts

	double traceable_interaction_fraction;  // the proportion of interactions which are traceable even if both users have app
	int tracing_network_depth;				// the number of layers in the interaction network to recursively trace
	int allow_clinical_diagnosis;			// allow a hospital clinical diagnosis to trigger interventions

	int quarantine_household_on_symptoms;   // quarantine other household members when someone shows symptoms
	int quarantine_household_on_positive;   // quarantine other household members when someone tests positive
	int quarantine_household_on_traced;		// quarantine other household members when someone is contact traced
	int quarantine_household_contacts_on_positive; // quarantine the contacts of other household members when someone tests positive
	int quarantine_household_contacts_on_symptoms; // quarantine the contacts of other household members when someone gets symptoms

	int test_on_symptoms;					// carry out a test on those with symptoms
	int test_on_traced;						// carry out a test on those with positive test results
	int test_insensititve_period;			// number of days until a test is sensitive (delay test of recent contacts)
	int test_result_wait;					// number of days to wait for a test result
	int test_order_wait;					// minimum number of days to wait for a test to be taken
	
	double app_users_fraction; 				// Proportion of the population that use the apps
	int app_turned_on;						// is the app turned on
	int app_turn_on_time;   				// time after which the app is usable
	double seasonal_flu_rate; 				// Rate of seasonal flu

	double lockdown_work_network_multiplier;		// during lockdown distancing this multiplier is applied to the fraction of work network connections made
	double lockdown_random_network_multiplier; 		// during lockdown distancing this multiplier is applied to the fraction of random network connections made
	double lockdown_house_interaction_multiplier;  	// during lockdown this multiplier is applied to the strengin of home connections
	int lockdown_time_on;							// lockdown turned on at this time
	int lockdown_time_off;							// lockdown turned off at this time
	int lockdown_on;								// is lockdown currently on

	int lockdown_elderly_time_on;					// lockdown elderly turned on at this time
	int lockdown_elderly_time_off;					// lockdown elderly turned off at this time
	int lockdown_elderly_on;						// is lockdown elderly currently on

	int successive_lockdown_time_on;               // successive lockdowns are turned on at this time
	int successive_lockdown_duration;              // successive lockdowns last for this duration
	int successive_lockdown_gap;                   // successive lockdowns will have this duration of gap between them
	
	int testing_symptoms_time_on;							// testing symptoms turned on at this time
	int testing_symptoms_time_off;							// testing symptoms turned off at this time

	int sys_write_individual; 		// Should an individual file be written to output?
	
	long N_REFERENCE_HOUSEHOLDS;		// Number of households in the household demographics file
    int **REFERENCE_HOUSEHOLDS;		// Array of reference households

    //hospital params
    int n_total_doctors;
    int n_total_nurses;
    int n_hospitals;
    int n_wards[N_HOSPITAL_WARD_TYPES];
    int n_ward_beds[N_HOSPITAL_WARD_TYPES];
    int n_hcw_per_ward[N_HOSPITAL_WARD_TYPES][N_WORKER_TYPES];
    int n_patient_required_interactions[N_HOSPITAL_WARD_TYPES][N_WORKER_TYPES];
    int max_hcw_daily_interactions; //TODO: should there be separate values for different types of healthcare workers?

    //TODO: Add in finer grained transition times between wards once we have more information on them.
    //TOM: Determines timing for hospital event transitions.
    double mean_time_hospital_transition; // mean time for movement between hospital locations
    double sd_time_hospital_transition; // sd for movement between hospital locations

    //TOM: Added for time dependency based on hospital location. Applied to hazard rate when transmitting the virus.
    double waiting_infectivity_modifier;
    double general_infectivity_modifier;
    double icu_infectivity_modifier;


} parameters;

/************************************************************************/
/******************************  Functions  *****************************/
/************************************************************************/

int get_param_test_on_symptoms( model* );
int get_param_test_on_traced( model* );
int get_param_quarantine_on_traced( model* );
double get_param_traceable_interaction_fraction( model* );
int get_param_tracing_network_depth( model* );
int get_param_allow_clinical_diagnosis( model* );
int get_param_quarantine_household_on_positive( model* );
int get_param_quarantine_household_on_symptoms( model* );
int get_param_quarantine_household_on_traced( model* );
int get_param_quarantine_household_contacts_on_positive( model* );
int get_param_quarantine_days( model* );
int get_param_test_order_wait( model* );
int get_param_test_result_wait( model* );
double get_param_self_quarantine_fraction( model* );
int get_param_lockdown_on( model* );
int get_param_app_turned_on( model* );
double get_param_app_users_fraction( model* );

int set_param_test_on_symptoms( model*, int );
int set_param_test_on_traced( model*, int );
int set_param_quarantine_on_traced( model*, int );
int set_param_traceable_interaction_fraction( model*, double );
int set_param_tracing_network_depth( model*, int );
int set_param_allow_clinical_diagnosis( model*, int );
int set_param_quarantine_household_on_positive( model*, int );
int set_param_quarantine_household_on_symptoms( model*, int );
int set_param_quarantine_household_on_traced( model*, int );
int set_param_quarantine_household_contacts_on_positive( model*, int );
int set_param_quarantine_days( model*, int );
int set_param_test_order_wait( model*, int );
int set_param_test_result_wait( model*, int );
int set_param_self_quarantine_fraction( model*, double );
int set_param_lockdown_on( model*, int );
int set_param_lockdown_elderly_on( model*, int );
int set_param_app_turned_on( model*, int );
int set_param_app_users_fraction( model*, double );


void check_params( parameters* );
void destroy_params( parameters* );

#endif /* PARAMS_H_ */
