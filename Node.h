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
	int times_selected = 0;

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


	void increment_stake_id(int max)
	{
		if (stakeholder_id_num < (max - 1))
		{
			stakeholder_id_num += 1;
		}
		else
		{
			stakeholder_id_num = 0;
		}
	}



	void set_in_quorum(bool status)
	{
		this->in_quorum = status;
		if (status)
		{
			times_selected += 1;
		}
	}

	/*std::ostream& operator<<(std::ostream& os, const Node& nd)
	{
		os << 
	}*/

};

#endif