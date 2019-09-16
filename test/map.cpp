#include "map.h"

int _Stage[3][8][12]=
{
	{
	
		{9,9,9,9,9,9,9,9,9,9,9,9},
		{9,0,0,0,2,0,0,0,0,0,0,9},
		{9,0,1,0,0,0,0,0,0,0,0,8},
		{9,0,0,0,0,0,0,0,0,6,0,9},
		{9,0,0,7,3,4,0,0,0,0,0,9},
		{9,0,0,0,0,0,0,0,0,0,0,9},
		{9,0,0,5,0,0,0,0,0,0,0,9},
		{9,9,9,9,9,9,9,9,9,9,9,9}},
	{
		{9,9,9,9,9,9,9,9,9,9,9,9},
		{9,0,0,0,0,0,0,0,7,0,0,9},
		{9,0,1,0,0,0,0,0,0,0,0,8},
		{9,0,0,2,0,0,0,0,0,0,0,9},
		{9,0,0,0,3,5,0,0,0,0,0,9},
		{9,0,0,0,0,0,0,0,0,0,0,9},
		{9,0,0,0,0,0,0,0,6,4,0,9},
		{9,9,9,9,9,9,9,9,9,9,9,9},
	},
	{
		{9,9,9,9,9,9,9,9,9,9,9,9},
		{9,0,0,0,0,5,0,0,0,0,0,9},
		{9,0,1,0,0,0,0,0,0,0,0,8},
		{9,0,0,0,0,0,0,0,0,3,0,9},
		{9,0,0,0,0,0,6,0,0,0,0,9},
		{9,0,0,0,4,0,0,7,0,0,0,9},
		{9,0,0,0,0,2,0,0,0,0,0,9},
		{9,9,9,9,9,9,9,9,9,9,9,9}
	}	
};
void Map::LoadM(int stage){
	int i,j;
	for(i=0;i<8;i++){
		for(j=0;j<12;j++){
			MapShap[stage][i][j]=_Stage[stage][i][j];
		}
	}
}