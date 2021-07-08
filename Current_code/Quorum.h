#ifndef QUORUM_H
#define QUORUM_H

#pragma once
#include "Node.h"

class Quorum
{
private:
	int number_of_members =0;
	int quorum_number;
	std::vector<Node*> q_members;

public:
	Quorum(const int &quorum_number)
	{
		this->quorum_number = quorum_number;

		/*this->number_of_members = num_mems;
		this->q_members = nodes;*/
	}

	bool add_member( Node *new_member) // returns false if new member was already in quorum
	{
		if (!new_member->get_in_quorum()) 
		{
			new_member->set_in_quorum(true);
			this->q_members.push_back(new_member);
			this->number_of_members++;
			return true;
		}
		//this->number_of_members++;
		return false; //// UPDATE THIS CONNOR 7-7
	}
	
	void clear_quorum()
	{
		this->q_members.clear();
		this->number_of_members = 0;
	}

	void print_quorum()
	{
		for (int i = 0; i < number_of_members; i++)
		{
			std::cout << "Type: " << q_members[i]->get_entity_type() << " ID: " << q_members[i]->get_id_num() << std::endl;
		}
	}


};

#endif