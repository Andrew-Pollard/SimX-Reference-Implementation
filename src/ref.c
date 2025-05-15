#include "simx.h"


#include <stdlib.h>


#define REF_IMPL_NAME "SimX Reference Implementation"
#define REF_IMPL_DESCRIPTION "The reference implementation of the SimX API written in C"
#define REF_IMPL_VERSION "0.0.0"
#define REF_IMPL_AUTHOR "Andrew Pollard"


static const char* ref_error_message = NULL;
static simx_log_callback ref_log_callback = NULL;
static void* ref_log_callback_user_data = NULL;


struct SIMXentity {
	double time;
	double timestep;
	long long iteration;

	simx_log_callback ref_log_callback;
	void* ref_log_callback_user_data;
};


int simx_get_api_version_number(int* major, int* minor, int* patch) {
	if (!major || !minor || !patch)
		return SIMX_ERROR_ARGUMENT_NULL;

	*major = SIMX_API_VERSION_MAJOR;
	*minor = SIMX_API_VERSION_MINOR;
	*patch = SIMX_API_VERSION_PATCH;

	return SIMX_ERROR_NONE;
}


const char* simx_get_api_version() {
	return SIMX_API_VERSION;
}


const char* simx_get_implementation_name() {
	return REF_IMPL_NAME;
}


const char* simx_get_implementation_description() {
	return REF_IMPL_DESCRIPTION;
}


const char* simx_get_implementation_version() {
	return REF_IMPL_VERSION;
}


const char* simx_get_implementation_author() {
	return REF_IMPL_AUTHOR;
}


int simx_get_extensions(char** extensions, int* length) {
	if (!extensions || !length)
		return SIMX_ERROR_ARGUMENT_NULL;

	*extensions = NULL;
	*length = 0;

	return SIMX_ERROR_NONE;
}


const char* simx_get_error_message() {
	return ref_error_message;
}


int simx_set_log_callback(simx_log_callback callback, void* user_data) {
	ref_log_callback = callback;
	ref_log_callback_user_data = user_data;

	return SIMX_ERROR_NONE;
}


int simx_set_entity_log_callback(struct SIMXentity* entity, simx_log_callback callback, void* user_data) {
	if (!entity)
		return SIMX_ERROR_ARGUMENT_NULL;

	entity->ref_log_callback = callback;
	entity->ref_log_callback_user_data = user_data;

	return SIMX_ERROR_NONE;
}


int simx_create_entity(struct SIMXentity** entity) {
	*entity = calloc(0, sizeof(struct SIMXentity));

	if (!*entity)
		return SIMX_ERROR_INSUFFICIENT_MEMORY;

	// Initialize

	return SIMX_ERROR_NONE;
}


int simx_step_entity(struct SIMXentity* entity) {
	if (!entity)
		return SIMX_ERROR_ARGUMENT_NULL;

	// Simulate

	entity->time += entity->timestep;
	entity->iteration++;

	return SIMX_ERROR_NONE;
}


void simx_destroy_entity(struct SIMXentity* entity) {
	free(entity);
}


int simx_get_entity_time(const struct SIMXentity* entity, double* time) {
	if (!entity)
		return SIMX_ERROR_ARGUMENT_NULL;

	*time = entity->time;

	return SIMX_ERROR_NONE;
}


int simx_get_entity_timestep(const struct SIMXentity* entity, double* timestep) {
	if (!entity)
		return SIMX_ERROR_ARGUMENT_NULL;

	*timestep = entity->timestep;

	return SIMX_ERROR_NONE;
}


int simx_get_entity_iteration(const struct SIMXentity* entity, long long* iteration) {
	if (!entity)
		return SIMX_ERROR_ARGUMENT_NULL;

	*iteration = entity->iteration;

	return SIMX_ERROR_NONE;
}
