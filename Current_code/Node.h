#ifndef NODE_H
#define NODE_H
#include "includes.h"

#pragma once

class Node
{
private:
	std::string entity_type;
	int stakeholder_id_num;
	bool in_quorum = false;
	int qourum_id;
	//int entity_type;

public:

	Node(std::string ent_type, int stake_hold_id, int group)
	{
		this->entity_type = ent_type;
		this->stakeholder_id_num = stake_hold_id;
		
	}


	int get_id_num()
	{
		return this->stakeholder_id_num;
	}

	std::string get_entity_type()
	{
		return this->entity_type;
	}

	bool get_in_quorum()
	{
		return in_quorum;
	}


	void set_in_quorum(bool status)
	{
		this->in_quorum = status;
	}

	/*std::ostream& operator<<(std::ostream& os, const Node& nd)
	{
		os << 
	}*/

};

#endif