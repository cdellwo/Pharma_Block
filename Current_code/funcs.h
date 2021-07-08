#ifndef FUNCS_H
#define FUNCS_H
#pragma once
#include"Node.h"
#include "Quorum.h"


void form_d_p_q(); //quorum 2 -- distributer - pharmacy

void form_w_d_q(); // quorum 1 -- wharehouse - distributer

void form_man_w_q(); // quorum 0 -- manu - wharehouse

void quorum_selection_test(std::vector<std::vector<Node*>>& all_nodes, int num_entity_types, std::string &prev_block_hash);









#endif