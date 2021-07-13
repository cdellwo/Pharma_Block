#ifndef FUNCS_H
#define FUNCS_H
#pragma once
#include"Node.h"
#include "Quorum.h"


//void form_d_p_q(); //quorum 2 -- distributer - pharmacy lol these functions will never be and never should have been
//
//void form_w_d_q(); // quorum 1 -- wharehouse - distributer
//
//void form_man_w_q(); // quorum 0 -- manu - wharehouse

void quorum_selection_test(std::vector<std::vector<Node*>>& all_nodes, int times_selected [4][20], std::string &prev_block_hash, int block_num);


void increment_entity_ids(std::vector<std::vector<Node* >>& all_nodes);






#endif