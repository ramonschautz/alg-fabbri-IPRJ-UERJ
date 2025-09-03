/* R. Fabbri, 2024 */
#include "sorted_merge_3way.h"
#include <climits>

bool
sorted_merge_3way(
    const int *list_a, int na,
    const int *list_b, int nb,
    const int *list_c, int nc,
    int *list_abc)
{
 	int i = 0, j = 0, k = 0, x = 0;

	for(int u = 0; u < na -1; u++){
		if(list_a[u] > list_a[u + 1]){
			return false;
		}
	}
	for(int u = 0; u < nb -1; u++){
		if(list_b[u] > list_b[u + 1]){
			return false;
		}
	}
	for(int u = 0; u < nc -1; u++){
		if(list_c[u] > list_c[u + 1]){
			return false;
		}
	}
    	while(i < na && j < nb && k < nc){
        	if(list_a[i] <= list_b[j] && list_a[i] <= list_c[k]){
            		list_abc[x++] = list_a[i++];
        	}
		else if(list_b[j] <= list_a[i] && list_b[j] <= list_c[k]){
            		list_abc[x++] = list_b[j++];
        	} 	
		else{
            		list_abc[x++] = list_c[k++];
        	}
    	}
    	while(i < na && j < nb){
        	if(list_a[i] <= list_b[j]) {
            		list_abc[x++] = list_a[i++];
        } 	
		else{
            		list_abc[x++] = list_b[j++];
        	}
    	}
    	while(i < na && k < nc){
        	if(list_a[i] <= list_c[k]){
            		list_abc[x++] = list_a[i++];
        	}
		else{
            		list_abc[x++] = list_c[k++];
        	}
    	}
    	while(j < nb && k < nc){
        	if(list_b[j] <= list_c[k]){
            		list_abc[x++] = list_b[j++];
        	}
		else{
            		list_abc[x++] = list_c[k++];
        	}
    	}
    	while(i < na){
        	list_abc[x++] = list_a[i++];
    	}
    	while(j < nb){
        	list_abc[x++] = list_b[j++];
    	}
    	while(k < nc){
        list_abc[x++] = list_c[k++];
    	}
    return true;
}
