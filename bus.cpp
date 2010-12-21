/*
 * Bus.cpp
 *
 *  Created on: Dec 21, 2010
 *      Author: crhan
 */

#include "bus.h"

int bus::print(int printNum)
{
	switch(printNum){
	case 1:
		cout<<getDepTown();
	case 2:
		cout<<getDesTown();
	case 3:
		cout<<getDepTime();
	case 4:
		cout<<getDesTime();
	}

	return 0;
}
