#ifndef REGEX_H
#define REGEX_H

#define EPSILON '\0'

typedef struct NFA_Transition NFA_Transition;
typedef struct NFA_TransitionListItem NFA_TransitionListItem;
typedef struct NFA_State NFA_State;

struct NFA_Transition{
	char condition;
	NFA_State *from;
	NFA_State *to;
};

struct NFA_TransitionListItem{
	NFA_Transition *transition;
	NFA_TransitionListItem *next;
};


struct NFA_State{
	NFA_TransitionListItem *transitions;
};

NFA_State *regex_generate_NFA_from_regex(char * regex);
void regex_link_NFA_states(NFA_State *A, NFA_State *B, char condition);
void regex_add_NFA_transition_to_list(NFA_State *state, NFA_TransitionListItem * transition);
NFA_State *regex_get_end_of_NFA(NFA_State *begin);
char *regex_get_group(char *begin);
NFA_State *regex_link_zero_or_more(NFA_State *cur_state, NFA_State *group_begin, NFA_State *group_end);
NFA_State *regex_link_one_or_more(NFA_State *cur_state, NFA_State *group_begin, NFA_State *group_end);
#endif
